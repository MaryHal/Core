#ifndef _SpacialPartition_hpp_
#define _SpacialPartition_hpp_

#include "BulletCommand.hpp"

class SpacialPartition
{
    public:
        SpacialPartition();

        void addBullet(const BulletCommand& bullet);
        void reset();

    private:
        static const unsigned int tileSize = 100;

        const BulletCommand* space[7][5][100];
        int bulletCount[7][5];
};

#endif // _SpacialPartition_hpp_
