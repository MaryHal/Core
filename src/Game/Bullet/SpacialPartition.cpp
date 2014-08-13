#include "SpacialPartition.hpp"

#include <cstring>

SpacialPartition::SpacialPartition()
{
    /* std::memset(space, 0, sizeof(BulletCommand*) * 7 * 5 * 100); */
    // std::memset(bulletCount, 0, sizeof(int) * 7 * 5);
}

void SpacialPartition::addBullet()
{
    // int x = bullet.getMover().x / tileSize;
    // int y = bullet.getMover().y / tileSize;

    // space[x][y][bulletCount[x][y]] = &bullet;
    // bulletCount[x][y]++;
}

void SpacialPartition::reset()
{
    // std::memset(bulletCount, 0, sizeof(int) * 7 * 5);
}
