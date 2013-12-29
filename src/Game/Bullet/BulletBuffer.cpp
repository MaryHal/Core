#include "BulletBuffer.hpp"
#include "../../Utils/Log.hpp"

const std::queue<Bullet::StepFunc> BulletBuffer::nullList;
sf::CircleShape BulletBuffer::sprite(2);

std::array<Bullet, BulletBuffer::MAX> BulletBuffer::bullets = {};
std::stack<Bullet*> BulletBuffer::unused;

void BulletBuffer::initialize()
{
    for (unsigned int i = BulletBuffer::MAX - 1; i > 0; --i)
    {
        bullets[i].initialize(sf::Vector2f(0.0f, 0.0f), 0.0f, 0.0f, nullptr);
        unused.push(&bullets[i]);
    }
}

Bullet* BulletBuffer::makeNewBullet()
{
    Bullet* b = unused.top();
    b->active = true;
    unused.pop();

    return b;
}

void BulletBuffer::destroy(Bullet* b)
{
    b->active = false;
    unused.push(b);
}

void BulletBuffer::update()
{
    Console::logf("%d", BulletBuffer::MAX - unused.size());
    for (unsigned int i = 0; i < BulletBuffer::MAX; ++i)
    {
        if (!bullets[i].active)
            return;

        bullets[i].move();
        sf::Vector2f pos = bullets[i].getPosition();

        bool xValid = (pos.x < 640.0f);
        bool yValid = (pos.y < 480.0f);

        if ((xValid & yValid) == 0) 
        {
            BulletBuffer::destroy(&bullets[i]);
        }

        bullets[i].step();
    }
}

void BulletBuffer::draw(sf::RenderTarget& target)
{
    for (unsigned int i = 0; i < BulletBuffer::MAX; ++i)
    {
        if (!bullets[i].active)
            return;

        BulletBuffer::sprite.setPosition(bullets[i].getPosition());
        BulletBuffer::sprite.setFillColor(sf::Color(255, 255, 255, 255));
        target.draw(BulletBuffer::sprite);
    }
}

void BulletBuffer::swap(int index1, int index2)
{
    Bullet temp = bullets[index1];
    bullets[index1] = bullets[index2];
    bullets[index2] = temp;
}

