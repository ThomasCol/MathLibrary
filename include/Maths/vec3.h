#ifndef _VEC3_H_
#define _VEC3_H_

#include <iostream>
#include <string>

namespace Maths
{
	struct Vec3
	{
		float	x;
		float	y;
		float	z;

		/* constructor */
		Vec3(float poX, float posY, float posZ);
		Vec3(float pos = 0);
		Vec3(const Vec3& vec);

		/* destructor */
		~Vec3();

		/* direction vectors */
		static Vec3	zero;
		static Vec3	up;
		static Vec3	down;
		static Vec3	left;
		static Vec3	right;
		static Vec3	forward;
		static Vec3	backward;

		/* math operators */
		/* ============== */
		Vec3&		operator=(const Vec3&);
		Vec3		operator++(int);
		Vec3		operator--(int);
		/* dot product */
		float		operator,(const Vec3& vect) const;
		/* vectorial product */
		Vec3		operator^(const Vec3& v) const;

		Vec3&		operator/=(float nb);
		Vec3&		operator*=(float nb);
		Vec3&		operator+=(const Vec3& vect);
		Vec3&		operator-=(const Vec3& vect);

		Vec3		operator+(const Vec3& vect);

		Vec3		operator-(const Vec3& vect);
		Vec3		operator-();

		Vec3		operator*(float nb);

		Vec3		operator/(float nb);
		/* ============== */

		/* binary operators */
		/* ================ */
		bool		operator==(const Vec3& vect);
		bool		operator!=(const Vec3& vect);
		bool		operator<(const Vec3& vect);
		bool		operator<=(const Vec3& vect);
		bool		operator>(const Vec3& vect);
		bool		operator>=(const Vec3& vect);
		/* ================ */

		/* vector length */
		float		length() const;

		/* change current vector value */
		Vec3		add(const Vec3& vect) const;
		Vec3&		add(const Vec3& vect);

		Vec3&		scale(float nb);
		Vec3		scale(float nb) const;

		Vec3		normalize() const;
		Vec3&		normalize();

		/* to debug */
		std::string	to_string();
	};

	/* operators to display a vector */
	std::ostream&	operator<<(std::ostream& os, const Vec3& vect);

	std::string		operator+(std::string& str, const Vec3& vect);

	/* multiplication and division */
	Vec3			operator*(float nb, const Vec3& vect);
	Vec3			operator/(float nb, const Vec3& vect);
}

#endif //_VEC3_H_
