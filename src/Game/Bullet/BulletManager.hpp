#ifndef _BulletManager_h_
#define _BuleltManager_h_

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

        void tick();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        /* void checkCollision(Ship* target, double hitDistSq); */
};

#endif // _BulletManager_h_

