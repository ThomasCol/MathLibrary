#ifndef __QUAD_H__
#define __QUAD_H__

#include "Vec3.h"

namespace Math::Geometry
{
	class Quad
	{
	private:
		Vec3	m_position;
		Vec3	m_i;
		Vec3	m_j;
		Vec3	m_k;
		float	m_x;
		float	m_y;

	public:
		Quad(const Vec3& position = Vec3(0), const Vec3& i = Vec3(1, 0, 0),
				const Vec3& j = Vec3(0, 1, 0), const Vec3& k = Vec3(0, 0, 1),
				const float& x = 1.f, const float& y = 1.f);
		Quad(const Quad& quad);
		Quad(Quad&& quad);
		~Quad() {};

		inline Vec3		Position() const {return m_position;}
		inline Vec3		I() const {return m_i;}
		inline Vec3		J() const {return m_j;}
		inline Vec3		K() const {return m_k;}
		inline float	X() const {return m_x;}
		inline float	Y() const {return m_y;}

		Quad&			operator=(const Quad& quad);
	};
}


#endif
