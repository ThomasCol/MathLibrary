#ifndef __ORIENTEDBOX_H__
#define __ORIENTEDBOX_H__

#include "Box.h"
#include "Segment.h"
#include "Plane.h"


namespace Math::Geometry
{
	class OrientedBox
	{
	private:
		Box		m_box;
		Vec3	m_i;
		Vec3	m_j;
		Vec3	m_k;

	public:
		OrientedBox(const Box& box = Box(), const Vec3& i = Vec3(1, 0, 0),
				const Vec3& j = Vec3(1, 0, 0), const Vec3& k = Vec3(1, 0, 0));
		OrientedBox(const OrientedBox& box, const float& offsetExtention = 0.f);
		OrientedBox(OrientedBox&& box);
		~OrientedBox() = default;

		inline Box		box() const {return m_box;}
		inline Vec3		position() const {return m_box.Position();}
		inline Vec3		I() const {return m_i;}
		inline Vec3		J() const {return m_j;}
		inline Vec3		K() const {return m_k;}
		inline float	X() const {return m_box.X();}
		inline float	Y() const {return m_box.Y();}
		inline float	Z() const {return m_box.Z();}
		Box				AABB() const;
		Vec3*			Points() const;
		Plane			TopPlane() const;
		Plane			BottomPlane() const;
		Plane			FrontPlane() const;
		Plane			BackPlane() const;
		Plane			LeftPlane() const;
		Plane			RightPlane() const;
		int				GetNumberPlaneGoodSide(const Vec3& point) const;
		Segment			GetNearestSegment(const Vec3& point) const;
		Vec3			GetNearestPoint(const Vec3& point) const;
		Segment*		GetSegmentsWithThisPoint(const Vec3& point) const;

		OrientedBox&	operator=(const OrientedBox& box);
	};
}



#endif
