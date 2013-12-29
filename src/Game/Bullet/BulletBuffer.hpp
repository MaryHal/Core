#ifndef _BulletBuffer_hpp_
#define _BulletBuffer_hpp_

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include <array>
#include <stack>

class BulletBuffer
{
    public:
        static const std::queue<Bullet::StepFunc> nullList;
        static const int MAX = 1024;
        static sf::CircleShape sprite;

    public:
        static void initialize();
        static Bullet* makeNewBullet();
        static void destroy(Bullet* b);

        static void update();
        static void draw(sf::RenderTarget& target);

    private:
        static void swap(int index1, int index2);

    private:
        static std::array<Bullet, MAX> bullets;
        static std::stack<Bullet*> unused;
        /* static unsigned int used; */
};

#endif // _BulletBuffer_hpp_
