#include "Quad.h"

namespace Math::Geometry
{
	QXquad::QXquad(const QXvec3& position, const QXvec3& i, const QXvec3& j, const QXvec3& k,
		const QXfloat& x, const QXfloat& y) noexcept :
		_position(position),
		_i(i),
		_j(j),
		_k(k),
		_x{ x },
		_y{ y }
	{}

	QXquad::QXquad(const QXquad& quad) noexcept :
		_position(quad._position),
		_i{ quad._i },
		_j{ quad._j },
		_k{ quad._k },
		_x{ quad._x },
		_y{ quad._y }
	{}

	QXquad::QXquad(QXquad&& quad) noexcept :
		_position{ std::move(quad._position) },
		_i{ std::move(quad._i) },
		_j{std::move(quad._j)},
		_k{ std::move(quad._k) },
		_x{std::move(quad._x)},
		_y{std::move(quad._y)}
	{}

	QXquad& QXquad::operator=(const QXquad& quad)
	{
		_position = quad._position;
		_i = quad._i;
		_j = quad._j;
		_k = quad._k;
		_x = quad._x;
		_y = quad._y;

		return *this;
	}
}
