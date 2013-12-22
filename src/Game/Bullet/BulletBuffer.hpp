#ifndef _BulletBuffer_hpp_
#define _BulletBuffer_hpp_

#include <array>
#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class BulletBuffer : public sf::Drawable
{
    public:
        static const int MAX = 1024;
        static sf::CircleShape sprite;

    public:
        BulletBuffer();
        ~BulletBuffer();

        void update();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void swap(int index1, int index2);

    private:
        std::array<Bullet, MAX> bullets;
        unsigned int used;
        /* std::stack<Bullet*> unused; */
};

#endif // _BulletBuffer_hpp_

