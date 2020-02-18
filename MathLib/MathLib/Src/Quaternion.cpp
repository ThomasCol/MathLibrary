#include "Quaternion.h"

namespace Math
{
	#pragma region Constructors
	QXquaternion::QXquaternion() : _w(1), _v(0, 0, 0)
	{
	}

	QXquaternion::QXquaternion(const QXquaternion& q) : _w(q._w), _v(q._v.x, q._v.y, q._v.z)
	{
	}

	QXquaternion::QXquaternion(const QXquaternion&& q)
	{
		std::move(q);
	}

	QXquaternion::QXquaternion(float vw, Vec3 vQ) : _w(vw), _v(Vec3(vQ))
	{
	}

	QXquaternion::QXquaternion(float vw, float vx, float vy, float vz) : _w(vw), _v(vx, vy, vz)
	{
	}
	#pragma endregion Constructors

	#pragma region Functions

	QXquaternion& QXquaternion::AddQuaternion(QXquaternion& q)
	{
		QXquaternion res = QXquaternion();

		res._w = _w + q._w;
		res._v = _v + q._v;
		return res;
	}

	QXquaternion& QXquaternion::ConjugateQuaternion()
	{
		QXquaternion res(_w, -_v.x, -_v.y, -_v.z);
		return res;
	}

	Mat4 QXquaternion::ConvertQuaternionToMat()
	{
		Mat4 res;

		res.array[0] = 1 - (2 * powf(_v.y, 2)) - (2 * powf(_v.z, 2));
		res.array[1] = (2 * _v.x * _v.y) - (2 * _w * _v.z);
		res.array[2] = (2 * _v.x * _v.z) + (2 * _w * _v.y);

		res.array[4] = (2 * _v.x * _v.y) + (2 * _w * _v.z);
		res.array[5] = 1 - (2 * powf(_v.x, 2)) - (2 * powf(_v.z, 2));
		res.array[6] = (2 * _v.y * _v.z) - (2 * _w * _v.x);

		res.array[8] = (2 * _v.x * _v.z) - (2 * _w * _v.y);
		res.array[9] = (2 * _v.y * _v.z) + (2 * _w * _v.x);
		res.array[10] = 1 - (2 * powf(_v.x, 2)) - (2 * powf(_v.y, 2));
		res.array[15] = 1;

		return res;
	}

	float QXquaternion::DotProductQuaternion(QXquaternion& q)
	{
		return (_w * q._w + _v.Dot(q._v));
	}

	QXquaternion& QXquaternion::InverseQuaternion()
	{
		return ConjugateQuaternion().MultQuaternion(1 / SqrtRootQuaternion());
	}

	QXquaternion& QXquaternion::MultQuaternion(float s)
	{
		QXquaternion res = QXquaternion();

		res._w = s * _w;
		res._v = _v * s;
		return res;
	}

	QXquaternion& QXquaternion::MultQuaternion(QXquaternion& q)
	{
		QXquaternion res = QXquaternion();

		res._w = _w * q._w - _v.x * q._v.x - _v.y * q._v.y - _v.z * q._v.z;
		res._v.x = _w * q._v.x + _v.x * q._w + _v.y * q._v.z - _v.z * q._v.y;
		res._v.y = _w * q._v.y - _v.x * q._v.z + _v.y * q._w + _v.z * q._v.x;
		res._v.z = _w * q._v.z + _v.x * q._v.y - _v.y * q._v.x + _v.z * q._w;

		return res;
	}

	void QXquaternion::NegateQuaternion()
	{
		_w = -_w;
		_v.x = -_v.x;
		_v.y = -_v.y;
		_v.z = -_v.z;
	}

	QXquaternion& QXquaternion::NormalizeQuaternion()
	{
		float s = 1 / QuaternionLength();

		return MultQuaternion(s);
	}

	void QXquaternion::NullQuaternion()
	{
		_w = 0;
		_v.x = _v.y = _v.z = 0;
	}

	float QXquaternion::QuaternionLength()
	{
		return sqrt(powf(_w, 2) + (_v.Dot(_v)));
	}

	QXquaternion& QXquaternion::ReturnNegateQuaternion()
	{
		QXquaternion res = QXquaternion();

		res._w = -_w;
		res._v.x = -_v.x;
		res._v.y = -_v.y;
		res._v.z = -_v.z;

		return res;
	}

	float QXquaternion::SqrtRootQuaternion()
	{
		return DotProductQuaternion(ConjugateQuaternion());
	}

	QXquaternion& QXquaternion::SlerpQuaternion(QXquaternion& q, float t)
	{
		float theta{ acos(DotProductQuaternion(q)) };

		if (theta < 0.f)
			* this = *this * -1.f;

		return ((*this * sin((1 - t) * theta) + q * sin(t * theta)) * (1 / sin(theta))).NormalizeQuaternion();
	}

