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
        Bullet(Mover* bullet, Mover* target);

    public:
        Mover* mMover;
        Mover* mTarget;
};

#endif // _Bullet_hpp_
