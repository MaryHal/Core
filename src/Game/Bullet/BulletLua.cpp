#include "BulletLua.hpp"
#include "BulletManager.hpp"

#include <sol.hpp>
#include "Mover.hpp"

#include "../../Math/Math.hpp"
#include "../../Utils/Log.hpp"

BulletLua* BulletLua::current = nullptr;

BulletLua::BulletLua(Mover* bullet, Mover* target,
                     BulletManager* owner)
    : Bullet(bullet, target, owner),
      luaState(new sol::state),
      funcName("")
{
    initLua();
}

BulletLua::BulletLua(const std::string& filename,
                     Mover* bullet, Mover* target,
                     BulletManager* owner)
    : Bullet(bullet, target, owner),
      luaState(new sol::state),
      funcName("main")
{
    luaState->open_file(filename);

    initLua();
}

BulletLua::BulletLua(std::shared_ptr<sol::state> lua, const std::string& func,
                     Mover* bullet, Mover* target,
                     BulletManager* owner)
    : Bullet(bullet, target, owner),
      luaState(lua),
      funcName(func)
{
}

std::shared_ptr<sol::state> BulletLua::getLuaState()
{
    return luaState;
}

bool BulletLua::isDead()
{
    return mMover->dead;
}

void BulletLua::run()
{
    BulletLua::current = this;

    // Run lua function
    if (!funcName.empty())
        luaState->get<sol::function>(funcName).call();

    // Move everything
    mMover->tick();
}

void BulletLua::__debugRun(const std::string& code)
{
    BulletLua::current = this;
    luaState->script(code);
}

void BulletLua::initLua()
{
    // luaState->open_libraries(sol::lib::base);
    luaState->open_libraries(sol::lib::math);

    luaState->set_function("getPosX",
                           [&]()
                           {
                               return BulletLua::current->mMover->x;
                           });

    luaState->set_function("getPosY",
                           [&]()
                           {
                               return BulletLua::current->mMover->y;
                           });

    luaState->set_function("getVelX",
                           [&]()
                           {
                               BulletLua* c = BulletLua::current;
                               return c->mMover->s * sin(c->mMover->d);
                           });

    luaState->set_function("getVelY",
                           [&]()
                           {
                               BulletLua* c = BulletLua::current;
                               return c->mMover->s * cos(c->mMover->d);
                           });

    luaState->set_function("getSpeed",
                           [&]()
                           {
                               BulletLua* c = BulletLua::current;
                               return c->mMover->s;
                           });

    luaState->set_function("getDir",
                           [&]()
                           {
                               BulletLua* c = BulletLua::current;
                               return c->mMover->d;
                           });

    luaState->set_function("getTurn",
                           [&]()
                           {
                               return Bullet::turn;
                           });

    luaState->set_function("getRank",
                           [&]()
                           {
                               return Bullet::rank;
                           });

    luaState->set_function("setPos",
                           [&](double x, double y)
                           {
                               BulletLua* c = BulletLua::current;
                               c->mMover->x = x;
                               c->mMover->y = y;
                           });

    luaState->set_function("setVel",
                           [&](double vx, double vy)
                           {
                               BulletLua* c = BulletLua::current;
                               c->mMover->d = atan2(vy, vx);
                               c->mMover->s = sqrt(vx*vx+vy*vy);
                           });

    luaState->set_function("setDir",
                           [&](double dir)
                           {
                               BulletLua* c = BulletLua::current;
                               c->mMover->d = Math::degToRad(dir);
                           });

    luaState->set_function("setAimDir",
                           [&]()
                           {
                               BulletLua* c = BulletLua::current;
                               c->mMover->d = Math::PI - atan2(c->mTarget->x - c->mMover->x,
                                                               c->mTarget->y - c->mMover->y);
                           });

    luaState->set_function("setSpeed",
                           [&](double s)
                           {
                               BulletLua* c = BulletLua::current;
                               c->mMover->s = s;
                           });

    luaState->set_function("setFunction",
                           [&](const std::string& funcName)
                           {
                               BulletLua* c = BulletLua::current;
                               c->setFunctionName(funcName);
                           });

    luaState->set_function("fire",
                           [&](double x, double y, double d, double s,
                               const std::string& funcName)
                           {
                               BulletLua* c = BulletLua::current;
                               c->mOwner->createBullet(c, funcName,
                                                       x, y,
                                                       d, s,
                                                       c->mTarget);
                           });

    luaState->set_function("fire",
                           [&](double d, double s,
                               const std::string& funcName)
                           {
                               BulletLua* c = BulletLua::current;
                               c->mOwner->createBullet(c, funcName,
                                                       c->mMover->x, c->mMover->y,
                                                       d, s,
                                                       c->mTarget);
                           });

    luaState->set_function("vanish",
                           [&]()
                           {
                               BulletLua* c = BulletLua::current;
                               c->mMover->dead = true;
                           });
}

void BulletLua::setFunctionName(const std::string& funcName)
{
    this->funcName = funcName;
}
