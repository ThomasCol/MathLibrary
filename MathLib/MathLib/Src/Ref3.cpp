#include "Ref3.h"

namespace Math
{
    Ref3::Ref3(const Vec3& O, const Vec3& I, const Vec3& J, const Vec3& K):
		o {O},
		i {I.Normalize()},
		j {J.Normalize()},
		k {K.Normalize()}
    {
	}

    Ref3::Ref3(const Ref3& ref):
		o {ref.o},
		i {ref.i},
		j {ref.j},
		k {ref.k}
    {}

    Ref3::~Ref3()
    {}

    Ref3&   Ref3::operator=(const Ref3& ref)
    {
        o = ref.o;
        i = ref.i;
        j = ref.j;
        k = ref.k;

        return *this;
    }
}