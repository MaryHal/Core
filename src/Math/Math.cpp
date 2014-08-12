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

float Math::radToDeg(float rad)
{
    return 180 / PI * rad;
}

float Math::degToRad(float deg)
{
    return PI / 180 * deg;
}

float Math::sin(float deg)
{
    return std::sin(degToRad(deg));
}

float Math::cos(float deg)
{
    return std::cos(degToRad(deg));
}

float Math::tan(float deg)
{
    return std::tan(degToRad(deg));
}

float Math::arcSin(float value)
{
    return radToDeg(std::asin(value));
}

float Math::arcCos(float value)
{
    return radToDeg(std::acos(value));
}

float Math::arcTan2(float x, float y)
{
    return radToDeg(std::atan2(y, x));
}

float Math::sqrt(float value)
{
    return std::sqrt(value);
}

void Math::distanceFromLine(double cx, double cy, double ax, double ay,
        double bx, double by, double &distanceSegment,
        double &distanceLine)
{
    double r_numerator = (cx-ax)*(bx-ax) + (cy-ay)*(by-ay);
    double r_denomenator = (bx-ax)*(bx-ax) + (by-ay)*(by-ay);
    double r = r_numerator / r_denomenator;
    //
    /* double px = ax + r*(bx-ax); */
    /* double py = ay + r*(by-ay); */
    //
    double s =  ((ay-cy)*(bx-ax)-(ax-cx)*(by-ay) ) / r_denomenator;

    distanceLine = fabs(s)*sqrt(r_denomenator);

    //
    // (xx,yy) is the point on the lineSegment closest to (cx,cy)
    //
    /* double xx = px; */
    /* double yy = py; */

    if ((r >= 0) && (r <= 1))
    {
        distanceSegment = distanceLine;
    }
    else
    {
        double dist1 = (cx-ax)*(cx-ax) + (cy-ay)*(cy-ay);
        double dist2 = (cx-bx)*(cx-bx) + (cy-by)*(cy-by);
        if (dist1 < dist2)
        {
            /* xx = ax; */
            /* yy = ay; */
            distanceSegment = sqrt(dist1);
        }
        else
        {
            /* xx = bx; */
            /* yy = by; */
            distanceSegment = sqrt(dist2);
        }
    }

    return;
}

float Math::getMagnitude(float x, float y)
{
    return std::sqrt(x*x + y*y);
}

float Math::getDirection(float x, float y)
{
    return std::atan2(y, x);
}

/* float Math::getX(float d, float m) */
/* { */
/*     return m * cos(d); */
/* } */

/* float Math::getY(float d, float m) */
/* { */
/*     return m * sin(d); */
/* } */

