#ifndef _Bullet_hpp_
#define _Bullet_hpp_

#include <SFML/Graphics.hpp>

struct Bullet
{
    public:
        float x, y;
        float vx, vy;
        bool dead;

        sf::RectangleShape sprite;

        Bullet(float x, float y, float vx, float vy);

        void setSpeedAndDirection(float speed, float dir);

        void setSpeed(float speed);
        void setSpeedRelative(float speed);
        float getSpeed();

        void setDirection(float dir);
        void setDirectionRelative(float dir);
        void setDirectionAim(float tx, float ty);
        float getDirection();
};

#endif // _Bullet_hpp_

