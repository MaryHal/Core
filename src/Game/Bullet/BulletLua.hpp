#ifndef _BulletLua_hpp_
#define _BulletLua_hpp_

#include "Bullet.hpp"

#include <string>
#include <memory>

namespace sol
{
    class state;
};

class BulletLua : public Bullet
{
    private:
        static BulletLua* current;

    public:
        BulletLua(Mover* bullet, Mover* target);
        BulletLua(const std::string& filename, Mover* bullet, Mover* target);
        BulletLua(std::shared_ptr<sol::state> lua, const std::string& func,
                  Mover* bullet, Mover* target);

        void tick();
        void __debugRun(const std::string& code);

    private:
        void initLua();
        void setBullet();

    public:
        std::shared_ptr<sol::state> luaState;
        std::string curFunc;
};

#endif // _BulletLua_hpp_
