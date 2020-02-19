#include "OrientedBox.h"
#include "Mat4.h"

#include <limits>
#include <float.h>

namespace Math::Geometry
{
	QXorientedBox::QXorientedBox(const QXref3& ref, const QXvec3& halfSizes) noexcept:
		_ref {ref},
		_halfSizes {halfSizes}
	{}

	QXorientedBox::QXorientedBox(const QXorientedBox& box, const QXfloat& offsetExtention) noexcept :
		_ref {box._ref},
		_halfSizes {box._halfSizes + QXvec3(offsetExtention)}
	{}

	QXorientedBox::QXorientedBox(QXorientedBox&& box) noexcept :
		_ref(std::move(box._ref)),
		_halfSizes(std::move(box._halfSizes))
	{}

	QXorientedBox&	QXorientedBox::operator=(const QXorientedBox& box) noexcept
	{
		_ref = box._ref;
		_halfSizes = box._halfSizes;

		return *this;
	}

	QXorientedBox&	QXorientedBox::operator=(QXorientedBox&& box) noexcept
	{
		_ref = std::move(box._ref);
		_halfSizes = std::move(box._halfSizes);

		return *this;
	}

	QXfloat max(const QXfloat& f1, const QXfloat& f2) { return f1 > f2 ? f1 : f2;}

	QXvec3* QXorientedBox::GetPoints() const noexcept
	{
		QXvec3* array = new QXvec3[8];

		QXvec3 vx(_ref.i * _halfSizes.x);
		QXvec3 vy(_ref.j * _halfSizes.y);
		QXvec3 vz(_ref.k * _halfSizes.z);

		array[0] = _ref.o + vx + vy + vz;
		array[1] = _ref.o + vx + vy - vz;
		array[2] = _ref.o + vx - vy + vz;
		array[3] = _ref.o + vx - vy - vz;
		array[4] = _ref.o + vx * (-1) + vy + vz;
		array[5] = _ref.o + vx * (-1) + vy - vz;
		array[6] = _ref.o + vx * (-1) - vy + vz;
		array[7] = _ref.o + vx * (-1) - vy - vz;

		return array;
	}

	QXplane QXorientedBox::GetTopPlane() const noexcept
	{
		return QXplane(_ref.j, _ref.o + _ref.j * _halfSizes.y);
	}

	QXplane QXorientedBox::GetBottomPlane() const noexcept
	{
		return QXplane(_ref.j * (-1), _ref.o - _ref.j * _halfSizes.y);
	}

	QXplane QXorientedBox::GetFrontPlane() const noexcept
	{
		return QXplane(_ref.k, _ref.o + _ref.k * _halfSizes.z);
	}

	QXplane QXorientedBox::GetBackPlane() const noexcept
	{
		return QXplane(_ref.k * (-1), _ref.o - _ref.k * _halfSizes.z);
	}

	QXplane QXorientedBox::GetRightPlane() const noexcept
	{
		return QXplane(_ref.i, _ref.o + _ref.i * _halfSizes.x);
	}

	QXplane QXorientedBox::GetLeftPlane() const noexcept
	{
		return QXplane(_ref.i * (-1), _ref.o - _ref.i * _halfSizes.x);
	}

	QXint QXorientedBox::GetNumberPlaneGoodSide(const QXvec3& point) const noexcept
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

	QXsegment QXorientedBox::GetNearestSegment(const QXvec3& point) const noexcept
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

	QXvec3 QXorientedBox::GetNearestPoint(const QXvec3& point) const noexcept
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

	QXsegment* QXorientedBox::GetSegmentsWithThisPoint(const QXvec3& point) const noexcept
	{
		QXsegment* array = new QXsegment[3];

		QXvec3 localPoint;

		localPoint.x = (point - _ref.o).Dot(_ref.i);
		localPoint.y = (point - _ref.o).Dot(_ref.j);
		localPoint.z = (point - _ref.o).Dot(_ref.k);

		QXvec3 p1(_ref.o + _ref.i * localPoint.x
			+ _ref.j * localPoint.y
			- _ref.k * localPoint.z);

		QXvec3 p2(_ref.o + _ref.i * localPoint.x
			- _ref.j * localPoint.y
			+ _ref.k * localPoint.z);

		QXvec3 p3(_ref.o - _ref.i * localPoint.x
								 + _ref.j * localPoint.y
								 + _ref.k * localPoint.z);

		array[0] = QXsegment(point, p1);
		array[1] = QXsegment(point, p2);
		array[2] = QXsegment(point, p3);

		return array;
	}
}