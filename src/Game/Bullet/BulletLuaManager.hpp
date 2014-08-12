#ifndef _BulletLuaManager_hpp_
#define _BulletLuaManager_hpp_

#include "BulletManager.hpp"
#include "BulletLua.hpp"

#include <vector>
#include <stack>
#include <string>

// #include <memory>

class BulletLuaManager : public BulletManager
{
    public:
        static float rank;

    public:
        BulletLuaManager(unsigned int initialCapacity=4096);

        // Root Bullet
        void createBullet(const std::string& filename, Mover* origin, Mover* target);

        // Child Bullets
        void createBullet(std::shared_ptr<sol::state> lua, const std::string& func, Mover* origin, Mover* target);
        void createBullet(std::shared_ptr<sol::state> lua, const std::string& func,
                          double x, double y, double d, double s, Mover* target);

        virtual void tick();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void printSizes();

        void pushToStack(BulletLua* b);

    private:
        BulletLua* getFreeBullet();

    private:
        std::vector<BulletLua> bullets;
        std::stack<BulletLua*> freeBullets;
};

#endif /* _BulletLuaManager_hpp_ */
