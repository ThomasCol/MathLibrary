#include "Log.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

namespace Core::Debug
{

	Log	Log::m_instance {Log()};

	Log::Log()
	{
	}

	Log::~Log()
	{

	}

	Log&	Log::instance()
	{
		return m_instance;
	}

	void 	Log::logType(Severity severity, std::string message)
	{
		std::string	time = getTime();

		switch (severity)
		{
			case Severity::INFO:
				info(message, time);
				break;

			case Severity::DEBUG:
				debug(message, time);
				break;

			case Severity::WARNING:
				warning(message, time);
				break;

			case Severity::ERROR:
				error(message, time);
				break;

			default:
				break;
		}
	}

	void 	Log::info(std::string info, std::string time)
	{
		std::string	log = "[Info]  " + time + "\n\t> " + info + "\n";

		std::string	message = "\e[1;92;4m[Info]  " + time + "\n\t\e[0;32m> " +
		info + "\n\e[39m";

		std::cout << message;

		writeLog(log);
	}

	void 	Log::debug(std::string debug, std::string time)
	{
		std::string	log = "[Debug]  " + time + "\n\t> " + debug + "\n";

		std::string	message = "\e[1;96;4m[Debug]  " + time +
		"\n\t\e[0;36m> " + debug + "\n\e[39m";

		std::cout << message;

		writeLog(log);
	}

	void 	Log::warning(std::string warning, std::string time)
	{
		std::string	log = "[Warning]  " + time + "\n\t> " + warning + "\n";

		std::string	message = "\e[1;93;4m[Warning]  " + time +
		"\n\t\e[0;33m> " +
		warning + "\n\e[39m";

		std::cout << message;

		writeLog(log);
	}

	void 	Log::error(std::string error, std::string time)
	{
		std::string	log = "[Error]  " + time + "\n\t> " + error + "\n";

		std::string	message = "\e[1;91;4m[Error]  " + time +
		"\n\t\e[0;31m> " + error + "\n\e[39m";

		std::cout << message;

		writeLog(log);
	}

	void 	clearLog()
	{
		std::ofstream	logFile("resources/log.txt", std::ofstream::trunc);

		if (logFile.is_open())
		{
			logFile.close();
		}
	}

	void 	writeLog(std::string log)
	{
		std::ofstream	logFile("resources/log.txt", std::ios::app);

		if (logFile.is_open())
		{
			logFile << log;
			logFile.close();
		}
	}

	std::string	getTime()
	{
		time_t theTime = time(NULL);
		struct tm *aTime = localtime(&theTime);

		int	hour = aTime->tm_hour;
		int	min = aTime->tm_min;
		int	sec = aTime->tm_sec;

		std::string time = std::to_string(hour) + ":" +	std::to_string(min) + ":" +
		std::to_string(sec);

		return time;
	}
}
