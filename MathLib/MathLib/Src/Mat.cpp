#include "Mat.h"
#include <iostream>
#include <cstring>
#include <math.h>

namespace Math
{
    Mat::Mat(int ln, int col):
		line {ln},
		column {col}
    {
        array = new float[ln * col];

        for (int i = 0; i < ln * col; i++)
        {
            array[i] = 0;
        }
    }

    Mat::Mat(const Vec3& v1, const Vec3& v2, const Vec3& v3):
		line {3},
		column {3}
    {
        array = new float[line * column];

        (*this)[0][0] = v1.x;
		(*this)[0][1] = v1.y;
		(*this)[0][2] = v1.z;

		(*this)[1][0] = v2.x;
		(*this)[1][1] = v2.y;
		(*this)[1][2] = v2.z;

		(*this)[2][0] = v3.x;
		(*this)[2][1] = v3.y;
		(*this)[2][2] = v3.z;
    }


    Mat::Mat(const Mat& mat)
    {
        line = mat.line;
        column = mat.column;
        array = new float[mat.line * mat.column];
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                (*this)[i][j] = mat[i][j];
            }
        }
    }

    Mat::Mat(Mat&& mat):
		line {std::move(mat.line)},
		column {std::move(mat.column)}
    {
        array = new float[line * column];
        for (int i = 0; i < line * column; i++)
        {
            array[i] = mat.array[i];
        }
    }


    Mat::~Mat()
    {
        if (array != nullptr)
            delete[] array;
        array = nullptr;
    }

    float*  Mat::operator[](int i)
    {
        return &array[i * column];
    }

    float*  Mat::operator[](int i) const
    {
        return &array[i * column];
    }

    Mat  Mat::Zero(int m)
    {
        Mat  mat(m, m);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mat[i][j] = 0;
            }
        }
        return mat;
    }

    Mat  Mat::Identity(int m)
    {
        Mat mat(m, m);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == i)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
        }
        return mat;
    }

    Mat  Mat::Transpose() const
    {
        Mat mat(column, line);

        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                float k = array[i * column + j];
                mat[j][i] = k;
            }
        }
        return mat;
    }

    Mat  Mat::operator+(const Mat& mat)
    {
        Mat  res(line, column);

        if (line != mat.line || column != mat.column)
        {
            return res;
        }

        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                res[i][j] = (*this)[i][j] + mat[i][j];
            }
        }

        return res;
    }

    Mat  Mat::operator*(const Mat& mat) const
    {
        Mat res(line, mat.column);
        if (column != mat.line)
        {
            return res;
        }

        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < mat.column; j++)
            {
                for (int k = 0; k < mat.line; k++)
                {
                    res[i][j] += (*this)[i][k] * mat[k][j];
                }
            }
        }

        return res;
    }

    Vec3 Mat::operator*(const Vec3& vect) const
    {
        Mat  v(3, 1);
        v[0][0] = vect.x;
        v[1][0] = vect.y;
        v[2][0] = vect.z;

        Mat  res((*this) * v);
        
        Vec3 v_res(res[0][0], res[1][0], res[2][0]);

        return v_res;
    }

    Vec4 Mat::operator*(const Vec4& vect) const
    {
        Mat  v(4, 4);
        v[0][0] = vect.x;
        v[1][0] = vect.y;
        v[2][0] = vect.z;
        v[3][0] = vect.w;

        Mat  res((*this) * v);
        
        Vec4 v_res(res[0][0], res[1][0], res[2][0], res[3][0]);

        return v_res;
    }

    Mat     operator*(Mat mat, float nb)
    {
        Mat  res(mat.line, mat.column);
        for (int i = 0; i < mat.line; i++)
        {
            for (int j = 0; j < mat.column; j++)
            {
                res[i][j] = mat[i][j] * nb;
            }
        }
        return res;
    }

    Mat&   Mat::operator=(const Mat& mat)
    {
        line = mat.line;
        column = mat.column;

        if (array != nullptr)
            delete array;

        array = new float[line * column];
        
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                (*this)[i][j] = mat[i][j];
            }
        }
        return *this;
    }

    Mat Mat::InverseMat3()
    {
        // computes the inverse of a matrix m
        double det = (*this)[0][0] * ((*this)[1][1] * (*this)[2][2] - (*this)[2][1] * (*this)[1][2]) -
                     (*this)[0][1] * ((*this)[1][0] * (*this)[2][2] - (*this)[1][2] * (*this)[2][0]) +
                     (*this)[0][2] * ((*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0]);

        if (!det)
            return *this;

        double invdet = 1 / det;

        Mat minv(3, 3); // inverse of matrix m
        minv[0][0] = (float)(((*this)[1][1] * (*this)[2][2] - (*this)[2][1] * (*this)[1][2]) * invdet);
        minv[0][1] = (float)(((*this)[0][2] * (*this)[2][1] - (*this)[0][1] * (*this)[2][2]) * invdet);
        minv[0][2] = (float)(((*this)[0][1] * (*this)[1][2] - (*this)[0][2] * (*this)[1][1]) * invdet);
        minv[1][0] = (float)(((*this)[1][2] * (*this)[2][0] - (*this)[1][0] * (*this)[2][2]) * invdet);
        minv[1][1] = (float)(((*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0]) * invdet);
        minv[1][2] = (float)(((*this)[1][0] * (*this)[0][2] - (*this)[0][0] * (*this)[1][2]) * invdet);
        minv[2][0] = (float)(((*this)[1][0] * (*this)[2][1] - (*this)[2][0] * (*this)[1][1]) * invdet);
        minv[2][1] = (float)(((*this)[2][0] * (*this)[0][1] - (*this)[0][0] * (*this)[2][1]) * invdet);
        minv[2][2] = (float)(((*this)[0][0] * (*this)[1][1] - (*this)[1][0] * (*this)[0][1]) * invdet);

        return minv;
    }

    float Mat::Determinant() const
	{
		if (line != column)
			return 0.f;

		if (line == 1 && column == 1)
			return (*this)[0][0];
		else if (line == 2 && column == 2)
			return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
		else if (line == 3 && column == 3)
		{
			return (*this)[0][0] * (*this)[1][1] * (*this)[2][2] +
					(*this)[0][1] * (*this)[1][2] * (*this)[2][0] +
					(*this)[0][2] * (*this)[1][0] * (*this)[2][1] -
					(*this)[0][2] * (*this)[1][1] * (*this)[2][0] -
					(*this)[0][1] * (*this)[1][0] * (*this)[2][2] -
					(*this)[0][0] * (*this)[1][2] * (*this)[2][1];
		}
		else if (line == 4 && column == 4)
		{
			return	(*this)[0][0] * (*this)[1][1] * (*this)[2][2] * (*this)[3][3] -
					(*this)[0][0] * (*this)[1][1] * (*this)[2][3] * (*this)[3][2] -
					(*this)[0][0] * (*this)[1][2] * (*this)[2][1] * (*this)[3][3] +
					(*this)[0][0] * (*this)[1][2] * (*this)[2][3] * (*this)[3][1] +
					(*this)[0][0] * (*this)[1][3] * (*this)[2][1] * (*this)[3][2] -
					(*this)[0][0] * (*this)[1][3] * (*this)[2][2] * (*this)[3][1] -
					(*this)[0][1] * (*this)[1][0] * (*this)[2][2] * (*this)[3][3] +
					(*this)[0][1] * (*this)[1][0] * (*this)[2][3] * (*this)[3][2] +
					(*this)[0][1] * (*this)[1][2] * (*this)[2][0] * (*this)[3][3] -
					(*this)[0][1] * (*this)[1][2] * (*this)[2][3] * (*this)[3][0] -
					(*this)[0][1] * (*this)[1][3] * (*this)[2][0] * (*this)[3][2] +
					(*this)[0][1] * (*this)[1][3] * (*this)[2][2] * (*this)[3][0] +
					(*this)[0][2] * (*this)[1][0] * (*this)[2][1] * (*this)[3][3] -
					(*this)[0][2] * (*this)[1][0] * (*this)[2][3] * (*this)[3][1] -
					(*this)[0][2] * (*this)[1][1] * (*this)[2][0] * (*this)[3][3] +
					(*this)[0][2] * (*this)[1][1] * (*this)[2][3] * (*this)[3][0] +
					(*this)[0][2] * (*this)[1][3] * (*this)[2][0] * (*this)[3][1] -
					(*this)[0][2] * (*this)[1][3] * (*this)[2][1] * (*this)[3][0] -
					(*this)[0][3] * (*this)[1][0] * (*this)[2][1] * (*this)[3][2] +
					(*this)[0][3] * (*this)[1][0] * (*this)[2][2] * (*this)[3][1] +
					(*this)[0][3] * (*this)[1][1] * (*this)[2][0] * (*this)[3][2] -
					(*this)[0][3] * (*this)[1][1] * (*this)[2][2] * (*this)[3][0] -
					(*this)[0][3] * (*this)[1][2] * (*this)[2][0] * (*this)[3][1] +
					(*this)[0][3] * (*this)[1][2] * (*this)[2][1] * (*this)[3][0];
		}
		else
		{
			/*float	result{0};
			int		sign{1};
			Mat		temp(line, column);

			for (unsigned int i = 0; i < line; i++)
			{
				temp = GetCofactor(0, i);
				result += sign * (*this)[0][i] * temp.Determinant();
				sign = -sign;
			}

			return result;*/

			return 0;
		}
	}

	Mat Mat::GetCofactorMatrix() const
	{
		Mat	mat(line, column);

		for (int i = 0 ; i < line ; i++)
			for (int j = 0 ; j < column ; j++)
				mat[i][j] = (float)(pow(-1, i + j) * GetMinor(i + 1, j + 1));

		return mat;
	}

	float Mat::GetCofactor(const unsigned int& l, const unsigned int& c) const
	{
		return (float)(pow(-1, l + c) * GetMinor(l, c));
	}

	float Mat::GetMinor(const unsigned int& l, const unsigned int& c) const
	{
		if (line != column || line < 2)
			return 0.f;

		return GetSubMatrix(l, c).Determinant();
	}

	Mat Mat::GetSubMatrix(unsigned int l, unsigned int c) const
	{
		if (line != column || line <= 2)
			return Mat(0, 0);

		Mat	mat(line - 1, column - 1);

		l--;
		c--;

		for (int i = 0, i2 = 0 ; i < line ; i++)
			if (i != (int)l)
			{
				for (int j = 0, j2 = 0 ; j < column ; j++)
					if (j != (int)c)
					{
						mat[i2][j2] = (*this)[i][j];
						j2++;
					}

				i2++;
			}

		return mat;
	}

	Mat Mat::Inverse() const
	{
		if (line != column)
			return Mat(0, 0);

		Mat inv(line, column);
		float det = Determinant();

		if (line == 2)
		{
			inv[0][0] = (*this)[1][1] * (1 / det);
			inv[0][1] = -(*this)[0][1] * (1 / det);
			inv[1][0] = -(*this)[1][0] * (1 / det);
			inv[1][1] = (*this)[0][0] * (1 / det);
		}
		else
		{
			Mat cofactor(GetCofactorMatrix());

			for (int i = 0; i < line; i++)
				for (int j = 0; j < column; j++)
					inv[i][j] = cofactor[j][i] / det;
		}

		return inv;
	}
}