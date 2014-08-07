#ifndef _BulletManager_hpp_
#define _BulletManager_hpp_

#include <memory>
#include <list>
#include "Mover.hpp"

#include <SFML/Graphics.hpp>

class BulletMLState;
class BulletMLParser;
class BulletCommand;

// class BulletLua;

class BulletManager : public sf::Drawable, public sf::Transformable
{
    public:
        BulletManager();
        // std::vector<BulletLua*> mLuaCommands;
        std::vector<BulletCommand*> mCommands;
        std::vector<Shot*> mShots;
        std::vector<Shot*> mPool;

        // BulletLua* createBullet(const std::string& luaFile, Mover* origin, Mover* target);
        // BulletLua* createBullet(BulletLua* bullet, const std::string& func, double x, double y, double d, double s, Mover* target);

        BulletCommand* createBullet(BulletMLState* state, double x, double y, double d, double s, Mover* target);
        BulletCommand* createBullet(BulletMLParser* parser, Mover* origin, Mover* target);
        Shot* createProjectile(double x, double y,double d, double s);
        void destroyProjectile(Shot* projectile);
        void clearAll();

        void tick();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        /* void checkCollision(); */
};

#endif // _BulletManager_hpp_


