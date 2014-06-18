#ifndef _Bullet_hpp_
#define _Bullet_hpp_

#include <SFML/System/Vector2.hpp>
#include <queue>
#include <functional>

class Bullet
{
    public:
        static constexpr float DEFAULT_ANGLE = 180.0f;
        typedef std::function<void(Bullet*)> StepFunc;

    public:
        Bullet();
        ~Bullet();

        void initialize(sf::Vector2f position,
                        float speed, float angle,
                        const StepFunc* stepFunctions);

        // Methods to interface with bullets from step functions
        void setCircle(float speed, int life);
        void setAcceleration(float speed, int life);
        int getAccelLife();

        void setAngle(float newAngle);
        float getAngle();
        void setSpeed(float newSpeed);
        float getSpeed();
        void setSpeedAndAngle(float newSpeed, float newAngle);

        int getLife();
        void setLife(int newLife);
        void decreaseLife();

        int getWait();
        void setWait(int newWait);

        void stop();
        void clear();

        const sf::Vector2f& getPosition() const;

        void move();
        void step();

        unsigned int index;
        bool active;
        float lastAngle;
        float lastSpeed;

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
        const StepFunc* stepFunctionList; 
};

#endif // _Bullet_hpp_

