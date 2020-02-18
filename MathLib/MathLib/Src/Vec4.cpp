#include "Vec4.h"

#include <math.h>

namespace Math
{
#pragma region Attributes

	const QXvec4	QXvec4::zero {0.f, 0.f, 0.f, 0.f};
	const QXvec4	QXvec4::up {0.f, 1.f, 0.f, 0.f};
	const QXvec4	QXvec4::down {0.f, -1.f, 0.f, 0.f};
	const QXvec4	QXvec4::left {-1.f, 0.f, 0.f, 0.f};
	const QXvec4	QXvec4::right {1.f, 0.f, 0.f, 0.f};
	const QXvec4	QXvec4::forward {0.0f, 0.0f, 1.0f, 0.f};
	const QXvec4	QXvec4::backward {0.0f, 0.0f, -1.0f, 0.f};

#pragma endregion

#pragma region Constructors

	QXvec4::QXvec4(const QXfloat& posX = 0.f, const QXfloat& posY = 0.f, const QXfloat& posZ = 0.f, const QXfloat& posW = 0.f):
		x (posX),
		y (posY),
		z (posZ),
		w (posW)
	{
	}

	QXvec4::QXvec4(const QXvec3& vec, QXfloat posW):
		x { vec.x },
		y { vec.y },
		z { vec.z },
		w { posW }
	{}

	QXvec4::QXvec4(const QXvec4& vec) :
		x{ vec.x },
		y{ vec.y },
		z{ vec.z },
		w{ vec.w }
	{}

	QXvec4::QXvec4(QXvec4&& vec) :
		x{ std::move(vec.x) },
		y{ std::move(vec.y) },
		z{ std::move(vec.z) },
		w{ std::move(vec.w) }
	{}

#pragma endregion

#pragma region Operators

	QXvec4& QXvec4::operator=(const QXvec4& vect)
	{
		x = vect.x;
		y = vect.y;
	    z = vect.z;
		w = vect.w;

		return *this;
	}

	std::ostream&	operator<<(std::ostream& os, const QXvec4& vect)
	{
		os << vect.x << ", " << vect.y << ", " << vect.z <<
								", " << vect.w << std::endl;

		return os;
	}

	std::string	operator+(std::string& str, const QXvec4& vect)
	{
		std::string	res = str + "x : " + std::to_string(vect.x) +
		" , y : " + std::to_string(vect.y) + " , z : " + std::to_string(vect.z) +
		" , w : " + std::to_string(vect.w);

		return res;
	}

	QXvec4	QXvec4::operator+(const QXvec4& vect)
	{
		QXvec4	res;

		res.x = x + vect.x;
		res.y = y + vect.y;
	    res.z = z + vect.z;
		res.w = w + vect.w;

		return res;
	}

	QXvec4	QXvec4::operator-(const QXvec4& vect)
	{
		QXvec4	res;

		res.x = x - vect.x;
		res.y = y - vect.y;
	    res.z = z - vect.z;
		res.w = w - vect.w;

		return res;
	}

	QXvec4	QXvec4::operator-()
	{
		QXvec4	res;

		res.x = -x;
		res.y = -y;
		res.z = -z;
		res.w = -w;

		return res;
	}

	QXvec4	QXvec4::operator*(QXfloat nb)
	{
		QXvec4	res;

		res.x = x * nb;
		res.y = y * nb;
	    res.z = z * nb;
		res.w = w * nb;

		return res;
	}

	QXvec4	operator*(QXfloat nb, const QXvec4& vect)
	{
		QXvec4	res;

		res.x = vect.x * nb;
		res.y = vect.y * nb;
	    res.z = vect.z * nb;
		res.w = vect.w * nb;

		return res;
	}

	QXvec4	QXvec4::operator/(QXfloat nb)
	{
		QXvec4	res;

		res.x = x / nb;
		res.y = y / nb;
	    res.z = z / nb;
		res.w = w / nb;

		return res;
	}

	QXvec4	operator/(QXfloat nb, const QXvec4& vect)
	{
		QXvec4	res;

		res.x = nb / vect.x;
		res.y = nb / vect.y;
		res.z = nb / vect.z;
		res.w = nb / vect.w;

		return res;
	}

	QXvec4&	QXvec4::operator/=(QXfloat nb)
	{
		x /= nb;
		y /= nb;
	    z /= nb;
		w /= nb;

		return *this;
	}

	QXvec4&	QXvec4::operator*=(QXfloat nb)
	{
		x *= nb;
		y *= nb;
	    z *= nb;
		w *= nb;

		return *this;
	}

	QXvec4&	QXvec4::operator+=(const QXvec4& vect)
	{
		x += vect.x;
		y += vect.y;
	    z += vect.z;
		w += vect.w;

		return *this;
	}

	QXvec4&	QXvec4::operator-=(const QXvec4& vect)
	{
		x -= vect.x;
		y -= vect.y;
	    z -= vect.z;
		w -= vect.w;

		return *this;
	}

#pragma endregion

	QXfloat	QXvec4::Length() const
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}

	QXfloat	QXvec4::SqrLength() const
	{
		return x * x + y * y + z * z + w * w;
	}

	QXvec4	QXvec4::Scale(QXfloat nb) const
	{
		QXvec4	res;

		res.x = x * nb;
		res.y = y * nb;
	    res.z = z * nb;
		res.w = w * nb;

		return res;
	}

	QXvec4& QXvec4::Scale(QXfloat nb)
	{
		x = x * nb;
		y = y * nb;
	    z = z * nb;
		w = w * nb;

		return *this;
	}

	QXvec4	QXvec4::Normalize() const
	{
		QXvec4	res;

	    QXfloat size = Length();

	    if (size == 0)
		{
	    	return res;
	    }

		res.x = x / size;
		res.y = y / size;
	    res.z = z / size;
		res.w = w / size;

		return res;
	}

	QXvec4&	QXvec4::Normalize()
	{
		QXfloat	size = Length();

		if (size == 0)
		{
	    	return *this;
		}

		x = x / size;
		y = y / size;
	    z = z / size;
		w = w / size;

		return *this;
	}

	void 	QXvec4::Homogenize()
	{
		if (w == 0)
			return;

		x /= w;
		y /= w;
		z /= w;
	}

	QXbool	QXvec4::operator==(const QXvec4& vect)
	{
		if (SqrLength() == vect.SqrLength())
			return true;
		return false;
	}

	QXbool	QXvec4::operator!=(const QXvec4& vect)
	{
		if (SqrLength() != vect.SqrLength())
			return true;
		return false;
	}

	QXbool	QXvec4::operator<(const QXvec4& vect)
	{
		if (SqrLength() < vect.SqrLength())
			return true;
		return false;
	}

	QXbool	QXvec4::operator<=(const QXvec4& vect)
	{
		if (SqrLength() <= vect.SqrLength())
			return true;
		return false;
	}

	QXbool	QXvec4::operator>(const QXvec4& vect)
	{
		if (SqrLength() > vect.SqrLength())
			return true;
		return false;
	}

	QXbool	QXvec4::operator>=(const QXvec4& vect)
	{
		if (SqrLength() >= vect.SqrLength())
			return true;
		return false;
	}

	std::string	QXvec4::ToString() const
	{
		std::string vec = std::to_string(x) + ", " + std::to_string(y) + ", " +
		std::to_string(z) + ", " + std::to_string(w) + "\n";

		return vec;
	}
}
