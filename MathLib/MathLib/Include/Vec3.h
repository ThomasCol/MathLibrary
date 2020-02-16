#ifndef __VEC3_H__
#define __VEC3_H__

#include <ostream>

namespace Math
{
	typedef unsigned int uint;

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
		static const Vec3 infinity;

#pragma endregion

#pragma region Constructors

		/**
		 * @brief Construct a new Vec3 object
		 * 
		 * @param x Value for x parameter 0 by default
		 * @param y Value for y parameter 0 by default
		 * @param z Value for z parameter 0 by default
		 */
		Vec3(const float& x = 0.f, const float& y = 0.f, const float& z = 0.f) noexcept;
		
		/**
		 * @brief Construct a new Vec3 object
		 * 
		 * @param vector Vector to copy
		 */
		Vec3(const Vec3& vector) noexcept;

		/**
		 * @brief Construct a new Vec3 object
		 * 
		 * @param vector Vector to move
		 */
		Vec3(Vec3&& vector) noexcept;

		/**
		 * @brief Destroy the Vec3 object
		 */
		~Vec3() = default;

#pragma endregion

#pragma region Operators

		/* Copy and move operator */

		/**
		 * @brief Operator = by copy
		 * 
		 * @param vector Vector to copy
		 * @return Vec3& Reference of current vector
		 */
		Vec3& 	operator=(const Vec3& vector) noexcept;

		/**
		 * @brief Operator = by move
		 * 
		 * @param vector Vector to move
		 * @return Vec3& Reference of current vector
		 */
		Vec3& 	operator=(Vec3&& vector) noexcept;

		/* Mathematics operators */

		/**
		 * @brief Operator for vector addition
		 * 
		 * @param vector Vector to add
		 * @return Vec3& Reference of current vector
		 */
		Vec3& 	operator+=(const Vec3& vector) noexcept;

		/**
		 * @brief Operator for addition
		 * 
		 * @param vector Vector to add
		 * @return Vec3 New vector
		 */
		Vec3 	operator+(const Vec3& vector) const noexcept;

		/**
		 * @brief Operator for substraction
		 * 
		 * @param vector Vector to substract
		 * @return Vec3& Reference of current vector
		 */
		Vec3& 	operator-=(const Vec3& vector) noexcept;

		/**
		 * @brief Operator for substraction
		 * 
		 * @param vector Vector to substract
		 * @return Vec3 New vector
		 */
		Vec3 	operator-(const Vec3& vector) const noexcept;

		/**
		 * @brief Create a new Vec3 as the oposite of the vector
		 * 
		 * @return Vec3 New vector
		 */
		Vec3	operator-() const noexcept;
		
		/**
		 * @brief Operator for division by scalar
		 * 
		 * @param value Scalar to divide
		 * @return Vec3& Reference of current vector
		 */
		Vec3& 	operator/=(float value) noexcept;

		/**
		 * @brief Operator for division by scalar
		 * 
		 * @param value Scalar to divide
		 * @return Vec3 New vector
		 */
		Vec3 	operator/(float value) const noexcept;

		/**
		 * @brief Operator for multiplication by scalar
		 * 
		 * @param value Scalar to multiply
		 * @return Vec3& Reference of current vector
		 */
		Vec3&	operator*=(float value) noexcept;

		/**
		 * @brief Operator for multiplication by scalar
		 * 
		 * @param value Scalar to multiply
		 * @return Vec3 New vector
		 */
		Vec3	operator*(float value) const noexcept;

		/* Binary operators */

		/**
		 * @brief Operator to compare vector length
		 * 
		 * @param vector Vector to compare
		 * @return true Vectors have same length
		 * @return false Vector have different length
		 */
		bool	operator==(const Vec3& vector) const noexcept;

		/**
		 * @brief Operator to compare vector length
		 * 
		 * @param vector Vector to compare
		 * @return true Vectors have different length
		 * @return false Vectors have same length
		 */
		bool	operator!=(const Vec3& vector) const noexcept;

		/**
		 * @brief Operator to compare vector length
		 * 
		 * @param vector Vector to compare
		 * @return true Vector length is strictly inferior to compared vector
		 * @return false Vector length is superior or equal to compared vector
		 */
		bool	operator<(const Vec3& vector) const noexcept;

		/**
		 * @brief Operator to compare vector length
		 * 
		 * @param vector Vector to compare
		 * @return true Vector length is inferior or equal to compared vector
		 * @return false Vector length is strictly superior to compared vector
		 */
		bool	operator<=(const Vec3& vector) const noexcept;

