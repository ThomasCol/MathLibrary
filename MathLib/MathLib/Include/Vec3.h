#ifndef __VEC3_H__
#define __VEC3_H__

#include <ostream>

namespace Math
{
	/**
	 * @brief Vector3 structure
	 * 
	 */
	struct Vec3
	{
#pragma region Attributes

		union
		{
			struct { float x, y, z; };
			struct { float r, g, b; };
			float	e[3];
		};

		static const Vec3 zero;
		static const Vec3 up;
		static const Vec3 down;
		static const Vec3 right;
		static const Vec3 left;
		static const Vec3 forward;
		static const Vec3 backward;

#pragma endregion

#pragma region Constructors

		/**
		 * @brief Construct a new Vec 3 object
		 * 
		 * @param x Value for x parameter 0 by default
		 * @param y Value for y parameter 0 by default
		 * @param z Value for z parameter 0 by default
		 */
		Vec3(const float& x = 0.f, const float& y = 0.f, const float& z = 0.f) noexcept;
		
		/**
		 * @brief Construct a new Vec 3 object
		 * 
		 * @param vector Vector to copy
		 */
		Vec3(const Vec3& vector) noexcept;

		/**
		 * @brief Construct a new Vec 3 object
		 * 
		 * @param vector Vector to move
		 */
		Vec3(Vec3&& vector) noexcept;

		/**
		 * @brief Destroy the Vec 3 object
		 */
		~Vec3() = default;

#pragma endregion

#pragma region Operators

		/* Copy and move operator */

		/**
		 * @brief operator = by copy
		 * 
		 * @param vector Vector to copy
		 * @return Vec3& Reference of current vector
		 */
		Vec3& operator=(const Vec3& vector);

		/**
		 * @brief operator = by move
		 * 
		 * @param vector Vector to move
		 * @return Vec3& Reference of current vector
		 */
		Vec3& operator=(Vec3&& vector);

		/* Mathematics operators */

		/**
		 * @brief Operator for vector addition
		 * 
		 * @param vector Vector to add
		 * @return Vec3& Reference of current vector
		 */
		Vec3&		operator+=(const Vec3& vector);

		/**
		 * @brief Operator for addition
		 * 
		 * @param vector Vector to add
		 * @return Vec3& Reference of current vector
		 */
		Vec3&		operator+(const Vec3& vector) const;

		/**
		 * @brief Operator for substraction
		 * 
		 * @param vector Vector to substract
		 * @return Vec3& Reference of current vector
		 */
		Vec3&		operator-=(const Vec3& vector);

		/**
		 * @brief Operator for substraction
		 * 
		 * @param vector Vector to substract
		 * @return Vec3& Reference of current vector
		 */
		Vec3&		operator-(const Vec3& vector);
		
		/**
		 * @brief Operator for division by scalar
		 * 
		 * @param value Scalar to divide
		 * @return Vec3& Reference of current vector
		 */
		Vec3&		operator/=(const float& value);

		/**
		 * @brief Operator for division by scalar
		 * 
		 * @param value Scalar to divide
		 * @return Vec3& Reference of current vector
		 */
		Vec3&		operator/(const float& value) const;

		/**
		 * @brief Operator for multiplication by scalar
		 * 
		 * @param value Scalar to multiply
		 * @return Vec3& Reference of current vector
		 */
		Vec3&		operator*=(const float& value);

		/**
		 * @brief Operator for multiplication by scalar
		 * 
		 * @param value Scalar to multiply
		 * @return Vec3& Reference of current vector
		 */
		Vec3&		operator*(const float& value) const;

#pragma endregion
	};

	/**
	 * @brief Operator to print vector
	 * 
	 * @param stream Stream to add the vector
	 * @param vector Vector to add
	 * @return std::ostream& Reference to the stream
	 */
	std::ostream&	operator<<(std::ostream& stream, const Vec3& vector);
}

#endif // __VEC3_H__
