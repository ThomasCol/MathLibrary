#ifndef _MAT4_H_
#define _MAT4_H_

#include "Vec3.h"
#include "Vec4.h"
#include "Ref3.h"

#include <string>

namespace Math
{
	struct Mat4
	{
		float	array[16];

		/* constructor */
		Mat4();
		Mat4(const Mat4& mat);

		/* destructor */
		~Mat4() = default;

		static Mat4		Identity();

		/* operator for access to the matrix */
		float*			operator[](int i);
		const float*	operator[](int i) const;

		/* math operators */
		Mat4			operator+(const Mat4& mat) const;
		Mat4			operator*(const Mat4& mat) const;
		Mat4&			operator*=(const Mat4& mat);
		Vec3			operator*(const Vec3& vec) const;
		Vec3			operator*(const Vec4& vec) const;

		Mat4			Transpose() const;

		/* for debug */
		std::string		ToString() const;


		static Mat4		CreateScaleMatrix(const Vec3& scale);

		static Mat4		CreateTranslationMatrix(const Vec3& trans);

		static Mat4		CreateRotationMatrix(const Vec3& axis, const float& angle);

		static Mat4		CreateXRotationMatrix(const float angle);
		static Mat4		CreateYRotationMatrix(const float angle);
		static Mat4		CreateZRotationMatrix(const float angle);
		static Mat4		CreateFixedAngleEulerRotationMatrix(const QXvec3& rotate);

		static Mat4		CreateTRSMatrix(const Vec3& trans, const Vec3& rotate,
									const Vec3& scale);
		/* ============================= */

		static Mat4		CreateProjectionMatrix(int width, int height, float near,
												float far, float fov);
		static Mat4		CreateOrthographicProjectionMatrix(int width, int height, float near, float far);

		static Mat4		CreateLookAtMatrix(Vec3 position, Vec3 target, Vec3 up, Vec3 Scale);

		/* func to get inverse matrix */
		Mat4 			Inverse() const;


	};
}

#endif //_MAT4_H_
