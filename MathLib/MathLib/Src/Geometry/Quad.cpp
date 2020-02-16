#include "Quad.h"

namespace Math::Geometry
{
	Quad::Quad(const Vec3& position, const Vec3& i, const Vec3& j, const Vec3& k,
			const float& x, const float& y):
		m_position(position),
		m_i(i),
		m_j(j),
		m_k(k),
		m_x{x},
		m_y{y}
	{}

	Quad::Quad(const Quad& quad):
		m_position(quad.m_position),
		m_i(quad.m_i),
		m_j(quad.m_j),
		m_k(quad.m_k),
		m_x{quad.m_x},
		m_y{quad.m_y}
	{}

	Quad::Quad(Quad&& quad):
		m_position(std::move(quad.m_position)),
		m_i(std::move(quad.m_i)),
		m_j(std::move(quad.m_j)),
		m_k(std::move(quad.m_k)),
		m_x{std::move(quad.m_x)},
		m_y{std::move(quad.m_y)}
	{}

	Quad& Quad::operator=(const Quad& quad)
	{
		m_position = quad.m_position;
		m_i = quad.m_i;
		m_j = quad.m_j;
		m_k = quad.m_k;
		m_x = quad.m_x;
		m_y = quad.m_y;

		return *this;
	}
}
