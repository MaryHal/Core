#ifndef _BulletLuaManager_hpp_
#define _BulletLuaManager_hpp_

#include "BulletManager.hpp"
#include "BulletLua.hpp"

#include <list>
#include <stack>
#include <string>

// #include <memory>

class BulletLuaManager : public BulletManager
{
    public:
        static float rank;
        static constexpr unsigned int BLOCK_SIZE = 1024;

    public:
        BulletLuaManager(unsigned int initialCapacity=1024);
        ~BulletLuaManager();

        // Root Bullet
        void createBullet(const std::string& filename, Mover* origin, Mover* target);

        // Child Bullets
        void createBullet(std::shared_ptr<sol::state> lua, const std::string& func, Mover* origin, Mover* target);
        void createBullet(std::shared_ptr<sol::state> lua, const std::string& func,
                          double x, double y, double d, double s, Mover* target);

        virtual void tick();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        unsigned int bulletCount() const;
        unsigned int freeCount() const;
        unsigned int blockCount() const;

    private:
        BulletLua* getFreeBullet();

        // Allocate a block of BLOCK_SIZE Bullets and add it to freeBullets
        void increaseCapacity(unsigned int blockSize=BLOCK_SIZE);

    private:
        std::list<BulletLua*> bullets;
        std::stack<BulletLua*> freeBullets;

        std::vector<BulletLua*> blocks;
};

#endif /* _BulletLuaManager_hpp_ */
