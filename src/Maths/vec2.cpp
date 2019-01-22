#include "vec2.h"

#include <math.h>

namespace Maths
{
	Vec2	Vec2::zero {0.f, 0.f};
	Vec2	Vec2::up {0.f, 1.f};
	Vec2	Vec2::down {0.f, -1.f};
	Vec2	Vec2::left {-1.f, 0.f};
	Vec2	Vec2::right {1.f, 0.f};

	/* ************************************* */

	Vec2::Vec2(float posX, float posY):
	x (posX) , y (posY)
	{
	}

	/* ************************************* */

	Vec2::~Vec2()
	{
	}

	/* ************************************* */

	Vec2::Vec2(float pos)
	{
		x = pos;
		y = pos;
	}

	/* ************************************* */

	Vec2::Vec2(const Vec2& vect)
	{
		x = vect.x;
		y = vect.y;
	}

	/* ************************************* */

	Vec2& Vec2::operator=(const Vec2& vect)
	{
		x = vect.x;
		y = vect.y;

		return *this;
	}

	/* ************************************* */

	std::ostream&	operator<<(std::ostream& os, const Vec2& vect)
	{
		os << vect.x << ", " << vect.y << std::endl;

		return os;
	}

	/* ************************************* */

	std::string	operator+(std::string& str, const Vec2& vect)
	{
		std::string	res = str + "x : " + std::to_string(vect.x) +
		" , y : " + std::to_string(vect.y);

		return res;
	}

	/* ************************************* */

	Vec2	Vec2::operator+(const Vec2& vect)
	{
		Vec2	res;

		res.x = x + vect.x;
		res.y = y + vect.y;

		return res;
	}

	/* ************************************* */

	Vec2	Vec2::operator-(const Vec2& vect)
	{
		Vec2	res;

		res.x = x - vect.x;
		res.y = y - vect.y;

		return res;
	}

	/* ************************************* */

	Vec2	Vec2::operator-()
	{
		Vec2	res;

		res.x = -x;
		res.y = -y;

		return res;
	}

	/* ************************************* */

	Vec2	Vec2::operator*(float nb)
	{
		Vec2	res;

		res.x = x * nb;
		res.y = y * nb;

		return res;
	}

	/* ************************************* */

	Vec2	operator*(float nb, const Vec2& vect)
	{
		Vec2	res;

		res.x = vect.x * nb;
		res.y = vect.y * nb;

		return res;
	}

	/* ************************************* */

	Vec2	Vec2::operator/(float nb)
	{
		Vec2	res;

		res.x = x / nb;
		res.y = y / nb;

		return res;
	}

	/* ************************************* */

	Vec2	operator/(float nb, const Vec2& vect)
	{
		Vec2	res;

		res.x = nb / vect.x;
		res.y = nb / vect.y;

		return res;
	}

	/* ************************************* */

	Vec2	Vec2::operator++(int nb)
	{
		nb = 1;

		float	size {length()};

		x *= ((size + nb) / size);
		y *= ((size + nb) / size);

		return *this;
	}

	/* ************************************* */

	Vec2	Vec2::operator--(int nb)
	{
		nb = 1;

		float	size {length()};

		x *= ((size - nb) / size);
		y *= ((size - nb) / size);

		return *this;
	}

	/* ************************************* */

	Vec2&	Vec2::operator/=(float nb)
	{
		x /= nb;
		y /= nb;

		return *this;
	}

	/* ************************************* */

	Vec2&	Vec2::operator*=(float nb)
	{
		x *= nb;
		y *= nb;

		return *this;
	}

	/* ************************************* */

	Vec2&	Vec2::operator+=(const Vec2& vect)
	{
		x += vect.x;
		y += vect.y;

		return *this;
	}

	/* ************************************* */

	Vec2&	Vec2::operator-=(const Vec2& vect)
	{
		x -= vect.x;
		y -= vect.y;

		return *this;
	}

	/* ************************************* */

	float	Vec2::operator,(const Vec2& vect) const
	{
		return vect.x * x + vect.y * y;
	}

	/* ************************************* */

	float	Vec2::operator^(const Vec2& vec) const
	{
		float	res;

		res = x * vec.y - y * vec.x;

		return res;
	}

	/* ************************************* */

	float	Vec2::length() const
	{
		return sqrt(x * x + y * y);
	}

	/* ************************************* */

	Vec2	Vec2::scale(float nb) const
	{
		Vec2	res;

		res.x = x * nb;
		res.y = y * nb;

		return res;
	}

	/* ************************************* */

	Vec2& Vec2::scale(float nb)
	{
		x = x * nb;
		y = y * nb;

		return *this;
	}

	/* ************************************* */

	Vec2	Vec2::normalize() const
	{
		Vec2	res;

	    float size = length();

	    if (size == 0)
		{
			std::cout << "Invalid Vector size" << '\n';
	    	return res;
	    }

		res.x = x / size;
		res.y = y / size;

		return res;
	}

	/* ************************************* */

	Vec2&	Vec2::normalize()
	{
		float	size = length();

		if (size == 0)
		{
			std::cout << "Invalid Vector size" << '\n';
	    	return *this;
		}

		x = x / size;
		y = y / size;

		return *this;
	}

	/* ************************************* */

	bool	Vec2::operator==(const Vec2& vect)
	{
		if (length() == vect.length())
			return true;
		return false;
	}

	/* ************************************* */

	bool	Vec2::operator!=(const Vec2& vect)
	{
		if (length() != vect.length())
			return true;
		return false;
	}

	/* ************************************* */

	bool	Vec2::operator<(const Vec2& vect)
	{
		if (length() < vect.length())
			return true;
		return false;
	}

	/* ************************************* */

	bool	Vec2::operator<=(const Vec2& vect)
	{
		if (length() <= vect.length())
			return true;
		return false;
	}

	/* ************************************* */

	bool	Vec2::operator>(const Vec2& vect)
	{
		if (length() > vect.length())
			return true;
		return false;
	}

	/* ************************************* */

	bool	Vec2::operator>=(const Vec2& vect)
	{
		if (length() >= vect.length())
			return true;
		return false;
	}

	std::string	Vec2::to_string()
	{
		std::string vec = std::to_string(x) + ", " + std::to_string(y) + "\n";

		return vec;
	}
}
