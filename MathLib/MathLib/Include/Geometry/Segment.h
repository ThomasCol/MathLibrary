#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "Vec3.h"

namespace Math::Geometry
{
	class Segment
	{
	private:
		Vec3	m_a;
		Vec3	m_b;

	public:
		Segment(const Vec3& a = 0.f, const Vec3& b = 1.f);
		Segment(const Segment& seg);
		Segment(Segment&& seg) noexcept;
		~Segment() = default;

		inline Vec3	A() const {return m_a;}
		inline Vec3	B() const {return m_b;}
		inline Vec3	AB() const {return m_b - m_a;}
		inline Vec3	BA() const {return m_a - m_b;}
		inline Vec3	GetPoint(const float& t) const {return m_a + t * AB();}

		Segment&	operator=(const Segment& seg);
	};
}



#endif
