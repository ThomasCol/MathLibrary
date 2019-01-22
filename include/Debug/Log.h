#ifndef _LOG_H_
#define _LOG_H_

#include <string>

namespace Debug
{
	class Log
	{
	public:
		/* enum for log type */
		enum class Severity
		{
			DEFAULT = 0,
			INFO,
			DEBUG,
			WARNING,
			ERROR
		};
	private:
		/* constructor */
		Log();
		/* destructor */
		~Log();

		/* singleton */
		static Log	m_instance;

	public:
		static Log&	instance();

		/* treat log type */
		void 	logType(Severity severity, std::string message = "\0");

		/* send log */
		void 	info(std::string info, std::string time);
		void 	debug(std::string debug, std::string time);
		void 	warning(std::string warning, std::string time);
		void 	error(std::string error, std::string time);
	};

	/* write log on log file */
	void 		writeLog(std::string log);

	/* clear log file */
	void 		clearLog();

	/* send log time */
	std::string	getTime();
}

/* macro to stop log */
#ifdef NDEBUG
	#define LOG(severity, message) ((void)0)
	#define	ClearLOG() ((void)0)
#else
	/* macro to call log */
	#define LOG(severity, message)\
	Debug::Log::instance().logType(Debug::Log::Severity::severity, message)
	#define	ClearLOG() Debug::clearLog()
#endif

#endif //_LOG_H_
