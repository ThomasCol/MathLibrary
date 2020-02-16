#ifndef __PLANE_H__
#define __PLANE_H__

#include <math.h>
#include "Vec3.h"
#include "Mat.h"

namespace Math::Geometry
{
	class Plane
	{
	private:
		Vec3	m_normal;
		float	m_d;

	public:
		Plane();
		Plane(const Plane& plane);
		Plane(Plane&& plane);
		Plane(const Vec3& normal, const float& d);
		Plane(const Vec3& p1, const Vec3& p2, const Vec3& p3);
		Plane(const Vec3& normal, const Vec3& p);
		~Plane() = default;

		inline Vec3		Normal() const {return m_normal;}
		inline float	D() const {return m_d;}

		float			GetDistanceToPoint(const Vec3& p) const;
		Vec3			GetClosestPointOnPlane(const Vec3& p) const;
		bool			GetSide(const Vec3& p) const;
		bool			SameSide(const Vec3& p1, const Vec3& p2) const;

		static Vec3		PlanesIntersection(const Plane& plane1, const Plane& plane2,
										const Plane& plane3);

		Plane& 			operator=(const Plane& plane);
	};
}




#endif
