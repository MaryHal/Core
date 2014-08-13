#ifndef _BulletML_hpp_
#define _BulletML_hpp_

#include <bulletmlrunner.h>

class Mover;
class BulletMLManager;

class BulletML : public BulletMLRunner
{
    public:
        // root bullet
        BulletML(BulletMLParser* parser, Mover* bullet, Mover* target, BulletMLManager* owner);
        // child bullet
        BulletML(BulletMLState* state, Mover* bullet, Mover* target, BulletMLManager* owner);

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
        Mover* mMover;
        Mover* mTarget;

        BulletMLManager* mOwner;
};

#endif // _BulletML_hpp_
