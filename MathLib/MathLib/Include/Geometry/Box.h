#ifndef __BOX_H__
#define __BOX_H__

#include "Vec3.h"

namespace Math::Geometry
{
	class Box
	{
	private:
		QXvec3	m_position;
		QXfloat	m_x;
		QXfloat	m_y;
		QXfloat	m_z;

	public:
		Box(const QXvec3& position = QXvec3(0), const QXfloat& x = 1.f,
							const QXfloat & y = 1.f, const QXfloat & z = 1.f);
		Box(const Box& box);
		Box(Box&& box) noexcept;
		~Box() = default;

		Box&			operator=(const Box& box);

		inline QXvec3	Position() const {return m_position;}
		inline QXfloat	X() const {return m_x;}
		inline QXfloat&	X() {return m_x;}
		inline QXfloat&	Y() {return m_y;}
		inline QXfloat	Y() const {return m_y;}
		inline QXfloat	Z() const {return m_z;}
		inline QXfloat&	Z() {return m_z;}
	};
}


#endif
