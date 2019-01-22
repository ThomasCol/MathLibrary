#include "mat4.h"
#include "Debug.h"

#include <math.h>

namespace Maths
{
	Mat4::Mat4()
	{
		array = new float[16];

		for (int i = 0; i < 16; i++)
		{
			array[i] = 0;
		}
		LOG(INFO, "Creating Mat4");
	}

	Mat4::Mat4(const Mat4& mat)
	{
		array = new float[16];

		for (int i = 0; i < 16; i++)
		{
			array[i] = mat.array[i];
		}
		LOG(INFO, "Creating Mat4");
	}

	Mat4::~Mat4()
	{
		delete[] array;
		LOG(INFO, "Destroy Mat4");
	}

	float*	Mat4::operator[](int i)
	{
		return &array[i * 4];
	}

	float*  Mat4::operator[](int i) const
	{
	    return &array[i * 4];
	}

	Mat4	Mat4::identity()
	{
		Mat4	identity;

		identity[0][0] = 1;
		identity[1][1] = 1;
		identity[2][2] = 1;
		identity[3][3] = 1;

		return identity;
	}

	Mat4	Mat4::operator+(const Mat4& mat) const
	{
		Mat4	res;

	    for (int i = 0; i < 16; i++)
	    {
			res.array[i] = mat.array[i] + array[i];
	    }

	    return res;
	}

	Mat4	Mat4::operator*(const Mat4& mat) const
	{
		Mat4	res;

	    for (int i = 0; i < 4; i++)
	    {
	        for (int j = 0; j < 4; j++)
	        {
	            for (int k = 0; k < 4; k++)
	            {
	                res[i][j] += (*this)[i][k] * mat[k][j];
	            }
	        }
	    }

	    return res;
	}

	Vec4	Mat4::operator*(const Vec4& vec) const
	{
	    Mat4  matVec;
	    matVec[0][0] = vec.x;
	    matVec[1][0] = vec.y;
	    matVec[2][0] = vec.z;
	    matVec[3][0] = vec.w;

	    Mat4  res((*this) * matVec);

	    Vec4 vecRes(res[0][0], res[1][0], res[2][0], res[3][0]);

	    return vecRes;
	}

	Mat4&	Mat4::operator*=(const Mat4& mat)
	{
		Mat4	res;

	    for (int i = 0; i < 4; i++)
	    {
	        for (int j = 0; j < 4; j++)
	        {
	            for (int k = 0; k < 4; k++)
	            {
	                res[i][j] += (*this)[i][k] * mat[k][j];
	            }
	        }
	    }

		(*this) = res;

	    return *this;
	}

	Mat4&	Mat4::operator=(const Mat4& mat)
	{
	    for (int i = 0; i < 16; i++)
	    {
			array[i] = mat.array[i];
	    }

	    return *this;
	}

	Mat4	Mat4::transpose() const
	{
		Mat4	res;
		float	tmp;

	    for (int i = 0; i < 4; i++)
	    {
	        for (int j = 0; j < 4; j++)
	        {
	            tmp = array[i * 4 + j];
	            res[j][i] = tmp;
	        }
	    }

	    return res;
	}

	std::string	Mat4::to_string() const
	{
		std::string	mat;
		for (int i = 0; i < 4; i++)
	    {
	        for (int j = 0; j < 4; j++)
	        {
	            mat = mat + std::to_string(array[i * 4 + j]) + " ";
	        }
	        mat += "\n\t  ";
	    }

		return mat;
	}

	Mat4	Mat4::createScaleMatrix(const Vec3& scale)
	{
		Mat4  scaleMatrix;

	    scaleMatrix[0][0] = scale.x;
	    scaleMatrix[1][1] = scale.y;
	    scaleMatrix[2][2] = scale.z;
	    scaleMatrix[3][3] = 1;

	    return scaleMatrix;
	}

	Mat4	Mat4::createTranslationMatrix(const Vec3& trans)
	{
		Mat4	transMatrix;

		transMatrix[0][0] = 1;
		transMatrix[0][3] = trans.x;
		transMatrix[1][1] = 1;
		transMatrix[1][3] = trans.y;
		transMatrix[2][2] = 1;
		transMatrix[2][3] = trans.z;
		transMatrix[3][3] = 1;

		return transMatrix;
	}

