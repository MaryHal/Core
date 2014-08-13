#ifndef _BulletLua_hpp_
#define _BulletLua_hpp_

#include <string>
#include <memory>

#include "Mover.hpp"

class BulletLuaManager;

namespace sol
{
    class state;
};

class BulletLua
{
    private:
        static BulletLua* current;

    public:
        struct Bullet
        {
            public:
                float x, y;
                float vx, vy;
                bool dead;
        };

    public:
        BulletLua();

        void set(const std::string& filename,
                 Mover* origin, Mover* target,
                 BulletLuaManager* owner);

        void set(std::shared_ptr<sol::state> lua,
                 const std::string& func,
                 Mover* origin, Mover* target,
                 BulletLuaManager* owner);

        void set(std::shared_ptr<sol::state> lua,
                 const std::string& func,
                 double x, double y, double d, double s,
                 Mover* target,
                 BulletLuaManager* owner);

        std::shared_ptr<sol::state> getLuaState();
        int getTurn() const;
        bool isDead() const;

        void run();
        const Mover& getMover() const;

        void __debugRun(const std::string& code);

    private:
        void initLua();
        void setFunctionName(const std::string& funcName);

    private:
        Mover mMover;
        Mover mTarget;

        std::shared_ptr<sol::state> luaState;
        std::string funcName;

        int turn;

        BulletLuaManager* mOwner;
};

#endif // _BulletLua_hpp_
