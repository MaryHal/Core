#ifndef _Trig_hpp_
#define _Trig_hpp_

#include <cmath>

class Trig
{
    public:
        static constexpr float PI = 3.14159265f;
        static constexpr float TWO_PI = (PI * 2.0f);

        static float sin(float deg)                     { return std::sin(degToRad(deg));          }
        static float cos(float deg)                     { return std::cos(degToRad(deg));          }
        static float tan(float deg)                     { return std::tan(degToRad(deg));          }
        static float arcSin(float value)                { return radToDeg(std::asin(value));       }
        static float arcCos(float value)                { return radToDeg(std::acos(value));       }
        static float arcTan2(float valY, float valX)    { return radToDeg(std::atan2(valY, valX)); }
        static float sqrt(float value)                  { return std::sqrt(value);                 }

        static float radToDeg(float rad)                { return 180 / PI * rad; }
        static float degToRad(float deg)                { return PI / 180 * deg; }
};

#endif // _Trigonometry_hpp_

