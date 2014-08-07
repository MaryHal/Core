#ifndef _SpacialPartition_hpp_
#define _SpacialPartition_hpp_

class Mover;

class SpacialPartition
{
    public:
        SpacialPartition();

        void addBullet();
        void reset();

    private:
        static const unsigned int tileSize = 100;

        const Mover* space[7][5][100];
        int bulletCount[7][5];
};

#endif // _SpacialPartition_hpp_
