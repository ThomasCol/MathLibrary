#include "Plane.h"
#include <iostream>

namespace Math::Geometry
{
	Plane::Plane():
		m_normal(0, 1, 0),
		m_d{0}
	{}

	Plane::Plane(const Plane& plane):
		m_normal(plane.m_normal),
		m_d{plane.m_d}
	{}

	Plane::Plane(Plane&& plane):
		m_normal(std::move(plane.m_normal)),
		m_d{std::move(plane.m_d)}
	{}

	Plane::Plane(const QXvec3& normal, const QXfloat& d)
	{
		m_normal = normal.Normalize();
		m_d = d / normal.Length();
	}

	Plane::Plane(const QXvec3& p1, const QXvec3& p2, const QXvec3& p3)
	{
		QXvec3 v1(p2 - p1);
		QXvec3 v2(p3 - p1);
		m_normal = v1.Cross(v2).Normalize();
		m_d = p3.Dot(m_normal);
	}

	Plane::Plane(const QXvec3& normal, const QXvec3& p)
	{
		m_normal = normal.Normalize();
		m_d = p.Dot(m_normal);
	}




	float Plane::GetDistanceToPoint(const QXvec3& p) const
	{
		return abs(p.Dot(m_normal) - m_d) / m_normal.Length();
	}

	QXvec3 Plane::GetClosestPointOnPlane(const QXvec3& p) const
	{
		QXfloat	distance{GetDistanceToPoint(p)};

		return p + m_normal * -distance;
	}

	bool Plane::GetSide(const QXvec3& p) const
	{
		return (p.Dot(m_normal) > m_d);
	}

	bool Plane::SameSide(const QXvec3& p1, const QXvec3& p2) const
	{
		return (GetSide(p1) == GetSide(p2));
	}


	QXvec3 Plane::PlanesIntersection(const Plane& plane1, const Plane& plane2,
									const Plane& plane3)
	{
		QXmat	matA(plane1.m_normal, plane2.m_normal, plane3.m_normal);

		if (matA.Determinant() == 0)
			return QXvec3(0);

		QXmat	matB(3, 1);

		matB[0][0] = plane1.m_d;
		matB[1][0] = plane2.m_d;
		matB[2][0] = plane3.m_d;

		QXmat	matX(3, 1);

		matX = matA.Inverse() * matB;

		return QXvec3(matX[0][0], matX[1][0], matX[2][0]);
	}

	Plane& Plane::operator=(const Plane& plane)
	{
		m_normal = plane.m_normal;
		m_d = plane.m_d;

		return *this;
	}
}
