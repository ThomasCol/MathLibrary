#include "Math.hpp"

namespace Math
{
    float QuadraticSolver(const float& a, const float& b, const float& c)
    {
        float delta {b * b - 4 * a * c};
        float doubleA = 2 * a;

        if (delta < 0)
            return -1;
        
        if (delta == 0)
            return -b / doubleA;

        float   sqrtDelta {(float)sqrt(delta)};
        float   first = (-b + sqrtDelta) / doubleA;
        float   second = (-b - sqrtDelta) / doubleA;

        if (first >= 0 && first <= 1)
        {
            if (second >= 0 && second <= 1)
            {
                if (second > first)
                    return first;

                return second;
            }
            return first;
        }
        if (second >= 0 && second <= 1)
            return second;

        return -1;
    }
}