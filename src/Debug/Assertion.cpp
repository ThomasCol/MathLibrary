#include "Assertion.h"
#include "Log.h"

#include <iostream>

namespace Debug
{
	void 	staticAssert(bool condition, std::string file, int line)
	{
		if (!condition)
		{
			std::string	time = getTime();

			std::string log {"[Static Assert]  " + time + "\n\t> in file " + file +
			", line " +	std::to_string(line) + ".\n"};

			std::cout << "\e[1;91;4m[Static Assert]  " << time <<
			"\e[0;31m\n\t> in file " <<	file << ", line " << line << ".\n";

			writeLog(log);

			exit(0);
		}
	}

	void 	assert(bool condition, std::string file, int line)
	{
		if (!condition)
		{
			std::string	time = getTime();

			std::string log {"[Assert]  " + time + "\n\t> in file " + file +
			", line " +	std::to_string(line) + ".\n"};

			std::cout << "\e[1;91;4m[Assert]  " << time << "\e[0;31m\n\t> in file "
			<< file << ", line " << line << ".\n";

			writeLog(log);
		}
	}
}
