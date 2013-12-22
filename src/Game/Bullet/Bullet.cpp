#include "Bullet.hpp"
#include <cmath>

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::initialize(sf::Vector2f position,
                        float speed, float angle,
                        std::queue<StepFunc> stepFunctions)
{
    this->position = position;
    this->speed = speed;
    this->angle = angle;

    circleSpeed = 0;
    circleLife = 0;

    accelSpeed = 0;
    accelLife = 0;

    life = 0;
    wait = 0;
    this->stepFunctionQueue = stepFunctions;
}

void Bullet::setCircle(float speed, int life)
{
    circleSpeed = speed;
    circleLife = life;
}

void Bullet::setAcceleration(float speed, int life)
{
    accelSpeed = speed;
    accelLife = life;
}

const int Bullet::getAccelLife() const
{
    return accelLife;
}

void Bullet::setAngle(float newAngle)
{
    angle = newAngle;
}

void Bullet::setSpeed(float newSpeed)
{
    speed = newSpeed;
}

void Bullet::setSpeedAndAngle(float newSpeed, float newAngle)
{
    speed = newSpeed;
    angle = newAngle;
}

const int Bullet::getLife() const
{
    return life;
}

void Bullet::setLife(int newLife)
{
    life = newLife;
}

void Bullet::decreaseLife()
{
    life -= (life > 0);
}

const int Bullet::getWait() const
{
    return wait;
}

void Bullet::setWait(int newWait)
{
    wait = newWait;
}

void Bullet::stop()
{
    speed = 0;
    circleSpeed = 0;
    circleLife = 0;
    accelSpeed = 0;
    accelLife = 0;
}

void Bullet::update()
{
    move();
    step();
}

void Bullet::move()
{
    // TODO: Cache speed * std::sin/code(angle) so we don't have to calculate it every time.
    // (Only if we aren't chaning speed/angle of course)
    position.x += speed * std::cos(angle);
    position.y += speed * std::sin(angle);

    if (circleLife > 0)
    {
        angle += circleSpeed;
        --circleLife;
    }

    if (accelLife > 0)
    {
        speed += accelSpeed;
        --accelSpeed;
    }
}

void Bullet::step()
{
    wait -= (wait > 0);
    while (wait == 0 && !stepFunctionQueue.empty())
    {
        stepFunctionQueue.front()(this);
        stepFunctionQueue.pop();
    }
}

const sf::Vector2f& Bullet::getPosition() const
{
    return position;
}

