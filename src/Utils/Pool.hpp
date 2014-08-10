#ifndef _Pool_hpp_
#define _Pool_hpp_

#include <vector>

class Pool
{
    public:
        class Poolable
        {
            public:
                // Reset an object for reuse
                virtual void reset();
        };

    public:
        Pool();
        Pool(unsigned int initialCapacity);

        void free();

    private:
        std::vector<Poolable> freeObjects;

        // Highest number of free objects. Can be reset.
        int peak;
};

#endif /* _Pool_hpp_ */
