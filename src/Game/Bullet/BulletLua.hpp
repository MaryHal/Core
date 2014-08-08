#ifndef _BulletLua_hpp_
#define _BulletLua_hpp_

#include "Bullet.hpp"

#include <string>
#include <memory>

class BulletLuaManager;

namespace sol
{
    class state;
};

class BulletLua : public Bullet
{
    private:
        static BulletLua* current;

    public:
        BulletLua(Mover* bullet, Mover* target,
                  BulletLuaManager* owner);
        BulletLua(const std::string& filename,
                  Mover* bullet, Mover* target,
                  BulletLuaManager* owner);
        BulletLua(std::shared_ptr<sol::state> lua, const std::string& func,
                  Mover* bullet, Mover* target,
                  BulletLuaManager* owner);

        std::shared_ptr<sol::state> getLuaState();
        bool isDead();
        void run();
        void __debugRun(const std::string& code);

    private:
        void initLua();
        void setFunctionName(const std::string& funcName);

    private:
        std::shared_ptr<sol::state> luaState;
        std::string funcName;
        BulletLuaManager* mOwner;
};

#endif // _BulletLua_hpp_
