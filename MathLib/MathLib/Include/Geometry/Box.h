#ifndef __BOX_H__
#define __BOX_H__

#include "Vec3.h"

namespace Math::Geometry
{
	class Box
	{
	private:
		Vec3	m_position;
		float	m_x;
		float	m_y;
		float	m_z;

	public:
		Box(const Vec3& position = Vec3(0), const float& x = 1.f,
							const float& y = 1.f, const float& z = 1.f);
		Box(const Box& box);
		Box(Box&& box) noexcept;
		~Box() = default;

		Box&			operator=(const Box& box);

		inline Vec3		Position() const {return m_position;}
		inline float	X() const {return m_x;}
		inline float&	X() {return m_x;}
		inline float&	Y() {return m_y;}
		inline float	Y() const {return m_y;}
		inline float	Z() const {return m_z;}
		inline float&	Z() {return m_z;}
	};
}


#endif
