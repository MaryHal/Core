#ifndef _BulletMLManager_hpp_
#define _BulletMLManager_hpp_

#include "Mover.hpp"

#include <SFML/Graphics.hpp>
#include <list>

class BulletMLState;
class BulletMLParser;

class BulletML;

class BulletMLManager : public sf::Drawable, public sf::Transformable
{
    public:
        static int turn;
        static float rank;

    public:
        BulletMLManager();
        std::vector<BulletML*> mCommands;
        std::vector<Shot*> mShots;
        std::vector<Shot*> mPool;

        BulletML* createBullet(BulletMLState* state, double x, double y, double d, double s, Mover* target);
        BulletML* createBullet(BulletMLParser* parser, Mover* origin, Mover* target);
        Shot* createProjectile(double x, double y,double d, double s);
        void destroyProjectile(Shot* projectile);
        void clearAll();

        virtual void tick();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        /* void checkCollision(); */
};

#endif // _BulletMLManager_hpp_
