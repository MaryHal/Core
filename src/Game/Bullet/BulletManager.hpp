#ifndef _BulletManager_hpp_
#define _BulletManager_hpp_

#include <memory>
#include <list>
#include "Mover.hpp"

#include <SFML/Graphics.hpp>

class BulletManager : public sf::Drawable, public sf::Transformable
{
    public:
        BulletManager() {}
        virtual ~BulletManager() {}

        virtual void tick() = 0;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
        /* void checkCollision(); */
};

#endif // _BulletManager_hpp_


