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

	Plane::Plane(const Vec3& normal, const float& d)
	{
		m_normal = normal.Normalize();
		m_d = d / normal.Length();
	}

	Plane::Plane(const Vec3& p1, const Vec3& p2, const Vec3& p3)
	{
		Vec3 v1(p2 - p1);
		Vec3 v2(p3 - p1);
		m_normal = v1.Cross(v2).Normalize();
		m_d = p3.Dot(m_normal);
	}

	Plane::Plane(const Vec3& normal, const Vec3& p)
	{
		m_normal = normal.Normalize();
		m_d = p.Dot(m_normal);
	}




	float Plane::GetDistanceToPoint(const Vec3& p) const
	{
		return abs(p.Dot(m_normal) - m_d) / m_normal.Length();
	}

	Vec3 Plane::GetClosestPointOnPlane(const Vec3& p) const
	{
		float	distance{GetDistanceToPoint(p)};

		return p + m_normal * -distance;
	}

	bool Plane::GetSide(const Vec3& p) const
	{
		return (p.Dot(m_normal) > m_d);
	}

	bool Plane::SameSide(const Vec3& p1, const Vec3& p2) const
	{
		return (GetSide(p1) == GetSide(p2));
	}


	Vec3 Plane::PlanesIntersection(const Plane& plane1, const Plane& plane2,
									const Plane& plane3)
	{
		Mat	matA(plane1.m_normal, plane2.m_normal, plane3.m_normal);

		if (matA.Determinant() == 0)
			return Vec3(0);

		Mat	matB(3, 1);

		matB[0][0] = plane1.m_d;
		matB[1][0] = plane2.m_d;
		matB[2][0] = plane3.m_d;

		Mat	matX(3, 1);

		matX = matA.Inverse() * matB;

		return Vec3(matX[0][0], matX[1][0], matX[2][0]);
	}

	Plane& Plane::operator=(const Plane& plane)
	{
		m_normal = plane.m_normal;
		m_d = plane.m_d;

		return *this;
	}
}
