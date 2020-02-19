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
		QXvec3	m_i;
		QXvec3	m_j;
		QXvec3	m_k;

	public:
		OrientedBox(const Box& box = Box(), const QXvec3& i = QXvec3(1, 0, 0),
				const QXvec3& j = QXvec3(1, 0, 0), const QXvec3& k = QXvec3(1, 0, 0));
		OrientedBox(const OrientedBox& box, const QXfloat& offsetExtention = 0.f);
		OrientedBox(OrientedBox&& box);
		~OrientedBox() = default;

		inline Box		box() const {return m_box;}
		inline QXvec3	position() const {return m_box.Position();}
		inline QXvec3	I() const {return m_i;}
		inline QXvec3	J() const {return m_j;}
		inline QXvec3	K() const {return m_k;}
		inline QXfloat	X() const {return m_box.X();}
		inline QXfloat	Y() const {return m_box.Y();}
		inline QXfloat	Z() const {return m_box.Z();}
		Box				AABB() const;
		QXvec3*			Points() const;
		Plane			TopPlane() const;
		Plane			BottomPlane() const;
		Plane			FrontPlane() const;
		Plane			BackPlane() const;
		Plane			LeftPlane() const;
		Plane			RightPlane() const;
		QXint			GetNumberPlaneGoodSide(const QXvec3& point) const;
		Segment			GetNearestSegment(const QXvec3& point) const;
		QXvec3			GetNearestPoint(const QXvec3& point) const;
		Segment*		GetSegmentsWithThisPoint(const QXvec3& point) const;

		OrientedBox&	operator=(const OrientedBox& box);
	};
}



#endif
