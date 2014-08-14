#ifndef _BulletLuaManager_hpp_
#define _BulletLuaManager_hpp_

#include "BulletLua.hpp"
#include "BulletManager.hpp"
#include "SpacialPartition.hpp"

#include <vector>
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
        void createBullet(const std::string& filename, Bullet* origin, Bullet* target);

        // Child Bullets
        void createBullet(std::shared_ptr<sol::state> lua, const std::string& func, Bullet* origin, Bullet* target);
        void createBullet(std::shared_ptr<sol::state> lua, const std::string& func,
                          double x, double y, double d, double s, Bullet* target);

        virtual void tick();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual bool checkCollision(Bullet& b);

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

        std::list<BulletLua*> blocks;

        sf::VertexArray vertices;
        unsigned int vertexCount;

        SpacialPartition collision;
};

#endif /* _BulletLuaManager_hpp_ */

