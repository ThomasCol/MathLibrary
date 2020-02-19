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
		QXvec3	m_normal;
		QXfloat	m_d;

	public:
		Plane();
		Plane(const Plane& plane);
		Plane(Plane&& plane);
		Plane(const QXvec3& normal, const QXfloat& d);
		Plane(const QXvec3& p1, const QXvec3& p2, const QXvec3& p3);
		Plane(const QXvec3& normal, const QXvec3& p);
		~Plane() = default;

		inline QXvec3	Normal() const {return m_normal;}
		inline QXfloat	D() const {return m_d;}

		QXfloat			GetDistanceToPoint(const QXvec3& p) const;
		QXvec3			GetClosestPointOnPlane(const QXvec3& p) const;
		QXbool			GetSide(const QXvec3& p) const;
		QXbool			SameSide(const QXvec3& p1, const QXvec3& p2) const;

		static QXvec3	PlanesIntersection(const Plane& plane1, const Plane& plane2,
										const Plane& plane3);

		Plane& 			operator=(const Plane& plane);
	};
}




#endif
