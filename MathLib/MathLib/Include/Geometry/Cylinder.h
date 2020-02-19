#ifndef __CYLINDER_H__
#define __CYLINDER_H__

#include "Segment.h"

namespace Math::Geometry
{
	class Cylinder
	{
	private:
		QXsegment	m_segment;
		QXfloat	m_radius;

	public:
		Cylinder(const QXsegment& segment = QXsegment(), const QXfloat& radius = 1.f);
		Cylinder(const Cylinder& cylinder);
		Cylinder(Cylinder&& cylinder);
		~Cylinder() = default;

		Cylinder& operator=(const Cylinder& cylinder);

		inline QXsegment	GetSegment() const { return m_segment; }
		inline QXfloat	Radius() const { return m_radius; }
		inline QXfloat	SqrtRadius() const {return m_radius * m_radius;}
	};

	typedef Cylinder Capsule;
}


#endif
