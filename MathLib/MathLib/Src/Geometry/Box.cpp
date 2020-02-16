#include "Box.h"

namespace Math::Geometry
{
	Box::Box(const Vec3& position, const float& x, const float& y, const float& z):
		m_position(position),
		m_x{x},
		m_y{y},
		m_z{z}
	{}

	Box::Box(const Box& box): 
		m_position(box.m_position),
		m_x{box.m_x},
		m_y{box.m_y},
		m_z{box.m_z}
	{}

	Box::Box(Box&& box) noexcept:
		m_position(std::move(box.m_position)),
		m_x{std::move(box.m_x)},
		m_y{std::move(box.m_y)},
		m_z{std::move(box.m_z)}
	{}



	Box& Box::operator=(const Box& box)
	{
		m_position = box.m_position;
		m_x = box.m_x;
		m_y = box.m_y;
		m_z = box.m_z;

		return *this;
	}
}
