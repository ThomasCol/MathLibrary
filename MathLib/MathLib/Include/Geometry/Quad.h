#ifndef __QUAD_H__
#define __QUAD_H__

#include "Vec3.h"

namespace Math::Geometry
{
	class QXquad
	{
	private:
		#pragma region Attributes
		QXvec3	_position;
		QXvec3	_i;
		QXvec3	_j;
		QXvec3	_k;
		QXfloat	_x;
		QXfloat	_y;
		#pragma endregion Attributes

	public:
		#pragma region Constructors/Destructor
		QXquad(const QXvec3& position = QXvec3(0), const QXvec3& i = QXvec3(1, 0, 0),
				const QXvec3& j = QXvec3(0, 1, 0), const QXvec3& k = QXvec3(0, 0, 1),
				const QXfloat& x = 1.f, const QXfloat & y = 1.f) noexcept;
		QXquad(const QXquad& quad) noexcept;
		QXquad(QXquad&& quad) noexcept;
		~QXquad() {};
		#pragma endregion Constructors/Destructor

		#pragma region Methods
		#pragma region Accessors
		inline QXvec3	Position() const {return _position;}
		inline QXvec3	I() const {return _i;}
		inline QXvec3	J() const {return _j;}
		inline QXvec3	K() const {return _k;}
		inline QXfloat	X() const {return _x;}
		inline QXfloat	Y() const {return _y;}
		#pragma endregion Accessors

		#pragma region Operator
		QXquad&			operator=(const QXquad& quad);
		#pragma endregion Operator
		#pragma endregion Methods
	};
}


#endif
