#include "Segment.h"

namespace Math::Geometry
{
	Segment::Segment(const QXvec3& a, const QXvec3& b):
		m_a(a),
		m_b(b)
	{}

	Segment::Segment(const Segment& seg):
		m_a(seg.m_a),
		m_b(seg.m_b)
	{}

	Segment::Segment(Segment&& seg) noexcept:
		m_a(std::move(seg.m_a)),
		m_b(std::move(seg.m_b))
	{}

	Segment& Segment::operator=(const Segment& seg)
	{
		m_a = seg.m_a;
		m_b = seg.m_b;

		return *this;
	}
}
