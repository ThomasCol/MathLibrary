#include "Quaternion.h"

namespace Math
{
	#pragma region Constructors
	QXquaternion::QXquaternion() : w(1), v(0, 0, 0)
	{
	}

	QXquaternion::QXquaternion(const QXquaternion& q) : w(q.w), v(q.v.x, q.v.y, q.v.z)
	{
	}

	QXquaternion::QXquaternion(const QXquaternion&& q)
	{
		std::move(q);
	}

	QXquaternion::QXquaternion(QXfloat vw, QXvec3 vQ) : w(vw), v(QXvec3(vQ))
	{
	}

	QXquaternion::QXquaternion(QXfloat vw, QXfloat vx, QXfloat vy, QXfloat vz) : w(vw), v(vx, vy, vz)
	{
	}
	#pragma endregion Constructors

	#pragma region Functions

	QXquaternion& QXquaternion::AddQuaternion(QXquaternion& q)
	{
		QXquaternion res = QXquaternion();

		res.w = w + q.w;
		res.v = v + q.v;
		return res;
	}

	QXquaternion& QXquaternion::ConjugateQuaternion()
	{
		QXquaternion res(w, -v.x, -v.y, -v.z);
		return res;
	}

	QXmat4 QXquaternion::ConvertQuaternionToMat()
	{
		QXmat4 res;

		res.array[0] = 1 - (2 * powf(v.y, 2)) - (2 * powf(v.z, 2));
		res.array[1] = (2 * v.x * v.y) - (2 * w * v.z);
		res.array[2] = (2 * v.x * v.z) + (2 * w * v.y);

		res.array[4] = (2 * v.x * v.y) + (2 * w * v.z);
		res.array[5] = 1 - (2 * powf(v.x, 2)) - (2 * powf(v.z, 2));
		res.array[6] = (2 * v.y * v.z) - (2 * w * v.x);

		res.array[8] = (2 * v.x * v.z) - (2 * w * v.y);
		res.array[9] = (2 * v.y * v.z) + (2 * w * v.x);
		res.array[10] = 1 - (2 * powf(v.x, 2)) - (2 * powf(v.y, 2));
		res.array[15] = 1;

		return res;
	}

	float QXquaternion::DotProductQuaternion(QXquaternion& q)
	{
		return (w * q.w + v.Dot(q.v));
	}

	QXquaternion& QXquaternion::InverseQuaternion()
	{
		return ConjugateQuaternion().MultQuaternion(1 / SqrtRootQuaternion());
	}

	QXquaternion& QXquaternion::MultQuaternion(QXfloat s)
	{
		QXquaternion res = QXquaternion();

		res.w = s * w;
		res.v = v * s;
		return res;
	}

	QXquaternion& QXquaternion::MultQuaternion(QXquaternion& q)
	{
		QXquaternion res = QXquaternion();

		res.w = w * q.w - v.x * q.v.x - v.y * q.v.y - v.z * q.v.z;
		res.v.x = w * q.v.x + v.x * q.w + v.y * q.v.z - v.z * q.v.y;
		res.v.y = w * q.v.y - v.x * q.v.z + v.y * q.w + v.z * q.v.x;
		res.v.z = w * q.v.z + v.x * q.v.y - v.y * q.v.x + v.z * q.w;

		return res;
	}

	void QXquaternion::NegateQuaternion()
	{
		w = -w;
		v.x = -v.x;
		v.y = -v.y;
		v.z = -v.z;
	}

	QXquaternion& QXquaternion::NormalizeQuaternion()
	{
		float s = 1 / QuaternionLength();

		return MultQuaternion(s);
	}

	void QXquaternion::NullQuaternion()
	{
		w = 0;
		v.x = v.y = v.z = 0;
	}

	float QXquaternion::QuaternionLength()
	{
		return sqrt(powf(w, 2) + (v.Dot(v)));
	}

	QXquaternion& QXquaternion::ReturnNegateQuaternion()
	{
		QXquaternion res = QXquaternion();

		res.w = -w;
		res.v.x = -v.x;
		res.v.y = -v.y;
		res.v.z = -v.z;

		return res;
	}

