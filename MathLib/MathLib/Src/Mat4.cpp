#include "Mat4.h"
#include "Mat.h"

#include <math.h>

namespace Math
{
	#pragma region Constructor
	QXmat4::QXmat4()
	{
		for (QXint i = 0; i < 16; i++)
		{
			array[i] = 0;
		}
	}

	QXmat4::QXmat4(const QXmat4& mat)
	{
		for (QXint i = 0; i < 16; i++)
		{
			array[i] = mat.array[i];
		}
	}
	#pragma endregion Constructor

	#pragma region Functions
	QXmat4 QXmat4::Inverse() const
	{
		QXmat m(4, 4);

		for (QXint i = 0; i < 4; i++)
			for (QXint j = 0; j < 4; j++)
				m[i][j] = (*this)[i][j];

		m = m.Inverse();
		QXmat4 invt;

		for (QXint i = 0; i < 4; i++)
			for (QXint j = 0; j < 4; j++)
				invt[i][j] = m[i][j];

		return invt;
	}

	QXmat4	QXmat4::Transpose() const
	{
		QXmat4	res;
		QXfloat	tmp;

	    for (QXint i = 0; i < 4; i++)
	    {
	        for (QXint j = 0; j < 4; j++)
	        {
	            tmp = array[i * 4 + j];
	            res[j][i] = tmp;
	        }
	    }

	    return res;
	}

	QXstring	QXmat4::ToString() const
	{
		std::string	mat;
		for (QXint i = 0; i < 4; i++)
	    {
	        for (QXint j = 0; j < 4; j++)
	        {
	            mat = mat + std::to_string(array[i * 4 + j]) + " ";
	        }
	        mat += "\n\t  ";
	    }

		return mat;
	}

	#pragma region Operator Functions
	QXfloat* QXmat4::operator[](QXint i)
	{
		return &array[i * 4];
	}

	const QXfloat* QXmat4::operator[](QXint i) const
	{
		return &array[i * 4];
	}

	QXmat4	QXmat4::operator+(const QXmat4& mat) const
	{
		QXmat4	res;

		for (QXint i = 0; i < 16; i++)
		{
			res.array[i] = mat.array[i] + array[i];
		}

		return res;
	}

