#ifndef _MAT4_H_
#define _MAT4_H_

#include "Vec3.h"
#include "Vec4.h"
#include "Ref3.h"

#include <string>

namespace Math
{
	/**
	 * @brief QXmat4 structure
	 * 
	 */
	struct QXmat4
	{
		#pragma region Attributes
		QXfloat	array[16];
		#pragma endregion Attributes

		#pragma region Constructor/Destructor
		/* constructor */
		QXmat4();
		QXmat4(const QXmat4& mat);

		/* destructor */
		~QXmat4() = default;
		#pragma endregion Constructor/Destructor

		#pragma region Functions
		/* func to get inverse matrix */
		QXmat4 				Inverse() const;

		QXmat4				Transpose() const;

		/* for debug */
		QXstring			ToString() const;

		#pragma region Operator Functions
		/* operator for access to the matrix */
		QXfloat*			operator[](QXint i);
		const QXfloat*		operator[](QXint i) const;

		/* math operators */
		QXmat4				operator+(const QXmat4& mat) const;
		QXmat4				operator*(const QXmat4& mat) const;
		QXmat4&				operator*=(const QXmat4& mat);
		QXvec3				operator*(const QXvec3& vec) const;
		QXvec3				operator*(const QXvec4& vec) const;
		#pragma endregion Operator Functions

		#pragma region Static Functions
		static QXmat4		CreateScaleMatrix(const QXvec3& scale);

		static QXmat4		CreateTranslationMatrix(const QXvec3& trans);

		static QXmat4		CreateRotationMatrix(const QXvec3& axis, const QXfloat& angle);

		static QXmat4		CreateXRotationMatrix(const QXfloat angle);
		static QXmat4		CreateYRotationMatrix(const QXfloat angle);
		static QXmat4		CreateZRotationMatrix(const QXfloat angle);
		static QXmat4		CreateFixedAngleEulerRotationMatrix(const QXvec3& rotate);

		static QXmat4		CreateTRSMatrix(const QXvec3& trans, const QXvec3& rotate,
									const QXvec3& scale);
		/* ============================= */

		static QXmat4		CreateProjectionMatrix(QXint width, QXint height, QXfloat near,
													QXfloat far, QXfloat fov);
		static QXmat4		CreateOrthographicProjectionMatrix(QXint width, QXint height, QXfloat near, QXfloat far);

		static QXmat4		CreateLookAtMatrix(QXvec3 position, QXvec3 target, QXvec3 up, QXvec3 Scale);

		static QXmat4		Identity();
		#pragma endregion Static Functions
		#pragma endregion Functions
	};
}

#endif //_MAT4_H_
