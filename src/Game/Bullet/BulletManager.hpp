#ifndef _BulletManager_hpp_
#define _BulletManager_hpp_

#include "Mover.hpp"

#include <SFML/Graphics.hpp>

class BulletMLState;
class BulletMLParser;
class BulletCommand;

class BulletManager : public sf::Drawable, public sf::Transformable
{
    public:
        BulletManager();
        std::vector<BulletCommand*> mCommands;
        std::vector<Shot*> mShots;
        std::vector<Shot*> mPool;

        BulletCommand* createBullet(BulletMLState* state, double x, double y, double d, double s, Mover* target);
        BulletCommand* createBullet(BulletMLParser* parser, Mover* origin, Mover* target);
        Shot* createProjectile(double x, double y,double d, double s);
        void destroyProjectile(Shot* projectile);
        void clearAll();

        void tick();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        /* void checkCollision(Ship* target, double hitDistSq); */
};

#endif // _BulletManager_hpp_

