#ifndef _REF3_H_
#define _REF3_H_

#include "Vec3.h"

namespace Math
{
	struct Ref3
	{
		Vec3	o;
		Vec3	i;
		Vec3	j;
		Vec3	k;

		Ref3(const Vec3& O = {Vec3::zero}, const Vec3& I = {Vec3::right},
			const Vec3& J = {Vec3::up}, const Vec3& K = {Vec3::forward});
		Ref3(const Ref3& ref);
		Ref3(Ref3&& ref) = default;
		~Ref3();

		Ref3&	operator=(const Ref3& ref);

	};
}

#endif //_REFERANTIAL3_H_
