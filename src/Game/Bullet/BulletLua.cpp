#include "BulletLua.hpp"

#include <sol.hpp>
#include "Mover.hpp"

#include "../../Utils/Log.hpp"

BulletLua::BulletLua(Mover* bullet, Mover* target)
    : Bullet(bullet, target),
      luaState(new sol::state),
      curFunc("main")
{
    luaState->open_libraries(sol::lib::base);
    luaState->open_libraries(sol::lib::math);

    luaState->set_function("setPos",
                           [&, this](double x, double y)
                           {
                               mMover->x = x;
                               mMover->y = y;
                           });

    luaState->set_function("setVel",
                           [&, this](double vx, double vy)
                           {
                           mMover->d = atan2(vy, vx);
                           mMover->s = sqrt(vx*vx+vy*vy);
                           });
}

BulletLua::BulletLua(const std::string& filename, Mover* bullet, Mover* target)
    : Bullet(bullet, target),
      luaState(new sol::state),
      curFunc("main")
{
    luaState->open_libraries(sol::lib::base);
    luaState->open_libraries(sol::lib::math);

    luaState->open_file(filename);
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
    mMover->tick();
}

void BulletLua::__debugRun(const std::string& code)
{
    luaState->script(code);
}

void BulletLua::setPos(double x, double y)
{
    mMover->x = x;
    mMover->y = y;
}

void BulletLua::setVel(double vx, double vy)
{
    mMover->d = atan2(vy, vx);
    mMover->s = sqrt(vx*vx+vy*vy);
}

void BulletLua::vanish()
{
    mMover->dead = true;
}
