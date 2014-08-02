#include "BulletLua.hpp"

#include <sol.hpp>
#include "Mover.hpp"

#include "../../Math/Math.hpp"
#include "../../Utils/Log.hpp"

BulletLua* BulletLua::current = nullptr;

BulletLua::BulletLua(Mover* bullet, Mover* target)
    : Bullet(bullet, target),
      luaState(new sol::state),
      curFunc("main")
{
    initLua();
}

BulletLua::BulletLua(const std::string& filename, Mover* bullet, Mover* target)
    : Bullet(bullet, target),
      luaState(new sol::state),
      curFunc("main")
{
    luaState->open_file(filename);

    initLua();
}

BulletLua::BulletLua(std::shared_ptr<sol::state> lua, const std::string& func,
                     Mover* bullet, Mover* target)
    : Bullet(bullet, target),
      luaState(lua),
      curFunc(func)
{
}

void BulletLua::tick()
{
    BulletLua::current = this;
    mMover->tick();
}

void BulletLua::__debugRun(const std::string& code)
{
    BulletLua::current = this;
    luaState->script(code);
}

void BulletLua::initLua()
{
    luaState->open_libraries(sol::lib::base);
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

    luaState->set_function("vanish",
                           [&]()
                           {
                               BulletLua* c = BulletLua::current;
                               c->mMover->dead = true;
                           });
}
