#ifndef _MAT4_H_
#define _MAT4_H_

#include "vec3.h"
#include "vec4.h"

#include <string>

namespace Maths
{
	struct Mat4
	{
		float*	array;

		/* constructor */
		Mat4();
		Mat4(const Mat4& mat);

		/* destructor */
		~Mat4();

		static Mat4	identity();

		/* operator for access to the matrix */
		float*	operator[](int i);
		float*	operator[](int i) const;

		/* math operators */
		Mat4	operator+(const Mat4& mat) const;
		Mat4	operator*(const Mat4& mat) const;
		Mat4&	operator*=(const Mat4& mat);
		Vec4	operator*(const Vec4& vec) const;
		Mat4&	operator=(const Mat4& mat);

		Mat4			transpose() const;

		/* for debug */
		std::string		to_string() const;

		/* function to create TRS matrix */
		/* ============================= */
		static Mat4		createScaleMatrix(const Vec3& scale);

		static Mat4		createTranslationMatrix(const Vec3& trans);

		static Mat4		createXRotationMatrix(const float angle);
		static Mat4		createYRotationMatrix(const float angle);
		static Mat4		createZRotationMatrix(const float angle);
		static Mat4		createFixedAngleEulerRotationMatrix(const Vec3& rotate);

		static Mat4		createTRSMatrix(const Vec3& trans, const Vec3& rotate,
									const Vec3& scale);
		/* ============================= */

		static Mat4		createProjectionMatrix(int width, int height, float near,
		                                        	float far, float fov);

		/* func to get inverse matrix */
		float			determinant();
		float			getMinor();
		float			getCofactor();
		Mat4			getCofactorMatrix();

		Mat4			inverse();


	};
}

#endif //_MAT4_H_
