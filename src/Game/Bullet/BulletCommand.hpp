#ifndef _BulletCommand_hpp_
#define _BulletCommand_hpp_

#include <bulletmlrunner.h>
#include "Bullet.hpp"

class Mover;
class BulletManager;

class BulletCommand : public BulletMLRunner, Bullet
{
    public:
        // root bullet
        BulletCommand(BulletMLParser* parser, Mover* bullet, Mover* target, BulletManager* owner);
        // child bullet
        BulletCommand(BulletMLState* state, Mover* bullet, Mover* target, BulletManager* owner);

        virtual double getBulletDirection();
        virtual double getAimDirection();
        virtual double getBulletSpeed();
        virtual double getDefaultSpeed();
        virtual void createSimpleBullet(double direction, double speed);
        virtual void createBullet(BulletMLState* state, double direction, double speed);
        virtual void doVanish();
        virtual void doChangeDirection(double direction);
        virtual void doChangeSpeed(double speed);
        virtual void doAccelX(double speedx);
        virtual void doAccelY(double speedy);
        virtual double getBulletSpeedX();
        virtual double getBulletSpeedY();

        virtual int getTurn();
        virtual double getRank();

        bool isDead();

        // If you want to customize random generator
        //virtual double getRand();

    private:
        // BulletManager* mOwner;
};

#endif // _BulletCommand_hpp_