	QXquaternion& QXquaternion::SubQuaternion(QXquaternion& q)
	{
		QXquaternion res = QXquaternion();

		res._w = _w - q._w;
		res._v = _v - q._v;
		return res;
	}

	std::string QXquaternion::ToString() const
	{
		std::string quat = std::to_string(_w) + ", " + _v.ToString();

		return quat;
	}

	#pragma endregion Functions

	#pragma region Static Functions

	Mat4 QXquaternion::ConvertQuaternionToMat(QXquaternion& q)
	{
		Mat4 res;

		res.array[0] = 1 - (2 * powf(q._v.y, 2)) - (2 * powf(q._v.z, 2));
		res.array[1] = (2 * q._v.x * q._v.y) - (2 * q._w * q._v.z);
		res.array[2] = (2 * q._v.x * q._v.z) + (2 * q._w * q._v.y);

		res.array[4] = (2 * q._v.x * q._v.y) + (2 * q._w * q._v.z);
		res.array[5] = 1 - (2 * powf(q._v.x, 2)) - (2 * powf(q._v.z, 2));
		res.array[6] = (2 * q._v.y * q._v.z) - (2 * q._w * q._v.x);

		res.array[8] = (2 * q._v.x * q._v.z) - (2 * q._w * q._v.y);
		res.array[9] = (2 * q._v.y * q._v.z) + (2 * q._w * q._v.x);
		res.array[10] = 1 - (2 * powf(q._v.x, 2)) - (2 * powf(q._v.y, 2));
		res.array[15] = 1;

		return res;
	}

	QXquaternion QXquaternion::ConvertMatToQuaternion(Mat4 m)
	{
		float qw = sqrt(1 + m.array[0] + m.array[5] + m.array[10]) / 2.f;
		float qx = (m.array[9] - m.array[6]) / (4 * qw);
		float qy = (m.array[2] - m.array[8]) / (4 * qw);
		float qz = (m.array[4] - m.array[1]) / (4 * qw);

		return QXquaternion(qw, Vec3(qx, qy, qz));
	}

	QXquaternion QXquaternion::ConvertEulerAngleToQuaternion(Vec3& euler)
	{
		float c1 = cos(euler.x / 2);
		float c2 = cos(euler.y / 2);
		float c3 = cos(euler.z / 2);
		float s1 = sin(euler.x / 2);
		float s2 = sin(euler.y / 2);
		float s3 = sin(euler.z / 2);

		float qw = ((c1 * c2 * c3) - (s1 * s2 * s3));
		float qx = ((s1 * s2 * c3) + (c1 * c2 * s3));
		float qy = ((s1 * c2 * c3) + (c1 * s2 * s3));
		float qz = ((c1 * s2 * c3) - (s1 * c2 * s3));

		return QXquaternion(qw, Vec3(qx, qy, qz));
	}

	QXquaternion QXquaternion::SlerpQuaternion(QXquaternion q1, QXquaternion q2, float t)
	{
		float theta{ q1.DotProductQuaternion(q2) };

		if (theta < 0.f)
			q1 = q1 * -1.f;

		return ((q1 * sin((1 - t) * theta) + q2 * sin(t * theta)) * (1 / sin(theta))).NormalizeQuaternion();
	}

	#pragma endregion Static Functions

	#pragma region Operator Functions

	QXquaternion& QXquaternion::operator=(const QXquaternion& q)
	{
		_w = q._w;
		_v = q._v;

		return *this;
	}

	QXquaternion& QXquaternion::operator*(float s)
	{
		QXquaternion res = QXquaternion();

		res._w = s * _w;
		res._v = _v * s;
		return res;
	}

	QXquaternion& QXquaternion::operator*(const QXquaternion& q)
	{
		QXquaternion res = QXquaternion();

		res._w = _w * q._w - _v.x * q._v.x - _v.y * q._v.y - _v.z * q._v.z;
		res._v.x = _w * q._v.x + _v.x * q._w + _v.y * q._v.z - v.z * q._v.y;
		res._v.y = _w * q._v.y - _v.x * q._v.z + _v.y * q._w + v.z * q._v.x;
		res._v.z = _w * q._v.z + _v.x * q._v.y - _v.y * q._v.x + v.z * q._w;

		return res;
	}

	QXquaternion& QXquaternion::operator+(const QXquaternion& q)
	{
		QXquaternion res = QXquaternion();

		res._w = _w + q._w;
		res._v = _v + q._v;
		return res;
	}

	QXquaternion& QXquaternion::operator-(const QXquaternion& q)
	{
		QXquaternion res = QXquaternion();

		res._w = _w - q._w;
		res._v = _v - q._v;
		return res;
	}

	#pragma endregion Operator Functions
}