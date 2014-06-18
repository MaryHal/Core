#include "Math.hpp"

#include <cmath>

unsigned int Math::nextPow2(register unsigned int n)
{
    // Flip final bit
    --n;

    // Shift bits then OR data
    for (unsigned int i = 1; i < sizeof(unsigned int); i <<= 1)
        n |= (n >> i);

    // flip the last bit back over.
    return (n + 1);
}

bool Math::checkPow2(unsigned int n)
{
    return ((n & (n - 1)) == 0) ? true : false;
}

