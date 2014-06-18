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
                        const StepFunc* stepFunctions)
{
    this->position = position;
    this->speed = speed;
    this->angle = angle;

    lastSpeed = speed;
    lastAngle = angle;

    circleSpeed = 0;
    circleLife = 0;

    accelSpeed = 0;
    accelLife = 0;

    life = 0;
    wait = 0;
    this->stepFunctionList = stepFunctions;
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

int Bullet::getAccelLife()
{
    return accelLife;
}

void Bullet::setAngle(float newAngle)
{
    angle = newAngle;
}

float Bullet::getAngle()
{
    return angle;
}

void Bullet::setSpeed(float newSpeed)
{
    speed = newSpeed;
}

float Bullet::getSpeed()
{
    return speed;
}

void Bullet::setSpeedAndAngle(float newSpeed, float newAngle)
{
    speed = newSpeed;
    angle = newAngle;
}

int Bullet::getLife()
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

int Bullet::getWait()
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

void Bullet::clear()
{
    stop();

    // Clear step function list
    // std::queue<StepFunc>().swap(stepFunctionQueue);
    stepFunctionList = nullptr;
}

const sf::Vector2f& Bullet::getPosition() const
{
    return position;
}

void Bullet::move()
{
    // TODO: Cache (speed * std::sin/code(angle)) so we don't have to calculate it every time.
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
    while (wait == 0 && stepFunctionList != nullptr)
    {
        (*stepFunctionList)(this);
        ++stepFunctionList;
    }
}