	QXmat4	QXmat4::operator*(const QXmat4& mat) const
	{
		QXmat4	res;
		QXint	i, j, k;

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

	QXvec3	QXmat4::operator*(const QXvec3& vec) const
	{

		return QXvec3(array[0] * vec.x + array[1] * vec.x + array[2] * vec.x + array[3] * vec.x,
			array[4] * vec.y + array[5] * vec.y + array[6] * vec.y + array[7] * vec.y,
			array[8] * vec.z + array[9] * vec.z + array[10] * vec.z + array[11] * vec.z);
	}

	QXvec3	QXmat4::operator*(const QXvec4& vec) const
	{
		QXmat4  matVec;
		matVec[0][0] = vec.x;
		matVec[1][0] = vec.y;
		matVec[2][0] = vec.z;
		matVec[3][0] = vec.w;

		QXmat4  res((*this) * matVec);

		QXvec3 vecRes(res[0][0], res[1][0], res[2][0]);

		return vecRes;
	}

	QXmat4& QXmat4::operator*=(const QXmat4& mat)
	{
		QXmat4	res;

		for (QXint i = 0; i < 4; i++)
		{
			for (QXint j = 0; j < 4; j++)
			{
				for (QXint k = 0; k < 4; k++)
				{
					res[i][j] += (*this)[i][k] * mat[k][j];
				}
			}
		}

		(*this) = res;

		return *this;
	}
	#pragma endregion Operator Functions

	#pragma region Static Functions
	QXmat4	QXmat4::CreateScaleMatrix(const QXvec3& scale)
	{
		QXmat4  scaleMatrix;

	    scaleMatrix[0][0] = scale.x;
	    scaleMatrix[1][1] = scale.y;
	    scaleMatrix[2][2] = scale.z;
	    scaleMatrix[3][3] = 1;

	    return scaleMatrix;
	}

	QXmat4	QXmat4::CreateTranslationMatrix(const QXvec3& trans)
	{
		QXmat4	transMatrix;

		transMatrix[0][0] = 1;
		transMatrix[0][3] = trans.x;
		transMatrix[1][1] = 1;
		transMatrix[1][3] = trans.y;
		transMatrix[2][2] = 1;
		transMatrix[2][3] = trans.z;
		transMatrix[3][3] = 1;

		return transMatrix;
	}

	QXmat4		QXmat4::CreateRotationMatrix(const QXvec3& axis, const QXfloat& angle)
	{
		QXfloat c = cos(angle);
		QXfloat s = sin(angle);
		QXfloat t = 1 - c;
		QXfloat axisX = axis.x;
		QXfloat axisY = axis.y;
		QXfloat axisZ = axis.z;

		QXmat4	rotation;

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

	QXmat4	QXmat4::CreateXRotationMatrix(const QXfloat angle)
	{
		QXmat4	xRotation;

		QXfloat   c = cos(angle);
		QXfloat   s = sin(angle);

		xRotation[0][0] = 1;
		xRotation[1][1] = c;
		xRotation[1][2] = -s;
		xRotation[2][1] = s;
		xRotation[2][2] = c;
		xRotation[3][3] = 1;

		return xRotation;
	}

	QXmat4	QXmat4::CreateYRotationMatrix(const QXfloat angle)
	{
		QXmat4	yRotation;

		QXfloat   c = cos(angle);
		QXfloat   s = sin(angle);

		yRotation[0][0] = c;
		yRotation[0][2] = s;
		yRotation[1][1] = 1;
		yRotation[2][0] = -s;
		yRotation[2][2] = c;
		yRotation[3][3] = 1;

		return yRotation;
	}

	QXmat4	QXmat4::CreateZRotationMatrix(const QXfloat angle)
	{
		QXmat4	zRotation;

		QXfloat   c = cos(angle);
		QXfloat   s = sin(angle);

		zRotation[0][0] = c;
		zRotation[0][1] = -s;
		zRotation[1][0] = s;
		zRotation[1][1] = c;
		zRotation[2][2] = 1;
		zRotation[3][3] = 1;

		return zRotation;
	}

	QXmat4	QXmat4::CreateFixedAngleEulerRotationMatrix(const QXvec3& rotate)
	{
		QXmat4	xRotation(QXmat4::CreateXRotationMatrix(rotate.x));
		QXmat4	yRotation(QXmat4::CreateYRotationMatrix(rotate.y));
		QXmat4	zRotation(QXmat4::CreateZRotationMatrix(rotate.z));

		QXmat4	rotation(yRotation * xRotation * zRotation);

		return rotation;
	}

	QXmat4	QXmat4::CreateTRSMatrix(const QXvec3& trans, const QXvec3& rotate, const QXvec3& scale)
	{
		QXmat4	transMatrix(QXmat4::CreateTranslationMatrix(trans));
		QXmat4	rotateMatrix(QXmat4::CreateFixedAngleEulerRotationMatrix(rotate));
		QXmat4	scaleMatrix(QXmat4::CreateScaleMatrix(scale));

		QXmat4	TRS(transMatrix * rotateMatrix * scaleMatrix);

		return TRS;
	}

	QXmat4	QXmat4::CreateProjectionMatrix(QXint width, QXint height, QXfloat near,
		QXfloat far, QXfloat fov)
	{
		QXmat4    toReturn;
		QXfloat top, bottom, left, right;
		QXfloat a = (QXfloat)width / height;

		top = (QXfloat)(near * tan(fov * 0.5 * M_PI / 180.0f));
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

	QXmat4    QXmat4::CreateOrthographicProjectionMatrix(QXint width, QXint height, QXfloat near, QXfloat far)
	{
		QXmat4 toReturn = QXmat4::Identity();
		QXfloat top, bottom, left, right;

		top = (QXfloat)height / 2.f;
		bottom = -top;
		right = (QXfloat)width / 2.f;
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
	QXmat4	QXmat4::CreateLookAtMatrix(QXvec3 position, QXvec3 target, QXvec3 up, QXvec3 scale)
	{
		QXmat4	lookAt;

		QXvec3	X, Y, Z;

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

	QXmat4	QXmat4::Identity()
	{
		QXmat4	identity;

		identity[0][0] = 1;
		identity[1][1] = 1;
		identity[2][2] = 1;
		identity[3][3] = 1;

		return identity;
	}
	#pragma endregion Static Functions
	#pragma endregion Functions
}
