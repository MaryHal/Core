#include "BulletBuffer.hpp"
#include "Bullet.hpp"

sf::CircleShape BulletBuffer::sprite(2);

BulletBuffer::BulletBuffer()
    : bullets(), used(0)
{
}

BulletBuffer::~BulletBuffer()
{
}

void BulletBuffer::update()
{
    for (unsigned int i = 0; i < used; ++i)
    {
        bullets[i].update();
    }
}

void BulletBuffer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (unsigned int i = 0; i < used; ++i)
    {
        BulletBuffer::sprite.setPosition(bullets[i].getPosition());
        target.draw(BulletBuffer::sprite);
    }
}

void BulletBuffer::swap(int index1, int index2)
{
    Bullet temp = bullets[index1];
    bullets[index1] = index2;
    bullets[index2] = temp;
}

