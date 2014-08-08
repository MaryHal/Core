#ifndef _BulletMLManager_hpp_
#define _BulletMLManager_hpp_

#include "BulletManager.hpp"
#include "Mover.hpp"

#include <list>

class BulletMLState;
class BulletMLParser;
class BulletCommand;

class BulletMLManager : public BulletManager
{
    public:
        BulletMLManager();
        std::vector<BulletCommand*> mCommands;
        std::vector<Shot*> mShots;
        std::vector<Shot*> mPool;

        BulletCommand* createBullet(BulletMLState* state, double x, double y, double d, double s, Mover* target);
        BulletCommand* createBullet(BulletMLParser* parser, Mover* origin, Mover* target);
        Shot* createProjectile(double x, double y,double d, double s);
        void destroyProjectile(Shot* projectile);
        void clearAll();

        virtual void tick();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        /* void checkCollision(); */
};

#endif // _BulletMLManager_hpp_
