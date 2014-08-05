#include "BulletCommand.hpp"
#include "Mover.hpp"
#include "BulletManager.hpp"

#include <cmath>

double dtor(double x) { return x*M_PI/180; }
double rtod(double x) { return x*180/M_PI; }

BulletCommand::BulletCommand(BulletMLParser* parser, Mover* bullet, Mover* target, BulletManager* owner)
    : BulletMLRunner(parser)
    , Bullet(bullet, target, owner)
{}

BulletCommand::BulletCommand(BulletMLState* state, Mover* bullet, Mover* target, BulletManager* owner)
    : BulletMLRunner(state)
    , Bullet(bullet, target, owner)
{}

double BulletCommand::getBulletDirection()
{
    return mMover->d;
}

double BulletCommand::getAimDirection()
{
    return rtod(M_PI-atan2(mTarget->x - mMover->x, mTarget->y - mMover->y));
}

double BulletCommand::getBulletSpeed()
{
    return mMover->s;
}

double BulletCommand::getDefaultSpeed()
{
    return 1.0;
}

void BulletCommand::createSimpleBullet(double direction, double speed)
{
    mOwner->createProjectile(mMover->x, mMover->y, dtor(direction), speed);
}

void BulletCommand::createBullet(BulletMLState* state, double direction, double speed)
{
    mOwner->createBullet(state, mMover->x, mMover->y, dtor(direction), speed, mTarget);
}

void BulletCommand::doVanish()
{
    mMover->dead = true;
}

void BulletCommand::doChangeDirection(double direction)
{
    mMover->d = dtor(direction);
}

void BulletCommand::doChangeSpeed(double speed)
{
    mMover->s = speed;
}

void BulletCommand::doAccelX(double speedx)
{
    double sx = getBulletSpeedX();
    double sy = getBulletSpeedY();
    sx = speedx;
    mMover->d = atan2(sy, sx);
    mMover->s = sqrt(sx*sx+sy*sy);
}

void BulletCommand::doAccelY(double speedy)
{
    double sx = getBulletSpeedX();
    double sy = getBulletSpeedY();
    sy = speedy;
    mMover->d = atan2(sy, sx);
    mMover->s = sqrt(sx*sx+sy*sy);
}

double BulletCommand::getBulletSpeedX()
{
    return mMover->s * sin(mMover->d);
}

double BulletCommand::getBulletSpeedY()
{
    return -mMover->s * cos(mMover->d);
}

int BulletCommand::getTurn()
{
    return Bullet::turn;
}

double BulletCommand::getRank()
{
    return Bullet::rank;
}

bool BulletCommand::isDead()
{
    return mMover->dead || isEnd();
}
