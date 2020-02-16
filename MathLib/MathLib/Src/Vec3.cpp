#include "Vec3.h"

#include <cmath>

#include "MathDefines.h"

namespace Math
{
#pragma region Attributes

    const Vec3 Vec3::zero       {0.f, 0.f, 0.f};
    const Vec3 Vec3::up         {0.f, 1.f, 0.f};
    const Vec3 Vec3::down       {0.f, -1.f, 0.f};
    const Vec3 Vec3::right      {1.f, 0.f, 0.f};
    const Vec3 Vec3::left       {-1.f, 0.f, 0.f};
    const Vec3 Vec3::forward    {0.f, 0.f, 1.f};
    const Vec3 Vec3::backward   {0.f, 0.f, -1.f};

#pragma endregion

#pragma region Constructors

    Vec3::Vec3(const float& x = 0.f, const float& y = 0.f, const float& z = 0.f) :
        r {x},
        g {y},
        b {z}
    {}

    Vec3::Vec3(const Vec3& vector) :
        x {vector.x},
        y {vector.x},
        z {vector.x}
    {}

    Vec3::Vec3(Vec3&& vector) :
        x {std::move(vector.x)},
        y {std::move(vector.y)},
        z {std::move(vector.z)}
    {}

#pragma endregion

#pragma region Operators

    Vec3&   Vec3::operator=(const Vec3& vector)
    {
        x = vector.x;
        y = vector.y;
        z = vector.z;

        return *this;
    }
    
    Vec3&   Vec3::operator=(Vec3&& vector)
    {
        x = std::move(vector.x);
        y = std::move(vector.y);
        z = std::move(vector.z);

        return *this;
    }

    Vec3&   Vec3::operator+=(const Vec3& vector)
    {
        x += vector.x;
        y += vector.y;
        z += vector.z;

        return *this;
    }

    Vec3    Vec3::operator+(const Vec3& vector) const
    {
        Vec3 res;

        res.x = vector.x + x;
        res.y = vector.y + y;
        res.z = vector.z + z;

        return res;
    }

    Vec3&   Vec3::operator-=(const Vec3& vector)
    {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;

        return *this;
    }

    Vec3    Vec3::operator-(const Vec3& vector) const
    {
        Vec3 res;

        res.x = x - vector.x;
        res.y = y - vector.y;
        res.z = z - vector.z;

        return res;
    }

    Vec3    Vec3::operator-() const
    {
        return {-x, -y, -z};
    }

    Vec3&   Vec3::operator/=(float value)
    {
        x /= value;
        y /= value;
        z /= value;

        return *this;
    }

    Vec3    Vec3::operator/(float value) const
    {
        Vec3 res;

        res.x = x / value;
        res.y = y / value;
        res.z = z / value;

        return res;
    }

    Vec3&   Vec3::operator*=(float value)
    {
        x /= value;
        y /= value;
        z /= value;

        return *this;
    }

    Vec3    Vec3::operator*(float value) const
    {
        Vec3 res;

        res.x = x * value;
        res.y = y * value;
        res.z = z * value;

        return res;
    }

    bool    Vec3::operator==(const Vec3& vector) const
    {
        return SqrLength() == vector.SqrLength();
    }

    bool    Vec3::operator!=(const Vec3& vector) const
    {
        return SqrLength() != vector.SqrLength();
    }

    bool    Vec3::operator<(const Vec3& vector) const
    {
        return SqrLength() < vector.SqrLength();
    }

    bool    Vec3::operator<=(const Vec3& vector) const
    {
        return SqrLength() <= vector.SqrLength();
    }

    bool    Vec3::operator>(const Vec3& vector) const
    {
        return SqrLength() > vector.SqrLength();
    }

    bool    Vec3::operator>=(const Vec3& vector) const
    {
        return SqrLength() >= vector.SqrLength();
    }

    float   Vec3::operator[](uint idx)
    {
        switch (idx)
        {
            case 0: return x; break;
            
            case 1: return y; break;
            
            case 2: return z; break;
        
            default: return 0.f; break;
        }
    }

#pragma endregion

#pragma region Functions

    float   Vec3::Angle(const Vec3& vector) const
    {
        float len = SqrLength() * vector.SqrLength();
        if (len == 0.0f)
            return 0.0f;

        float div = Dot(vector) / sqrt(len);

        if (div > 1.0f)
            return 0.0f;
        else if (div < -1.0f)
            return (float)Q_PI;
        
        return acosf(div);
    }

    Vec3    Vec3::Cross(const Vec3& vector) const
    {
        return {(y * vector.z) - (z * vector.y), (z * vector.x) - (x * vector.z), (x * vector.y) - (y * vector.x)};
    }

    float   Vec3::Dot(const Vec3& vector) const
    {
        return x * vector.x + y * vector.y + z * vector.z;
    }

#pragma endregion
}