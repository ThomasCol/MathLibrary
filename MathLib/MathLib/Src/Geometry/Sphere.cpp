#include "Sphere.h"

namespace Math::Geometry
{
	Sphere::Sphere(const QXvec3& position, const QXfloat& radius):
		m_position(position),
		m_radius{radius}
	{}

	Sphere::Sphere(const Sphere& sphere):
		m_position(sphere.m_position),
		m_radius{sphere.m_radius}
	{}

	Sphere::Sphere(Sphere&& sphere):
		m_position(std::move(sphere.m_position)),
		m_radius{std::move(sphere.m_radius)}
	{}

	Sphere& Sphere::operator=(const Sphere& sphere)
	{
		m_position = sphere.m_position;
		m_radius = sphere.m_radius;

		return *this;
	}
}