	float QXquaternion::SqrtRootQuaternion()
	{
		return DotProductQuaternion(ConjugateQuaternion());
	}

	QXquaternion& QXquaternion::SlerpQuaternion(QXquaternion& q, QXfloat t)
	{
		float theta{ acos(DotProductQuaternion(q)) };

		if (theta < 0.f)
			* this = *this * -1.f;

		return ((*this * sin((1 - t) * theta) + q * sin(t * theta)) * (1 / sin(theta))).NormalizeQuaternion();
	}

	QXquaternion& QXquaternion::SubQuaternion(QXquaternion& q)
	{
		QXquaternion res = QXquaternion();

		res.w = w - q.w;
		res.v = v - q.v;
		return res;
	}

	QXstring QXquaternion::ToString() const
	{
		QXstring quat = std::to_string(w) + ", " + v.ToString();

		return quat;
	}

	#pragma endregion Functions

	#pragma region Static Functions

	QXmat4 QXquaternion::ConvertQuaternionToMat(QXquaternion& q)
	{
		QXmat4 res;

		res.array[0] = 1 - (2 * powf(q.v.y, 2)) - (2 * powf(q.v.z, 2));
		res.array[1] = (2 * q.v.x * q.v.y) - (2 * q.w * q.v.z);
		res.array[2] = (2 * q.v.x * q.v.z) + (2 * q.w * q.v.y);

		res.array[4] = (2 * q.v.x * q.v.y) + (2 * q.w * q.v.z);
		res.array[5] = 1 - (2 * powf(q.v.x, 2)) - (2 * powf(q.v.z, 2));
		res.array[6] = (2 * q.v.y * q.v.z) - (2 * q.w * q.v.x);

		res.array[8] = (2 * q.v.x * q.v.z) - (2 * q.w * q.v.y);
		res.array[9] = (2 * q.v.y * q.v.z) + (2 * q.w * q.v.x);
		res.array[10] = 1 - (2 * powf(q.v.x, 2)) - (2 * powf(q.v.y, 2));
		res.array[15] = 1;

		return res;
	}

	QXquaternion QXquaternion::ConvertMatToQuaternion(QXmat4 m)
	{
		float qw = sqrt(1 + m.array[0] + m.array[5] + m.array[10]) / 2.f;
		float qx = (m.array[9] - m.array[6]) / (4 * qw);
		float qy = (m.array[2] - m.array[8]) / (4 * qw);
		float qz = (m.array[4] - m.array[1]) / (4 * qw);

		return QXquaternion(qw, QXvec3(qx, qy, qz));
	}

	QXquaternion QXquaternion::ConvertEulerAngleToQuaternion(QXvec3& euler)
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

		return QXquaternion(qw, QXvec3(qx, qy, qz));
	}

	QXquaternion QXquaternion::SlerpQuaternion(QXquaternion q1, QXquaternion q2, QXfloat t)
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
		w = q.w;
		v = q.v;

		return *this;
	}

	QXquaternion& QXquaternion::operator*(QXfloat s)
	{
		QXquaternion res = QXquaternion();

		res.w = s * w;
		res.v = v * s;
		return res;
	}

	QXquaternion& QXquaternion::operator*(const QXquaternion& q)
	{
		QXquaternion res = QXquaternion();

		res.w = w * q.w - v.x * q.v.x - v.y * q.v.y - v.z * q.v.z;
		res.v.x = w * q.v.x + v.x * q.w + v.y * q.v.z - v.z * q.v.y;
		res.v.y = w * q.v.y - v.x * q.v.z + v.y * q.w + v.z * q.v.x;
		res.v.z = w * q.v.z + v.x * q.v.y - v.y * q.v.x + v.z * q.w;

		return res;
	}

	QXquaternion& QXquaternion::operator+(const QXquaternion& q)
	{
		QXquaternion res = QXquaternion();

		res.w = w + q.w;
		res.v = v + q.v;
		return res;
	}

	QXquaternion& QXquaternion::operator-(const QXquaternion& q)
	{
		QXquaternion res = QXquaternion();

		res.w = w - q.w;
		res.v = v - q.v;
		return res;
	}

	#pragma endregion Operator Functions
}