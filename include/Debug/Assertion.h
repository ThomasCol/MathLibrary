#ifndef _ASSERTION_H_
#define _ASSERTION_H_

#include <string>

namespace Core::Debug
{
	/* static assert break program */
	void 	staticAssert(bool condition, std::string file, int line);
	/* assert send an alert */
	void 	assert(bool condition, std::string file, int line);
}

/* Macro to deactivate asserts */
#ifdef NDEBUG
	#define Assert(condition) ((void)0)
	#define StaticAssert(condition) ((void)0)
/* Macro to call asserts */
#else
	#define Assert(condition)\
	Core::Debug::assert(condition, __FILE__, __LINE__)
	#define StaticAssert(condition)\
	Core::Debug::staticAssert(condition, __FILE__, __LINE__)
#endif

#endif //_ASSERTION_H_
