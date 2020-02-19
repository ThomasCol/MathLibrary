#include "OrientedBox.h"
#include "Mat4.h"

#include <limits>
#include <float.h>

namespace Math::Geometry
{
	OrientedBox::OrientedBox(const Box& box, const QXvec3& i, const QXvec3& j, const QXvec3& k):
		m_box(box),
		m_i(i),
		m_j(j),
		m_k(k)
	{}

	OrientedBox::OrientedBox(const OrientedBox& box, const QXfloat& offsetExtention):
		m_box(box.m_box),
		m_i(box.m_i),
		m_j(box.m_j),
		m_k(box.m_k)
	{
		m_box.X() += offsetExtention;
		m_box.Y() += offsetExtention;
		m_box.Z() += offsetExtention;
	}

	OrientedBox::OrientedBox(OrientedBox&& box):
		m_box(std::move(box.m_box)),
		m_i(std::move(box.m_i)),
		m_j(std::move(box.m_j)),
		m_k(std::move(box.m_k))
	{}

	QXfloat max(const QXfloat& f1, const QXfloat& f2) { return f1 > f2 ? f1 : f2;}

	Box OrientedBox::AABB() const
	{
		QXvec3 vx(m_i * m_box.X());
		QXvec3 vy(m_j * m_box.Y());
		QXvec3 vz(m_k * m_box.Z());
		QXvec3 point(vx + vy + vz);
		QXfloat x{ std::numeric_limits<QXfloat>::min() };
		QXfloat y{ std::numeric_limits<QXfloat>::min() };
		QXfloat z{ std::numeric_limits<QXfloat>::min() };

		QXvec3* array = Points();

		for (QXint i = 0; i < 8; i++)
		{
			x = max(x, m_box.Position().x - array[i].x);
			y = max(y, m_box.Position().y - array[i].y);
			z = max(z, m_box.Position().z - array[i].z);
		}

		delete[] array;

		return Box(m_box.Position(), x, y, z);
	}

	QXvec3* OrientedBox::Points() const
	{
		QXvec3* array = new QXvec3[8];

		QXvec3 vx(m_i * m_box.X());
		QXvec3 vy(m_j * m_box.Y());
		QXvec3 vz(m_k * m_box.Z());

		array[0] = m_box.Position() + vx + vy + vz;
		array[1] = m_box.Position() + vx + vy - vz;
		array[2] = m_box.Position() + vx - vy + vz;
		array[3] = m_box.Position() + vx - vy - vz;
		array[4] = m_box.Position() + vx * (-1) + vy + vz;
		array[5] = m_box.Position() + vx * (-1) + vy - vz;
		array[6] = m_box.Position() + vx * (-1) - vy + vz;
		array[7] = m_box.Position() + vx * (-1) - vy - vz;

		return array;
	}

	Plane OrientedBox::TopPlane() const
	{
		return Plane(m_j, m_box.Position() + m_j * m_box.Y());
	}

	Plane OrientedBox::BottomPlane() const
	{
		return Plane(m_j * (-1), m_box.Position() - m_j * m_box.Y());
	}

	Plane OrientedBox::FrontPlane() const
	{
		return Plane(m_k, m_box.Position() + m_k * m_box.Z());
	}

	Plane OrientedBox::BackPlane() const
	{
		return Plane(m_k * (-1), m_box.Position() - m_k * m_box.Z());
	}

	Plane OrientedBox::RightPlane() const
	{
		return Plane(m_i, m_box.Position() + m_i * m_box.X());
	}

	Plane OrientedBox::LeftPlane() const
	{
		return Plane(m_i * (-1), m_box.Position() - m_i * m_box.X());
	}

	QXint OrientedBox::GetNumberPlaneGoodSide(const QXvec3& point) const
	{
		QXint counter{ 0 };

		if (TopPlane().GetSide(point))
			counter++;
		if (BottomPlane().GetSide(point))
			counter++;
		if (FrontPlane().GetSide(point))
			counter++;
		if (BackPlane().GetSide(point))
			counter++;
		if (RightPlane().GetSide(point))
			counter++;
		if (LeftPlane().GetSide(point))
			counter++;

		return counter;
	}

	Segment OrientedBox::GetNearestSegment(const QXvec3& point) const
	{
		QXvec3* array = Points();
		QXvec3 p1(FLT_MAX);
		QXvec3 p2(FLT_MAX);

		for (QXint i = 0; i < 8; i++)
		{
			if (point.Nearest(array[i], p1))
			{
				p2 = p1;
				p1 = array[i];
			}
			else if (point.Nearest(array[i], p2))
			{
				p2 = array[i];
			}

		}

		delete[] array;

		return Segment(p1, p2);
	}

	QXvec3 OrientedBox::GetNearestPoint(const QXvec3& point) const
	{
		QXvec3* array = Points();
		QXvec3 p1(array[0]);

		for (QXint i = 1; i < 6; i++)
		{
			if (point.Nearest(array[i], p1))
			{
				p1 = array[i];
			}
		}

		delete[] array;

		return p1;
	}

	Segment* OrientedBox::GetSegmentsWithThisPoint(const QXvec3& point) const
	{
		Segment* array = new Segment[3];

		QXvec3 localPoint;

		localPoint.x = (point - m_box.Position()).Dot(m_i);
		localPoint.y = (point - m_box.Position()).Dot(m_j);
		localPoint.z = (point - m_box.Position()).Dot(m_k);

		QXvec3 p1(m_box.Position() + m_i * localPoint.x
								 + m_j * localPoint.y
								 - m_k * localPoint.z);

		QXvec3 p2(m_box.Position() + m_i * localPoint.x
								 - m_j * localPoint.y
								 + m_k * localPoint.z);
		
		QXvec3 p3(m_box.Position() - m_i * localPoint.x
								 + m_j * localPoint.y
								 + m_k * localPoint.z);

		array[0] = Segment(point, p1);
		array[1] = Segment(point, p2);
		array[2] = Segment(point, p3);

		return array;
	}

	OrientedBox&	OrientedBox::operator=(const OrientedBox& box)
	{
		m_box = box.m_box;
		m_i = box.m_i;
		m_j = box.m_j;
		m_k = box.m_k;

		return *this;
	}
}