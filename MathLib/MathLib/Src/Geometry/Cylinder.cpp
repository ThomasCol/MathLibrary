#include "Cylinder.h"

namespace Math::Geometry
{
	Cylinder::Cylinder(const Segment& segment, const QXfloat& radius):
		m_segment(segment),
		m_radius{radius}
	{}

	Cylinder::Cylinder(const Cylinder& cylinder):
		m_segment(cylinder.m_segment),
		m_radius{cylinder.m_radius}
	{}

	Cylinder::Cylinder(Cylinder&& cylinder):
		m_segment(std::move(cylinder.m_segment)),
		m_radius{std::move(cylinder.m_radius)}
	{}

	Cylinder& Cylinder::operator=(const Cylinder& cylinder)
	{
		m_segment = cylinder.m_segment;
		m_radius = cylinder.m_radius;

		return *this;
	}
}