		/**
		 * @brief Operator to compare vector length
		 * 
		 * @param vector Vector to compare
		 * @return true Vector length is strictly superior to compared vector
		 * @return false Vector length is inferior or equal to compared vector
		 */
		bool	operator>(const Vec3& vector) const noexcept;

		/**
		 * @brief Operator to compare vector length
		 * 
		 * @param vector Vector to compare
		 * @return true Vector length is superior or equal to compared vector
		 * @return false Vector length is strictly inferior to compared vector
		 */
		bool	operator>=(const Vec3& vector) const noexcept;

		/* Operator accessor*/

		/**
		 * @brief Operator to access vector values as an array
		 * 
		 * @param idx Index of the array
		 * @return float& Reference of the vector value
		 */
		float	operator[](uint idx) noexcept;

#pragma endregion

#pragma region Functions

		/**
		 * @brief Compute Angle between two vectors
		 * 
		 * @param vector Destination vector 
		 * @return float Angle value in radian
		 */
		float			Angle(const Vec3& vector) const noexcept;

		/**
		 * @brief Cross product between two vectors
		 * 
		 * @param vector Vector to compute cross product
		 * @return Vec3 Vector result of the cross product
		 */
		Vec3			Cross(const Vec3& vector) const noexcept;

		/**
		 * @brief Dot product between two vectors
		 * 
		 * @param vector Vector to compute dot product
		 * @return float Result of the dot product
		 */
		float			Dot(const Vec3& vector) const noexcept;

		/**
		 * @brief Check if two vectors are collinear
		 * 
		 * @param vector Vector to check collinearity
		 * @return true Vectors are collinear
		 * @return false Vectors are not collinear
		 */
		bool			IsCollinear(const Vec3& vector) const noexcept;

		/**
		 * @brief Length (magnitude) of current vector
		 * 
		 * @return float Length value
		 */
		float			Length() const noexcept;

		/**
		 * @brief Normalize vector
		 * 
		 * @return Vec3& Reference of current vector
		 */
		Vec3&			Normalize() noexcept;

		/**
		 * @brief Normalize vector
		 * 
		 * @return Vec3 Vector normalized
		 */
		Vec3			Normalized() const noexcept;

		/**
		 * @brief Multiply vectors values by constant
		 * 
		 * @param value Scaling value
		 * @return Vec3& Reference of current vector
		 */
		Vec3&			Scale(float value) noexcept;

		/**
		 * @brief Multiply vectors values by constant
		 * 
		 * @param value Scaling value
		 * @return Vec3& Scaled vector
		 */
		Vec3			Scale(float value) const noexcept;

		/**
		 * @brief Square length of current vector
		 * 
		 * @return float Square length value
		 */
		float			SqrLength() const noexcept;

		/**
		 * @brief Make a string with vector values
		 * 
		 * @return std::string String with vector
		 */
		std::string		ToString() const noexcept;

#pragma region Static Functions

		/**
		 * @brief Cumpute shortest angle between two vectors
		 * 
		 * @param vector1 Start vector
		 * @param vector2 Destination Vector
		 * @return float Angle value in radian
		 */
        static float	Angle(const Vec3& vector1, const Vec3& vector2) noexcept;

		/**
		 * @brief Compute center of a segment
		 * 
		 * @param pointA First point of the segment
		 * @param pointB Second point of the segment
		 * @return Vec3 Point that reprensent center of the segment
		 */
		static Vec3 	Center(const Vec3& pointA, const Vec3& pointB) noexcept;

		/**
		 * @brief Lerp a vector to an other
		 * 
		 * @param vector1 Current vector
		 * @param vector2 Destination vector
		 * @param ratio Ratio of lerp
		 * @return Vec3 Vector result of lerp
		 */
        static Vec3		Lerp(const Vec3& vector1, const Vec3& vector2, float ratio) noexcept;

		/**
		 * @brief Create a new Vec3 object from two points
		 * 
		 * @param point1 First point
		 * @param point2 Second point
		 * @return Vec3 New vector
		 */
        static Vec3		Vec3FromPoints(const Vec3& point1, const Vec3& point2) noexcept;

#pragma endregion

#pragma endregion
	};

	/**
	 * @brief Operator to print vector
	 * 
	 * @param stream Stream to add the vector
	 * @param vector Vector to add to the stream
	 * @return std::ostream& Reference to the stream
	 */
	std::ostream&	operator<<(std::ostream& stream, const Vec3& vector) noexcept;
}

#endif // __VEC3_H__
