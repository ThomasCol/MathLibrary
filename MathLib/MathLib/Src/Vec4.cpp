#include "Vec4.h"

#include <math.h>

namespace Math
{
	Vec4	Vec4::zero {0.f, 0.f, 0.f, 0.f};
	Vec4	Vec4::up {0.f, 1.f, 0.f, 0.f};
	Vec4	Vec4::down {0.f, -1.f, 0.f, 0.f};
	Vec4	Vec4::left {-1.f, 0.f, 0.f, 0.f};
	Vec4	Vec4::right {1.f, 0.f, 0.f, 0.f};
	Vec4	Vec4::forward {0.0f, 0.0f, 1.0f, 0.f};
	Vec4	Vec4::backward {0.0f, 0.0f, -1.0f, 0.f};

	Vec4::Vec4(float posX, float posY, float posZ, float posW):
		x (posX),
		y (posY),
		z (posZ),
		w (posW)
	{
	}

	Vec4::~Vec4()
	{
	}

	Vec4::Vec4(float pos)
	{
		x = pos;
		y = pos;
		z = pos;
		w = pos;
	}

	Vec4::Vec4(const Vec3& vec, float posW)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
		w = posW;
	}

	Vec4::Vec4(const Vec4& vect)
	{
		x = vect.x;
		y = vect.y;
	    z = vect.z;
		w = vect.w;
	}

	Vec4& Vec4::operator=(const Vec4& vect)
	{
		x = vect.x;
		y = vect.y;
	    z = vect.z;
		w = vect.w;

		return *this;
	}

	std::ostream&	operator<<(std::ostream& os, const Vec4& vect)
	{
		os << vect.x << ", " << vect.y << ", " << vect.z <<
								", " << vect.w << std::endl;

		return os;
	}

	std::string	operator+(std::string& str, const Vec4& vect)
	{
		std::string	res = str + "x : " + std::to_string(vect.x) +
		" , y : " + std::to_string(vect.y) + " , z : " + std::to_string(vect.z) +
		" , w : " + std::to_string(vect.w);

		return res;
	}

	Vec4	Vec4::operator+(const Vec4& vect)
	{
		Vec4	res;

		res.x = x + vect.x;
		res.y = y + vect.y;
	    res.z = z + vect.z;
		res.w = w + vect.w;

		return res;
	}

	Vec4	Vec4::operator-(const Vec4& vect)
	{
		Vec4	res;

		res.x = x - vect.x;
		res.y = y - vect.y;
	    res.z = z - vect.z;
		res.w = w - vect.w;

		return res;
	}

	Vec4	Vec4::operator-()
	{
		Vec4	res;

		res.x = -x;
		res.y = -y;
		res.z = -z;
		res.w = -w;

		return res;
	}

	Vec4	Vec4::operator*(float nb)
	{
		Vec4	res;

		res.x = x * nb;
		res.y = y * nb;
	    res.z = z * nb;
		res.w = w * nb;

		return res;
	}

	Vec4	operator*(float nb, const Vec4& vect)
	{
		Vec4	res;

		res.x = vect.x * nb;
		res.y = vect.y * nb;
	    res.z = vect.z * nb;
		res.w = vect.w * nb;

		return res;
	}

	Vec4	Vec4::operator/(float nb)
	{
		Vec4	res;

		res.x = x / nb;
		res.y = y / nb;
	    res.z = z / nb;
		res.w = w / nb;

		return res;
	}

	Vec4	operator/(float nb, const Vec4& vect)
	{
		Vec4	res;

		res.x = nb / vect.x;
		res.y = nb / vect.y;
	    res.z = nb / vect.z;
		res.w = nb / vect.w;

		return res;
	}

	Vec4	Vec4::operator++(int nb)
	{
		nb = 1;

		float	size {Length()};

		x *= ((size + nb) / size);
		y *= ((size + nb) / size);
	    z *= ((size + nb) / size);
		w *= ((size + nb) / size);

		return *this;
	}

	Vec4	Vec4::operator--(int nb)
	{
		nb = 1;

		float	size {Length()};

		x *= ((size - nb) / size);
		y *= ((size - nb) / size);
		z *= ((size - nb) / size);
		w *= ((size - nb) / size);

		return *this;
	}

	Vec4&	Vec4::operator/=(float nb)
	{
		x /= nb;
		y /= nb;
	    z /= nb;
		w /= nb;

		return *this;
	}

	Vec4&	Vec4::operator*=(float nb)
	{
		x *= nb;
		y *= nb;
	    z *= nb;
		w *= nb;

		return *this;
	}

	Vec4&	Vec4::operator+=(const Vec4& vect)
	{
		x += vect.x;
		y += vect.y;
	    z += vect.z;
		w += vect.w;

		return *this;
	}

	Vec4&	Vec4::operator-=(const Vec4& vect)
	{
		x -= vect.x;
		y -= vect.y;
	    z -= vect.z;
		w -= vect.w;

		return *this;
	}

	float	Vec4::operator,(const Vec4& vect) const
	{
		return vect.x * x + vect.y * y + vect.z * z;
	}

	Vec4	Vec4::operator^(const Vec4& vec) const
	{
		Vec4	res;

		res.x = y * vec.z - z * vec.y;
		res.y = z * vec.x - x * vec.z;
		res.z = x * vec.y - y * vec.x;

		return res;
	}

	float	Vec4::Length() const
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}

	float	Vec4::SqrLength() const
	{
		return x * x + y * y + z * z + w * w;
	}

	Vec4	Vec4::Scale(float nb) const
	{
		Vec4	res;

		res.x = x * nb;
		res.y = y * nb;
	    res.z = z * nb;
		res.w = w * nb;

		return res;
	}

	Vec4& Vec4::Scale(float nb)
	{
		x = x * nb;
		y = y * nb;
	    z = z * nb;
		w = w * nb;

		return *this;
	}

	Vec4	Vec4::Normalize() const
	{
		Vec4	res;

	    float size = Length();

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

	Vec4&	Vec4::Normalize()
	{
		float	size = Length();

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

	void 	Vec4::Homogenize()
	{
		if (w == 0)
			return;

		x /= w;
		y /= w;
		z /= w;
	}

	bool	Vec4::operator==(const Vec4& vect)
	{
		if (SqrLength() == vect.SqrLength())
			return true;
		return false;
	}

	bool	Vec4::operator!=(const Vec4& vect)
	{
		if (SqrLength() != vect.SqrLength())
			return true;
		return false;
	}

	bool	Vec4::operator<(const Vec4& vect)
	{
		if (SqrLength() < vect.SqrLength())
			return true;
		return false;
	}

	bool	Vec4::operator<=(const Vec4& vect)
	{
		if (SqrLength() <= vect.SqrLength())
			return true;
		return false;
	}

	bool	Vec4::operator>(const Vec4& vect)
	{
		if (SqrLength() > vect.SqrLength())
			return true;
		return false;
	}

	bool	Vec4::operator>=(const Vec4& vect)
	{
		if (SqrLength() >= vect.SqrLength())
			return true;
		return false;
	}

	std::string	Vec4::ToString() const
	{
		std::string vec = std::to_string(x) + ", " + std::to_string(y) + ", " +
		std::to_string(z) + ", " + std::to_string(w) + "\n";

		return vec;
	}
}
