#pragma once

#include "Vec3.h"
#include "Mat.h"
#include "Mat4.h"

namespace Math
{
	/**
	 * @brief Quaternion structure
	 * 
	 */
	struct	QXquaternion
	{
		#pragma region Attributes
		QXfloat	w{ 0.f };
		QXvec3	v = QXvec3(0, 0, 0);
		#pragma endregion
	
		#pragma region Constructors/Destructor
		/**
		 * @brief Construct a default Quaternion object
		 * 
		 */
		QXquaternion() noexcept;

		/**
		 * @brief Construct a new Quaternion object
		 * 
		 * @param q Quaternion to copy
		 */
		QXquaternion(const QXquaternion& q) noexcept;

		/**
		 * @brief Construct a new Quaternion object
		 *
		 * @param q Quaternion to move 
		 */
		QXquaternion(const QXquaternion&& q) noexcept;

		/**
		 * @brief Construct a new Quaternion object
		 * 
		 * @param vw Value of angle in radian
		 * @param vQ Vector of rotation
		 */
		QXquaternion(QXfloat vw, QXvec3 vQ) noexcept;

		/**
		 * @brief Construct a new Quaternion object
		 * 
		 * @param vw Value of angle in radian
		 * @param vx Value for x parameter of Vector
		 * @param vy Value for y parameter of Vector
		 * @param vz Value for z parameter of Vector
		 */
		QXquaternion(QXfloat vw, QXfloat vx, QXfloat vy, QXfloat vz) noexcept;

		/**
		 * @brief Destroy the Quaternion object
		 * 
		 */
		~QXquaternion() = default;
		#pragma endregion Constructors/Destructor

		#pragma region Functions
		/**
		 * @brief Add two Quaternion object
		 * 
		 * @param q Quaternion to add
		 * @return Reference of new QXquaternion result object
		 */
		QXquaternion&		AddQuaternion(QXquaternion& q);

		/**
		 * @brief Conjugate of Quaternion object
		 * 
		 * @return Reference of new QXquaternion result object
		 */
		QXquaternion&		ConjugateQuaternion();

		/**
		 * @brief Convert Quaternion object into Mat4 object
		 * 
		 * @return New QXmat4 from the current Quaternion
		 */
		QXmat4				ConvertQuaternionToMat();

		/**
		 * @brief Dot product between two Quaternion object
		 * 
		 * @param q Quaternion to compute dot product
		 * @return QXfloat float result of dot product
		 */
		float				DotProductQuaternion(QXquaternion& q);

		/**
		 * @brief Inverse of the current Quaternion object
		 * 
		 * @return Reference QXquaternion of the current Quaternion
		 */
		QXquaternion&		InverseQuaternion();

		/**
		 * @brief Multiply Quaternion object with QXfloat
		 * 
		 * @param s float scale value for multiplication
		 * @return New reference QXquaternion result of multiplication 
		 */
		QXquaternion&		MultQuaternion(QXfloat s);

		/**
		 * @brief Multiply two Quaternion object
		 * 
		 * @param q Quaternion for multiplication
		 * @return New reference QXquaternion result of multiplication
		 */
		QXquaternion&		MultQuaternion(QXquaternion& q);

		/**
		 * @brief Negate of the current Quaternion object
		 * 
		 */
		void				NegateQuaternion();

		/**
		 * @brief Normalize Quaternion object
		 * 
		 * @return New reference QXquaternion result of normalize
		 */
		QXquaternion&		NormalizeQuaternion();

		/**
		 * @brief Nullify the current Quaternion object
		 * 
		 */
		void				NullQuaternion();

		/**
		 * @brief Length of the current Quaternion object
		 * 
		 * @return QXfloat length of the current Quaternion
		 */
		float				QuaternionLength();

		/**
		 * @brief Negate Quaternion object
		 * 
		 * @return New reference QXquaternion result of negate Quaternion
		 */
		QXquaternion&		ReturnNegateQuaternion();

		/**
		 * @brief Square root of Quaternion object
		 * 
		 * @return QXfloat of the square root of current Quaternion
		 */
		float				SqrtRootQuaternion();

		/**
		 * @brief Slerp of Quaternion object
		 * 
		 * @param q Quaternion destination
		 * @param t float ratio
		 * @return reference of the current QXquaternion slerp normalize
		 */
		QXquaternion&		SlerpQuaternion(QXquaternion& q, QXfloat t);

		/**
		 * @brief Substract two Quaternion object
		 * 
		 * @param q Quaternion for substraction
		 * @return New reference QXquaternion result of substraction of two quaternion
		 */
		QXquaternion&		SubQuaternion(QXquaternion& q);

		/**
		 * @brief String of Quaternion object
		 * 
		 * @return String quaternion of the current quaternion
		 */
		QXstring			ToString() const;
		#pragma region Static Functions

		/**
		 * @brief Convert Quaternion object into Mat4 object
		 * 
		 * @param q Quaternion for conversion
		 * @return New QXmat4 from the Quaternion
		 */
		static QXmat4			ConvertQuaternionToMat(QXquaternion& q);

		/**
		 * @brief Convert Mat4 object into Quaternion object
		 * 
		 * @param m Mat4 for conversion
		 * @return New Quaternion from the Mat4
		 */
		static QXquaternion	ConvertMatToQuaternion(QXmat4 m);

		/**
		 * @brief Convert Euler angle into Quaternion object
		 * 
		 * @param euler Vec3 for conversion
		 * @return New Quaternion from Vec3
		 */
		static QXquaternion	ConvertEulerAngleToQuaternion(QXvec3& euler);

		/**
		 * @brief Slerp of Quaternion object
		 * 
		 * @param q Quaternion begin
		 * @param q Quaternion destination
		 * @param t float ratio
		 * @return QXquaternion slerp normalize
		 */
		static QXquaternion	SlerpQuaternion(QXquaternion q1, QXquaternion q2, QXfloat t);
		#pragma endregion Static Functions
		#pragma region Operator Functions

		/**
		 * @brief Operator = by copy
		 * 
		 * @param q Quaternion to copy
		 * @return Reference QXquaternion of current Quaternion
		 */
		QXquaternion&		operator=(const QXquaternion& q);

		/**
		 * @brief Operator * multiplication
		 * 
		 * @param s float scale value for multiplication
		 * @return New reference QXquaternion result of multiplication
		 */
		QXquaternion&		operator*(QXfloat s);

		/**
		 * @brief Operator * multiplication
		 * 
		 * @param q Quaternion for multiplication
		 * @return New reference QXquaternion result of multiplication
		 */
		QXquaternion&		operator*(const QXquaternion& q);

		/**
		 * @brief Operator + addition
		 * 
		 * @param q QXquaternion for addition
		 * @return Reference of new QXquaternion result object
		 */
		QXquaternion&		operator+(const QXquaternion& q);

		/**
		 * @brief Operator - substaction
		 * 
		 * @param q QXquaternion for substraction
		 * @return String quaternion of the current quaternion
		 */
		QXquaternion&		operator-(const QXquaternion& q);
		#pragma endregion Operator Functions
		#pragma endregion Functions


	};
}