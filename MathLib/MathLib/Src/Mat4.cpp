#include "Mat4.h"
#include "Mat.h"

#include <math.h>

namespace Math
{
	Mat4::Mat4()
	{
		for (int i = 0; i < 16; i++)
		{
			array[i] = 0;
		}
	}

	Mat4::Mat4(const Mat4& mat)
	{
		for (int i = 0; i < 16; i++)
		{
			array[i] = mat.array[i];
		}
	}

	float*	Mat4::operator[](int i)
	{
		return &array[i * 4];
	}

	const float*  Mat4::operator[](int i) const
	{
	    return &array[i * 4];
	}

	Mat4	Mat4::Identity()
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
		int		i, j, k;

	    for (i = 0; i < 4; i++)
	    {
	        for (j = 0; j < 4; j++)
	        {
	            for (k = 0; k < 4; k++)
	            {
	                res.array[i * 4 + j] += array[i * 4 + k] * mat.array[k * 4 + j];
	            }
	        }
	    }

	    return res;
	}

	Vec3	Mat4::operator*(const Vec3& vec) const
	{

	    return Vec3(array[0] * vec.x + array[1] * vec.x + array[2] * vec.x + array[3] * vec.x,
			array[4] * vec.y + array[5] * vec.y + array[6] * vec.y + array[7] * vec.y,
			array[8] * vec.z + array[9] * vec.z + array[10] * vec.z + array[11] * vec.z);
	}

	Vec3	Mat4::operator*(const Vec4& vec) const
	{
		Mat4  matVec;
	    matVec[0][0] = vec.x;
	    matVec[1][0] = vec.y;
	    matVec[2][0] = vec.z;
	    matVec[3][0] = vec.w;

	    Mat4  res((*this) * matVec);

	    Vec3 vecRes(res[0][0], res[1][0], res[2][0]);

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

	Mat4	Mat4::Transpose() const
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

	std::string	Mat4::ToString() const
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

	Mat4	Mat4::CreateScaleMatrix(const Vec3& scale)
	{
		Mat4  scaleMatrix;

	    scaleMatrix[0][0] = scale.x;
	    scaleMatrix[1][1] = scale.y;
	    scaleMatrix[2][2] = scale.z;
	    scaleMatrix[3][3] = 1;

	    return scaleMatrix;
	}

	Mat4	Mat4::CreateTranslationMatrix(const Vec3& trans)
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

	Mat4		Mat4::CreateRotationMatrix(const Vec3& axis, const float& angle)
	{
		float c = cos(angle);
		float s = sin(angle);
		float t = 1 - c;
		float axisX = axis.x;
		float axisY = axis.y;
		float axisZ = axis.z;

		Mat4	rotation;

		rotation[0][0] = axisX * axisX * t + c;
		rotation[0][1] = axisX * axisY * t - axisZ * s;
		rotation[0][2] = axisX * axisZ * t + axisY * s;
		rotation[0][3] = 0;

		rotation[1][0] = axisX * axisY * t + axisZ * s;
		rotation[1][1] = axisY * axisY * t + c;
		rotation[1][2] = axisY * axisZ * t - axisX * s;
		rotation[1][3] = 0;

		rotation[2][0] = axisX * axisZ * t - axisY * s;
		rotation[2][1] = axisY * axisZ * t + axisX * s;
		rotation[2][2] = axisZ * axisZ * t + c;
		rotation[2][3] = 0;

		rotation[3][0] = 0;
		rotation[3][1] = 0;
		rotation[3][2] = 0;
		rotation[3][3] = 1;

		return rotation;
	}

	Mat4	Mat4::CreateXRotationMatrix(const float angle)
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

	Mat4	Mat4::CreateYRotationMatrix(const float angle)
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

	Mat4	Mat4::CreateZRotationMatrix(const float angle)
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

	Mat4	Mat4::CreateFixedAngleEulerRotationMatrix(const QXvec3& rotate)
	{
		Mat4	xRotation(Mat4::CreateXRotationMatrix(rotate.x));
	    Mat4	yRotation(Mat4::CreateYRotationMatrix(rotate.y));
	    Mat4	zRotation(Mat4::CreateZRotationMatrix(rotate.z));

	    Mat4	rotation(yRotation * xRotation * zRotation);

	    return rotation;
	}

	Mat4	Mat4::CreateTRSMatrix(const Vec3& trans, const Vec3& rotate, const Vec3& scale)
	{
		Mat4	transMatrix(Mat4::CreateTranslationMatrix(trans));
		Mat4	rotateMatrix(Mat4::CreateFixedAngleEulerRotationMatrix(rotate));
		Mat4	scaleMatrix(Mat4::CreateScaleMatrix(scale));

		Mat4	TRS(transMatrix * rotateMatrix * scaleMatrix);

		return TRS;
	}

	Mat4	Mat4::CreateProjectionMatrix(int width, int height, float near,
			float far, float fov)
	{
 		Mat4    toReturn;
		float top , bottom , left , right;
		float a = (float)width / height;

		top = (float)(near * tan(fov * 0.5 * M_PI / 180.0f));
		bottom = -top;
		right = top * a;
		left = -right;
		toReturn[0][0] = 2 * near / (right - left);
		toReturn[1][1] = 2 * near / (top - bottom);
		toReturn[2][2] = -(far + near) / (far - near);
		toReturn[3][2] = -1;
		toReturn[0][3] = -near * (right + left) / (right - left);
		toReturn[1][3] = -near * (top + bottom) / (top - bottom);
		toReturn[2][3] = 2 * far * near / (near - far);

		return toReturn;
	}

	Mat4    Mat4::CreateOrthographicProjectionMatrix(int width, int height, float near, float far)
	{
		Mat4 toReturn = Mat4::Identity();
		float top , bottom , left , right;

		top = (float)height / 2.f;
		bottom = -top;
		right = (float)width / 2.f;
		left = -right;
		toReturn[0][0] = 1 / right - left;
		toReturn[1][1] = 2 / top - bottom;
		toReturn[2][2] = -2 / (far - near);
		toReturn[2][3] = - (far + near) / (far - near);
		toReturn[0][3] = - (right + left) / (right - left);
		toReturn[1][3] = - (top + bottom) / (top - bottom);
		return toReturn;
	}

	// Custom implementation of the LookAt function
	Mat4	Mat4::CreateLookAtMatrix(Vec3 position, Vec3 target, Vec3 up, Vec3 scale)
	{
		Mat4	lookAt;

		Vec3	X, Y, Z;

		Z = target - position;
		Z.Normalize();
		X = (up ^ Z);
		X.Normalize();
		Y = (Z ^ X);
		Y.Normalize();

		lookAt[0][0] = X.x;
		lookAt[1][0] = X.y;
		lookAt[2][0] = X.z;
		//		lookAt[0][3] = -(X, position);
		lookAt[0][1] = Y.x;
		lookAt[1][1] = Y.y;
		lookAt[2][1] = Y.z;
		//		lookAt[1][3] = -(Y, position);
		lookAt[0][2] = Z.x;
		lookAt[1][2] = Z.y;
		lookAt[2][2] = Z.z;
		//		lookAt[2][3] = -(Z, position);
		lookAt[0][3] = position.x;
		lookAt[1][3] = position.y;
		lookAt[2][3] = position.z;
		lookAt[3][3] = 1.0f;

		return lookAt;
	}


	Mat4 Mat4::Inverse() const
	{
		Mat m(4, 4);

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				m[i][j] = (*this)[i][j];

		m = m.Inverse();
		Mat4 invt;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				invt[i][j] = m[i][j];

		return invt;
	}
}
