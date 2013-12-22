#include "BulletBuffer.hpp"

sf::CircleShape BulletBuffer::sprite(2);
std::array<Bullet, BulletBuffer::MAX> BulletBuffer::bullets = {};
unsigned int BulletBuffer::used = 0;

void BulletBuffer::update()
{
    for (unsigned int i = 0; i < used; ++i)
    {
        bullets[i].update();
    }
}

void BulletBuffer::draw(sf::RenderTarget& target, sf::RenderStates states)
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
    bullets[index1] = bullets[index2];
    bullets[index2] = temp;
}
