#include "Vec3.h"

namespace Math
{
    const Vec3 Vec3::zero       {0.f, 0.f, 0.f};
    const Vec3 Vec3::up         {0.f, 1.f, 0.f};
    const Vec3 Vec3::down       {0.f, -1.f, 0.f};
    const Vec3 Vec3::right      {1.f, 0.f, 0.f};
    const Vec3 Vec3::left       {-1.f, 0.f, 0.f};
    const Vec3 Vec3::forward    {0.f, 0.f, 1.f};
    const Vec3 Vec3::backward   {0.f, 0.f, -1.f};

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
}