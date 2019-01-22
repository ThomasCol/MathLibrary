#include "vec3.h"

#include <math.h>

namespace Maths
{
	Vec3	Vec3::zero {0.f, 0.f, 0.f};
	Vec3	Vec3::up {0.f, 1.f, 0.f};
	Vec3	Vec3::down {0.f, -1.f, 0.f};
	Vec3	Vec3::left {-1.f, 0.f, 0.f};
	Vec3	Vec3::right {1.f, 0.f, 0.f};
	Vec3	Vec3::forward {0.f, 0.f, 1.f};
	Vec3	Vec3::backward {0.f, 0.f, -1.f};

	/* ************************************* */

	Vec3::Vec3(float posX, float posY, float posZ):
	x (posX) , y (posY), z (posZ)
	{
	}

	/* ************************************* */

	Vec3::~Vec3()
	{
	}

	/* ************************************* */

	Vec3::Vec3(float pos)
	{
		x = pos;
		y = pos;
		z = pos;
	}

	/* ************************************* */

	Vec3::Vec3(const Vec3& vect)
	{
		x = vect.x;
		y = vect.y;
	    z = vect.z;
	}

	/* ************************************* */

	Vec3& Vec3::operator=(const Vec3& vect)
	{
		x = vect.x;
		y = vect.y;
	    z = vect.z;

		return *this;
	}

	/* ************************************* */

	std::ostream&	operator<<(std::ostream& os, const Vec3& vect)
	{
		os << vect.x << ", " << vect.y << ", " << vect.z << std::endl;

		return os;
	}

	/* ************************************* */

	std::string	operator+(std::string& str, const Vec3& vect)
	{
		std::string	res = str + "x : " + std::to_string(vect.x) +
		" , y : " + std::to_string(vect.y) + " , z : " + std::to_string(vect.z);

		return res;
	}

	/* ************************************* */

	Vec3	Vec3::operator+(const Vec3& vect)
	{
		Vec3	res;

		res.x = x + vect.x;
		res.y = y + vect.y;
	    res.z = z + vect.z;

		return res;
	}

	/* ************************************* */

	Vec3	Vec3::operator-(const Vec3& vect)
	{
		Vec3	res;

		res.x = x - vect.x;
		res.y = y - vect.y;
	    res.z = z - vect.z;

		return res;
	}

	/* ************************************* */

	Vec3	Vec3::operator-()
	{
		Vec3	res;

		res.x = -x;
		res.y = -y;
		res.z = -z;

		return res;
	}

	/* ************************************* */

	Vec3	Vec3::operator*(float nb)
	{
		Vec3	res;

		res.x = x * nb;
		res.y = y * nb;
	    res.z = z * nb;

		return res;
	}

	/* ************************************* */

	Vec3	operator*(float nb, const Vec3& vect)
	{
		Vec3	res;

		res.x = vect.x * nb;
		res.y = vect.y * nb;
	    res.z = vect.z * nb;

		return res;
	}

	/* ************************************* */

	Vec3	Vec3::operator/(float nb)
	{
		Vec3	res;

		res.x = x / nb;
		res.y = y / nb;
	    res.z = z / nb;

		return res;
	}

	/* ************************************* */

	Vec3	operator/(float nb, const Vec3& vect)
	{
		Vec3	res;

		res.x = nb / vect.x;
		res.y = nb / vect.y;
	    res.z = nb / vect.z;

		return res;
	}

	/* ************************************* */

	Vec3	Vec3::operator++(int nb)
	{
		nb = 1;

		float	size {length()};

		x *= ((size + nb) / size);
		y *= ((size + nb) / size);
	    z *= ((size + nb) / size);

		return *this;
	}

	/* ************************************* */

	Vec3	Vec3::operator--(int nb)
	{
		nb = 1;

		float	size {length()};

		x *= ((size - nb) / size);
		y *= ((size - nb) / size);
		z *= ((size - nb) / size);

		return *this;
	}

	/* ************************************* */

	Vec3&	Vec3::operator/=(float nb)
	{
		x /= nb;
		y /= nb;
	    z /= nb;

		return *this;
	}

	/* ************************************* */

	Vec3&	Vec3::operator*=(float nb)
	{
		x *= nb;
		y *= nb;
	    z *= nb;

		return *this;
	}

	/* ************************************* */

	Vec3&	Vec3::operator+=(const Vec3& vect)
	{
		x += vect.x;
		y += vect.y;
	    z += vect.z;

		return *this;
	}

	/* ************************************* */

	Vec3&	Vec3::operator-=(const Vec3& vect)
	{
		x -= vect.x;
		y -= vect.y;
	    z -= vect.z;

		return *this;
	}

	/* ************************************* */

	float	Vec3::operator,(const Vec3& vect) const
	{
		return vect.x * x + vect.y * y + vect.z * z;
	}

	/* ************************************* */

	Vec3	Vec3::operator^(const Vec3& vec) const
	{
		Vec3	res;

		res.x = y * vec.z - z * vec.y;
		res.y = z * vec.x - x * vec.z;
		res.z = x * vec.y - y * vec.x;

		return res;
	}

	/* ************************************* */

	float	Vec3::length() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	/* ************************************* */

	Vec3	Vec3::scale(float nb) const
	{
		Vec3	res;

		res.x = x * nb;
		res.y = y * nb;
	    res.z = z * nb;

		return res;
	}

	/* ************************************* */

	Vec3& Vec3::scale(float nb)
	{
		x = x * nb;
		y = y * nb;
	    z = z * nb;

		return *this;
	}

	/* ************************************* */

	Vec3	Vec3::normalize() const
	{
		Vec3	res;

	    float size = length();

	    if (size == 0)
		{
			std::cout << "Invalid Vector size" << '\n';
	    	return res;
	    }

		res.x = x / size;
		res.y = y / size;
	    res.z = z / size;

		return res;
	}

	/* ************************************* */

	Vec3&	Vec3::normalize()
	{
		float	size = length();

		if (size == 0)
		{
			std::cout << "Invalid Vector size" << '\n';
	    	return *this;
		}

		x = x / size;
		y = y / size;
	    z = z / size;

		return *this;
	}

	/* ************************************* */

	bool	Vec3::operator==(const Vec3& vect)
	{
		if (length() == vect.length())
			return true;
		return false;
	}

	/* ************************************* */

	bool	Vec3::operator!=(const Vec3& vect)
	{
		if (length() != vect.length())
			return true;
		return false;
	}

	/* ************************************* */

	bool	Vec3::operator<(const Vec3& vect)
	{
		if (length() < vect.length())
			return true;
		return false;
	}

	/* ************************************* */

	bool	Vec3::operator<=(const Vec3& vect)
	{
		if (length() <= vect.length())
			return true;
		return false;
	}

	/* ************************************* */

	bool	Vec3::operator>(const Vec3& vect)
	{
		if (length() > vect.length())
			return true;
		return false;
	}

	/* ************************************* */

	bool	Vec3::operator>=(const Vec3& vect)
	{
		if (length() >= vect.length())
			return true;
		return false;
	}

	std::string	Vec3::to_string()
	{
		std::string vec = std::to_string(x) + ", " + std::to_string(y) + ", " +
		std::to_string(z) + "\n";

		return vec;
	}
}
