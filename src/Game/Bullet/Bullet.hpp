#ifndef _Bullet_hpp_
#define _Bullet_hpp_

#include <SFML/System/Vector2.hpp>
#include <queue>
#include <functional>

class Bullet
{
    public:
        typedef std::function<void(Bullet*)> StepFunc;

    public:
        Bullet();
        ~Bullet();

        void initialize(sf::Vector2f position,
                        float speed, float angle,
                        std::queue<StepFunc> stepFunctions);

        // Methods to interface with bullets from step functions
        void setCircle(float speed, int life);
        void setAcceleration(float speed, int life);
        const int getAccelLife() const;

        void setAngle(float newAngle);
        void setSpeed(float newSpeed);
        void setSpeedAndAngle(float newSpeed, float newAngle);

        const int getLife() const;
        void setLife(int newLife);
        void decreaseLife();

        const int getWait() const;
        void setWait(int newWait);

        void stop();
        void clear();

        const sf::Vector2f& getPosition() const;

        // Update bullet (move and perform step functions)
        void update();

        void setIndex(int i);
        const int getIndex() const;

    protected:
        void move();
        void step();

    private:
        sf::Vector2f position;

        // Uniform Motion
        float angle;
        float speed;

        // Circular motion
        float circleSpeed;
        int circleLife;

        // Accelerated Motion
        float accelSpeed;
        int accelLife;

        int life;

        int wait;
        std::queue<StepFunc> stepFunctionQueue;

        unsigned int index;
};

#endif // _Bullet_hpp_

