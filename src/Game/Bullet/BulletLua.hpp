#ifndef _BulletLua_hpp_
#define _BulletLua_hpp_

#include <string>
#include <memory>

#include "Bullet.hpp"

class BulletManager;

namespace sol
{
    class state;
};

class BulletLua
{
    private:
        static BulletLua* current;

    public:
        BulletLua();

        void set(const std::string& filename,
                 Bullet* origin, Bullet* target,
                 BulletManager* owner);

        void set(std::shared_ptr<sol::state> lua,
                 const std::string& func,
                 Bullet* origin, Bullet* target,
                 BulletManager* owner);

        void set(std::shared_ptr<sol::state> lua,
                 const std::string& func,
                 double x, double y, double d, double s,
                 Bullet* target,
                 BulletManager* owner);

        std::shared_ptr<sol::state> getLuaState();
        int getTurn() const;
        bool isDead() const;

        void run();
        const Bullet& getMover() const;

        void __debugRun(const std::string& code);

    private:
        void initLua();
        void setFunctionName(const std::string& funcName);

    private:
        Bullet mMover;
        Bullet* mTarget;

        std::shared_ptr<sol::state> luaState;
        std::string funcName;

        int turn;

        BulletManager* mOwner;
};

#endif // _BulletLua_hpp_

