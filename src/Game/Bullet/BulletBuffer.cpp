#include "BulletBuffer.hpp"
#include "../../Utils/Log.hpp"

sf::CircleShape BulletBuffer::sprite(2);
std::array<Bullet, BulletBuffer::MAX> BulletBuffer::bullets = {};
unsigned int BulletBuffer::used = 0;

void BulletBuffer::initialize()
{
    bullets = {};
    used = 0;
}

Bullet* BulletBuffer::fire()
{
    Bullet& b = bullets[used];
    b.setIndex(used);
    used++;

    return &b;
}

void BulletBuffer::destroy(Bullet& b)
{
    b.clear();
    swap(used, b.getIndex());
    --used;
}

void BulletBuffer::update()
{
    for (unsigned int i = 0; i < used; ++i)
    {
        bullets[i].update();
        sf::Vector2f pos = bullets[i].getPosition();

        bool xValid = (pos.x < 640.0f);
        bool yValid = (pos.y < 480.0f);

        if ((xValid & yValid) == 0) 
        {
            BulletBuffer::destroy(bullets[i]);
        }
    }
}

void BulletBuffer::draw(sf::RenderTarget& target)
{
    for (unsigned int i = 0; i < used; ++i)
    {
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

