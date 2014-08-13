#include "BulletML.hpp"

#include "Mover.hpp"
#include "BulletMLManager.hpp"

#include <cmath>

double dtor(double x) { return x*M_PI/180; }
double rtod(double x) { return x*180/M_PI; }

BulletML::BulletML(BulletMLParser* parser, Mover* bullet, Mover* target, BulletMLManager* owner)
    : BulletMLRunner(parser)
    , mMover(bullet), mTarget(target), mOwner(owner)
{}

BulletML::BulletML(BulletMLState* state, Mover* bullet, Mover* target, BulletMLManager* owner)
    : BulletMLRunner(state)
    , mMover(bullet), mTarget(target), mOwner(owner)
{}

double BulletML::getBulletDirection()
{
    return mMover->d;
}

double BulletML::getAimDirection()
{
    return rtod(M_PI-atan2(mTarget->x - mMover->x, mTarget->y - mMover->y));
}

double BulletML::getBulletSpeed()
{
    return mMover->s;
}

double BulletML::getDefaultSpeed()
{
    return 1.0;
}

void BulletML::createSimpleBullet(double direction, double speed)
{
    mOwner->createProjectile(mMover->x, mMover->y, dtor(direction), speed);
}

void BulletML::createBullet(BulletMLState* state, double direction, double speed)
{
    mOwner->createBullet(state, mMover->x, mMover->y, dtor(direction), speed, mTarget);
}

void BulletML::doVanish()
{
    mMover->dead = true;
}

void BulletML::doChangeDirection(double direction)
{
    mMover->d = dtor(direction);
}

void BulletML::doChangeSpeed(double speed)
{
    mMover->s = speed;
}

void BulletML::doAccelX(double speedx)
{
    double sx = getBulletSpeedX();
    double sy = getBulletSpeedY();
    sx = speedx;
    mMover->d = atan2(sy, sx);
    mMover->s = sqrt(sx*sx+sy*sy);
}

void BulletML::doAccelY(double speedy)
{
    double sx = getBulletSpeedX();
    double sy = getBulletSpeedY();
    sy = speedy;
    mMover->d = atan2(sy, sx);
    mMover->s = sqrt(sx*sx+sy*sy);
}

double BulletML::getBulletSpeedX()
{
    return mMover->s * sin(mMover->d);
}

double BulletML::getBulletSpeedY()
{
    return -mMover->s * cos(mMover->d);
}

int BulletML::getTurn()
{
    return BulletMLManager::turn;
}

double BulletML::getRank()
{
    return BulletMLManager::rank;
}

bool BulletML::isDead()
{
    return mMover->dead || isEnd();
}
