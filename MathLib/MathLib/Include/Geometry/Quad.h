#ifndef __QUAD_H__
#define __QUAD_H__

#include "Vec3.h"

namespace Math::Geometry
{
	class Quad
	{
	private:
		QXvec3	m_position;
		QXvec3	m_i;
		QXvec3	m_j;
		QXvec3	m_k;
		QXfloat	m_x;
		QXfloat	m_y;

	public:
		Quad(const QXvec3& position = QXvec3(0), const QXvec3& i = QXvec3(1, 0, 0),
				const QXvec3& j = QXvec3(0, 1, 0), const QXvec3& k = QXvec3(0, 0, 1),
				const QXfloat& x = 1.f, const QXfloat & y = 1.f);
		Quad(const Quad& quad);
		Quad(Quad&& quad);
		~Quad() {};

		inline QXvec3	Position() const {return m_position;}
		inline QXvec3	I() const {return m_i;}
		inline QXvec3	J() const {return m_j;}
		inline QXvec3	K() const {return m_k;}
		inline QXfloat	X() const {return m_x;}
		inline QXfloat	Y() const {return m_y;}

		Quad&			operator=(const Quad& quad);
	};
}


#endif
