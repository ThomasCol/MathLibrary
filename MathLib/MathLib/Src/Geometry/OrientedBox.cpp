#include "OrientedBox.h"
#include "Mat4.h"

#include <limits>
#include <float.h>

namespace Math::Geometry
{
	OrientedBox::OrientedBox(const Box& box, const Vec3& i, const Vec3& j, const Vec3& k):
		m_box(box),
		m_i(i),
		m_j(j),
		m_k(k)
	{}

	OrientedBox::OrientedBox(const OrientedBox& box, const float& offsetExtention):
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

	float max(const float& f1, const float& f2) { return f1 > f2 ? f1 : f2;}

	Box OrientedBox::AABB() const
	{
		Vec3 vx(m_i * m_box.X());
		Vec3 vy(m_j * m_box.Y());
		Vec3 vz(m_k * m_box.Z());
		Vec3 point(vx + vy + vz);
		float x{ std::numeric_limits<float>::min() };
		float y{ std::numeric_limits<float>::min() };
		float z{ std::numeric_limits<float>::min() };

		Vec3* array = Points();
		
		for (int i = 0; i < 8; i++)
		{
			x = max(x, m_box.Position().x - array[i].x);
			y = max(y, m_box.Position().y - array[i].y);
			z = max(z, m_box.Position().z - array[i].z);
		}

		delete[] array;

		return Box(m_box.Position(), x, y, z);
	}

	Vec3* OrientedBox::Points() const
	{
		Vec3* array = new Vec3[8];

		Vec3 vx(m_i * m_box.X());
		Vec3 vy(m_j * m_box.Y());
		Vec3 vz(m_k * m_box.Z());

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

	int OrientedBox::GetNumberPlaneGoodSide(const Vec3& point) const
	{
		int counter{0};

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

	Segment OrientedBox::GetNearestSegment(const Vec3& point) const
	{
		Vec3* array = Points();
		Vec3 p1(FLT_MAX);
		Vec3 p2(FLT_MAX);

		for (int i = 0; i < 8; i++)
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

	Vec3 OrientedBox::GetNearestPoint(const Vec3& point) const
	{
		Vec3* array = Points();
		Vec3 p1(array[0]);

		for (int i = 1; i < 6; i++)
		{
			if (point.Nearest(array[i], p1))
			{
				p1 = array[i];
			}
		}

		delete[] array;

		return p1;
	}

	Segment* OrientedBox::GetSegmentsWithThisPoint(const Vec3& point) const
	{
		Segment* array = new Segment[3];

		Vec3 localPoint;

		localPoint.x = (point - m_box.Position()).Dot(m_i);
		localPoint.y = (point - m_box.Position()).Dot(m_j);
		localPoint.z = (point - m_box.Position()).Dot(m_k);

		Vec3 p1(m_box.Position() + m_i * localPoint.x
								 + m_j * localPoint.y
								 - m_k * localPoint.z);

		Vec3 p2(m_box.Position() + m_i * localPoint.x
								 - m_j * localPoint.y
								 + m_k * localPoint.z);
		
		Vec3 p3(m_box.Position() - m_i * localPoint.x
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