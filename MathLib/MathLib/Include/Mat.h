#ifndef _MAT_H_
#define _MAT_H_

#include "Vec3.h"
#include "Vec4.h"

namespace Math
{
	/**
	 * @brief QXmat structure
	 * 
	 */
    struct QXmat
    {
		#pragma region Attributes
        QXint       line;
        QXint       column;

        float*    array;
		#pragma endregion Attributes

		#pragma region Constructor/Destructor
		/**
		 * @brief Construct a default QXmat object
		 * 
		 */
		QXmat() = default;

		/**
		 * @brief Construct new QXmat object
		 * 
		 * @param ln int for number of line
		 * @param col int for number of column
		 */
		QXmat(QXint ln = 0, QXint col = 0);

		/**
		 * @brief Construct new QXmat object of size 3
		 * 
		 * @param v1 Vec3 for the first line
		 * @param v2 Vec3 for the second line
		 * @param v3 Vec3 for the third line
		 */
		QXmat(const QXvec3& v1, const QXvec3& v2, const QXvec3& v3);

		/**
		 * @brief Construct new QXmat object
		 * 
		 * @param Mat QXmat to copy
		 */
		QXmat(const QXmat& Mat);

		/**
		 * @brief Construct new QXmat object
		 * 
		 * @param mat QXmat to move
		 */
		QXmat(QXmat&& mat);

		/**
		 * @brief Destroy the QXmat object
		 * 
		 */
        ~QXmat();
		#pragma endregion Constructor/Destructor

		#pragma region Functions
		/**
		 * @brief Compute Determinant
		 * 
		 * @return QXfloat constant value of the matrix determinant
		 */
		QXfloat			Determinant() const;

		/**
		 * @brief Get the matrix cofactor
		 * 
		 * @param l QXint for the number of line in matrix
		 * @param c QXint for the number of column in matrix
		 * @return QXfloat factor value of the matrix
		 */
		QXfloat			GetCofactor(const QXuint& l, const QXuint& c) const;
		QXmat			GetCofactorMatrix() const;
		QXfloat			GetMinor(const QXuint& l, const QXuint& c) const;
		QXmat			GetSubMatrix(QXuint line, QXuint column) const;

		QXmat 			Inverse() const;
		QXmat 			InverseMat3();
		QXmat			Transpose() const;

		#pragma region Operator Functions
        QXfloat*		operator[](QXint i);
        QXfloat*		operator[](QXint i) const;
		QXmat			operator+(const QXmat& Mat);
		QXmat			operator*(const QXmat& Mat)const;
		QXvec3			operator*(const QXvec3& vect) const;
		QXvec4			operator*(const QXvec4& vect) const;
		QXmat&			operator=(const QXmat& Mat);
		#pragma endregion Operator Functions

		#pragma region Static Functions
        static QXmat	Identity(QXint m);
        static QXmat	Zero(QXint m);
		#pragma endregion Static Functions
		#pragma endregion Functions

    };

	QXmat				operator*(QXmat mat, QXfloat nb);
}

#endif //_MAT_H_