	Mat4	Mat4::createXRotationMatrix(const float angle)
	{
		Mat4	xRotation;

	    float   c = cos(angle);
	    float   s = sin(angle);

		xRotation[0][0] = 1;
		xRotation[1][1] = c;
	    xRotation[1][2] = -s;
	    xRotation[2][1] = s;
	    xRotation[2][2] = c;
		xRotation[3][3] = 1;

	    return xRotation;
	}

	Mat4	Mat4::createYRotationMatrix(const float angle)
	{
		Mat4	yRotation;

		float   c = cos(angle);
		float   s = sin(angle);

		yRotation[0][0] = c;
		yRotation[0][2] = s;
		yRotation[1][1] = 1;
		yRotation[2][0] = -s;
		yRotation[2][2] = c;
		yRotation[3][3] = 1;

		return yRotation;
	}

	Mat4	Mat4::createZRotationMatrix(const float angle)
	{
		Mat4	zRotation;

	    float   c = cos(angle);
	    float   s = sin(angle);

	    zRotation[0][0] = c;
	    zRotation[0][1] = -s;
	    zRotation[1][0] = s;
	    zRotation[1][1] = c;
		zRotation[2][2] = 1;
		zRotation[3][3] = 1;

	    return zRotation;
	}

	Mat4	Mat4::createFixedAngleEulerRotationMatrix(const Vec3& rotate)
	{
		Mat4	xRotation(Mat4::createXRotationMatrix(rotate.x));
	    Mat4	yRotation(Mat4::createYRotationMatrix(rotate.y));
	    Mat4	zRotation(Mat4::createZRotationMatrix(rotate.z));

	    Mat4	rotation(yRotation * xRotation * zRotation);

	    return rotation;
	}

	Mat4	Mat4::createTRSMatrix(const Vec3& trans, const Vec3& rotate, const Vec3& scale)
	{
		Mat4	transMatrix(Mat4::createTranslationMatrix(trans));
		Mat4	rotateMatrix(Mat4::createFixedAngleEulerRotationMatrix(rotate));
		Mat4	scaleMatrix(Mat4::createScaleMatrix(scale));

		Mat4	TRS(transMatrix * rotateMatrix * scaleMatrix);

		LOG(DEBUG, TRS.to_string());

		return TRS;
	}

	Mat4	Mat4::createProjectionMatrix(int width, int height, float near,
									float far, float fov)
	{
		float   ratio = (float)width / (float)height;
		float   tanHalfFOV = tanf((M_PI / 180.f) * (fov / 2.f));

		Mat4	project;

		project[0][0] = 1.f / (tanHalfFOV * ratio);

		project[1][1] = 1.f / tanf(fov / 2.f);

		project[2][2] = -(far + near) / (far - near);
		project[2][3] = -(2 * far * near) / (far - near);

		project[3][2] = -1.0f;

		LOG(DEBUG, project.to_string());

		return project;
	}

	float	Mat4::determinant()
	{
		float	determinant;
		float	a1 {(*this)[0][0]};
		float	a2 {(*this)[0][1]};
		float	a3 {(*this)[0][2]};
		float	a4 {(*this)[0][3]};
		float	a5 {(*this)[1][0]};
		float	a6 {(*this)[1][1]};
		float	a7 {(*this)[1][2]};
		float	a8 {(*this)[1][3]};
		float	a9 {(*this)[2][0]};
		float	a10 {(*this)[2][1]};
		float	a11 {(*this)[2][2]};
		float	a12 {(*this)[2][3]};
		float	a13 {(*this)[3][0]};
		float	a14 {(*this)[3][1]};
		float	a15 {(*this)[3][2]};
		float	a16 {(*this)[3][3]};

		determinant = a1 * (a6 * (a11 * a16 - a15 * a12) - a7 * (a10 * a16 - a14 * a12)
		+ a8 * (a10 * a15 - a14 * a11)) - a2 * (a5 * (a11 * a16 - a15 * a12) - a7 *
		(a9 * a16 - a13 * a12) + a8 * (a9 * a15 - a13 * a11)) + a3 * (a5 * (a10 * a16
		- a14 * a12) - a6 * (a9 * a16 - a13 * a12) + a8 * (a9 * a14 - a13 * a10)) -
		a4 * (a5 * (a10 * a15 - a14 * a11) - a6 * (a9 * a15 - a13 * a11) + a7 *
		(a9 * a14 - a13 * a10));

		return determinant;
	}
}
