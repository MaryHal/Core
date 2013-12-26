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
        static Bullet* fire();
        static void destroy(Bullet& b);

        static void update();
        static void draw(sf::RenderTarget& target);

    private:
        static void swap(int index1, int index2);

    private:
        static std::array<Bullet, MAX> bullets;
        static unsigned int used;
        /* std::stack<Bullet*> unused; */
};

#endif // _BulletBuffer_hpp_
