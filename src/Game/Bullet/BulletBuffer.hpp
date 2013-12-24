#ifndef _BulletBuffer_hpp_
#define _BulletBuffer_hpp_

#include <array>
#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class BulletBuffer
{
    public:
        static const int MAX = 1024;
        static sf::CircleShape sprite;

    public:
        static void initialize();
        static void fire();
        static void destroy();

        static void update();

    private:
        static void draw(sf::RenderTarget& target, sf::RenderStates states);
        static void swap(int index1, int index2);

    private:
        static std::array<Bullet, MAX> bullets;
        static unsigned int used;
        /* std::stack<Bullet*> unused; */
};

#endif // _BulletBuffer_hpp_
