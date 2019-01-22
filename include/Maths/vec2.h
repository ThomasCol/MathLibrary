#ifndef _VEC2_H_
#define _VEC2_H_

#include <iostream>
#include <string>

namespace Maths
{
	struct Vec2
	{
		float	x;
		float	y;

		/* constructor */
		Vec2(float poX, float posY);
		Vec2(float pos = 0);
		Vec2(const Vec2& vec);

		/* destructor */
		~Vec2();

		/* direction vectors */
		static Vec2	zero;
		static Vec2	up;
		static Vec2	down;
		static Vec2	left;
		static Vec2	right;

		/* math operators */
		/* ============== */
		Vec2&		operator=(const Vec2&);
		Vec2		operator++(int);
		Vec2		operator--(int);
		/* dot product */
		float		operator,(const Vec2& vect) const;
		/* vectorial product */
		float		operator^(const Vec2& vect) const;

		Vec2&		operator/=(float nb);
		Vec2&		operator*=(float nb);
		Vec2&		operator+=(const Vec2& vect);
		Vec2&		operator-=(const Vec2& vect);

		Vec2		operator+(const Vec2& vect);

		Vec2		operator-(const Vec2& vect);
		Vec2		operator-();

		Vec2		operator*(float nb);

		Vec2		operator/(float nb);
		/* ============== */

		/* binary operators */
		/* ================ */
		bool		operator==(const Vec2& vect);
		bool		operator!=(const Vec2& vect);
		bool		operator<(const Vec2& vect);
		bool		operator<=(const Vec2& vect);
		bool		operator>(const Vec2& vect);
		bool		operator>=(const Vec2& vect);
		/* ================ */

		/* vector length */
		float		length() const;

		/* change current vector value */
		Vec2		add(const Vec2& vect) const;
		Vec2&		add(const Vec2& vect);

		Vec2&		scale(float nb);
		Vec2		scale(float nb) const;

		Vec2		normalize() const;
		Vec2&		normalize();

		/* to debug */
		std::string	to_string();
	};

	/* operators to display a vector */
	std::ostream&	operator<<(std::ostream& os, const Vec2& vect);

	std::string		operator+(std::string& str, const Vec2& vect);

	/* multiplication and division */
	Vec2			operator*(float nb, const Vec2& vect);
	Vec2			operator/(float nb, const Vec2& vect);
}

#endif //_VEC2_H_
