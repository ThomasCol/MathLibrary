#include "OrientedBox.h"
#include "Mat4.h"

#include <limits>
#include <float.h>

namespace Math::Geometry
{
	QXorientedBox::QXorientedBox(const Box& box, const QXvec3& i, const QXvec3& j, const QXvec3& k) noexcept :
		m_box(box),
		m_i(i),
		m_j(j),
		m_k(k)
	{}

	QXorientedBox::QXorientedBox(const QXorientedBox& box, const QXfloat& offsetExtention) noexcept :
		m_box(box.m_box),
		m_i(box.m_i),
		m_j(box.m_j),
		m_k(box.m_k)
	{
		m_box.X() += offsetExtention;
		m_box.Y() += offsetExtention;
		m_box.Z() += offsetExtention;
	}

	QXorientedBox::QXorientedBox(QXorientedBox&& box) noexcept :
		m_box(std::move(box.m_box)),
		m_i(std::move(box.m_i)),
		m_j(std::move(box.m_j)),
		m_k(std::move(box.m_k))
	{}

	QXfloat max(const QXfloat& f1, const QXfloat& f2) { return f1 > f2 ? f1 : f2;}

	Box QXorientedBox::GetBox() const
	{
		QXvec3 vx(m_i * m_box.X());
		QXvec3 vy(m_j * m_box.Y());
		QXvec3 vz(m_k * m_box.Z());
		QXvec3 point(vx + vy + vz);
		QXfloat x{ std::numeric_limits<QXfloat>::min() };
		QXfloat y{ std::numeric_limits<QXfloat>::min() };
		QXfloat z{ std::numeric_limits<QXfloat>::min() };

		QXvec3* array = GetPoints();

		for (QXint i = 0; i < 8; i++)
		{
			x = max(x, m_box.GetPosition().x - array[i].x);
			y = max(y, m_box.GetPosition().y - array[i].y);
			z = max(z, m_box.GetPosition().z - array[i].z);
		}

		delete[] array;

		return Box(m_box.GetPosition(), x, y, z);
	}

	QXvec3* QXorientedBox::GetPoints() const
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

	QXplane QXorientedBox::GetTopPlane() const
	{
		return QXplane(m_j, m_box.GetPosition() + m_j * m_box.GetY());
	}

	QXplane QXorientedBox::GetBottomPlane() const
	{
		return QXplane(m_j * (-1), m_box.GetPosition() - m_j * m_box.GetY());
	}

	QXplane QXorientedBox::GetFrontPlane() const
	{
		return QXplane(m_k, m_box.GetPosition() + m_k * m_box.GetZ());
	}

	QXplane QXorientedBox::GetBackPlane() const
	{
		return QXplane(m_k * (-1), m_box.GetPosition() - m_k * m_box.GetZ());
	}

	QXplane QXorientedBox::GetRightPlane() const
	{
		return QXplane(m_i, m_box.GetPosition() + m_i * m_box.GetX());
	}

	QXplane QXorientedBox::GetLeftPlane() const
	{
		return QXplane(m_i * (-1), m_box.GetPosition() - m_i * m_box.GetX());
	}

	QXint QXorientedBox::GetNumberPlaneGoodSide(const QXvec3& point) const
	{
		QXint counter{ 0 };

		if (GetTopPlane().GetSide(point))
			counter++;
		if (GetBottomPlane().GetSide(point))
			counter++;
		if (GetFrontPlane().GetSide(point))
			counter++;
		if (GetBackPlane().GetSide(point))
			counter++;
		if (GetRightPlane().GetSide(point))
			counter++;
		if (GetLeftPlane().GetSide(point))
			counter++;

		return counter;
	}

	QXsegment QXorientedBox::GetNearestSegment(const QXvec3& point) const
	{
		QXvec3* array = GetPoints();
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

		return QXsegment(p1, p2);
	}

	QXvec3 QXorientedBox::GetNearestPoint(const QXvec3& point) const
	{
		QXvec3* array = GetPoints();
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

	QXsegment* QXorientedBox::GetSegmentsWithThisPoint(const QXvec3& point) const
	{
		QXsegment* array = new QXsegment[3];

		QXvec3 localPoint;

		localPoint.x = (point - m_box.GetPosition()).Dot(m_i);
		localPoint.y = (point - m_box.GetPosition()).Dot(m_j);
		localPoint.z = (point - m_box.GetPosition()).Dot(m_k);

		QXvec3 p1(m_box.GetPosition() + m_i * localPoint.x
			+ m_j * localPoint.y
			- m_k * localPoint.z);

		QXvec3 p2(m_box.GetPosition() + m_i * localPoint.x
			- m_j * localPoint.y
			+ m_k * localPoint.z);

		QXvec3 p3(m_box.GetPosition() - m_i * localPoint.x
								 + m_j * localPoint.y
								 + m_k * localPoint.z);

		array[0] = QXsegment(point, p1);
		array[1] = QXsegment(point, p2);
		array[2] = QXsegment(point, p3);

		return array;
	}

	QXorientedBox&	QXorientedBox::operator=(const QXorientedBox& box)
	{
		m_box = box.m_box;
		m_i = box.m_i;
		m_j = box.m_j;
		m_k = box.m_k;

		return *this;
	}
}