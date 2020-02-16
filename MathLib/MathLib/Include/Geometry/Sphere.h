#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "Vec3.h"


namespace Math::Geometry
{
	class Sphere
	{
	private:
		Vec3	m_position;
		float	m_radius;

	public:
		Sphere(const Vec3& position = Vec3(0), const float& radius = 1.f);
		Sphere(const Sphere& sphere);
		Sphere(Sphere&& sphere);
		~Sphere() = default;

		inline Vec3		Position() const {return m_position;}
		inline float	Radius() const {return m_radius;}

		Sphere&			operator=(const Sphere& sphere);
	};
}


#endif
