#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "Vec3.h"


namespace Math::Geometry
{
	class Sphere
	{
	private:
		QXvec3	m_position;
		float	m_radius;

	public:
		Sphere(const QXvec3& position = QXvec3(0), const QXfloat& radius = 1.f);
		Sphere(const Sphere& sphere);
		Sphere(Sphere&& sphere);
		~Sphere() = default;

		inline QXvec3	Position() const {return m_position;}
		inline QXfloat	Radius() const {return m_radius;}

		Sphere&			operator=(const Sphere& sphere);
	};
}


#endif
