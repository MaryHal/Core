#ifndef _Math_hpp_
#define _Math_hpp_

#include <cmath>

namespace Math
{
    unsigned int nextPow2(register unsigned int n);
    bool checkPow2(unsigned int n);


    void distanceFromLine(double cx, double cy, double ax, double ay,
            double bx, double by, double &distanceSegment,
            double &distanceLine);

    static constexpr float PI = 3.14159265f;
    static constexpr float TWO_PI = (PI * 2.0f);

    float radToDeg(float rad);
    float degToRad(float deg);

    float sin(float deg);
    float cos(float deg);
    float tan(float deg);
    float arcSin(float value);
    float arcCos(float value);
    float arcTan2(float valY, float valX);
    float sqrt(float value);
};

#endif // _Math_hpp_

