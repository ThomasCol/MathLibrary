#ifndef _MATH_H_
#define _MATH_H_

#include <cmath>

#include "Mat4.h"
#include "Mat.h"
#include "Vec2.h"



namespace Math
{
    float   QuadraticSolver(const float& a, const float& b, const float& c);
    
    template<typename T>
    inline void Clamp(const T& min, const T& max, T& val)
    {
        if (val < min)
            val = min;

        if(val > max)
            val = max;
    }

    template<typename T>
    inline T   Clamp(const T& min, const T& max, const T& val)
    {
        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

	Vec3	WorldToLocal(Vec3 vec, Ref3 ref);
	Vec3	LocalToWorld(Vec3 vec, Ref3 ref);
}

#endif //_MATH_H_
