#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "Vec3.h"

namespace Math::Geometry
{
	class Segment
	{
	private:
		QXvec3	m_a;
		QXvec3	m_b;

	public:
		Segment(const QXvec3& a = 0.f, const QXvec3 & b = 1.f);
		Segment(const Segment& seg);
		Segment(Segment&& seg) noexcept;
		~Segment() = default;

		inline QXvec3	A() const {return m_a;}
		inline QXvec3	B() const {return m_b;}
		inline QXvec3	AB() const {return m_b - m_a;}
		inline QXvec3	BA() const {return m_a - m_b;}
		inline QXvec3	GetPoint(const QXfloat& t) const {return m_a + AB() * t;}

		Segment&		operator=(const Segment& seg);
	};
}



#endif
