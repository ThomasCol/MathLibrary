#ifndef _MAT_H_
#define _MAT_H_

#include "Vec3.h"
#include "Vec4.h"

namespace Math
{
    struct Mat
    {
        int       line;
        int       column;

        float*    array;

        Mat() = default;
        Mat(int ln = 0, int col = 0);
        Mat(const Vec3& v1, const Vec3& v2, const Vec3& v3);
        Mat(const Mat& Mat);
        Mat(Mat&& mat);
        ~Mat();

        float*			operator[](int i);
        float*			operator[](int i) const;
        Mat				operator+(const Mat& Mat);
        Mat				operator*(const Mat& Mat)const;
        Vec3			operator*(const Vec3& vect) const;
        Vec4			operator*(const Vec4& vect) const;
        Mat&			operator=(const Mat& Mat);

        static Mat		Zero(int m);
        static Mat		Identity(int m);

        Mat				Transpose() const;
        float			Determinant() const;
		float			GetMinor(const unsigned int& l, const unsigned int& c) const;
	    float			GetCofactor(const unsigned int& l, const unsigned int& c) const;
	    Mat				GetCofactorMatrix() const;
        Mat				GetSubMatrix(unsigned int line, unsigned int column) const;

		Mat 			Inverse() const;
        Mat 			InverseMat3();
    };

    Mat					operator*(Mat mat, float nb);
}

#endif //_MAT_H_
