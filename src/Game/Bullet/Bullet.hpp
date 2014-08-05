#ifndef _Bullet_hpp_
#define _Bullet_hpp_

class Mover;
class BulletManager;

class Bullet
{
    public:
        static int turn;
        static double rank;

    public:
        Bullet(Mover* bullet, Mover* target, BulletManager* owner);

    public:
        Mover* mMover;
        Mover* mTarget;
        BulletManager* mOwner;
};

#endif // _Bullet_hpp_
