#include "Bullet.hpp"

int Bullet::turn = 0;
double Bullet::rank = 0.8;

Bullet::Bullet(Mover* bullet, Mover* target, BulletManager* owner)
    : mMover(bullet), mTarget(target), mOwner(owner)
{
}

