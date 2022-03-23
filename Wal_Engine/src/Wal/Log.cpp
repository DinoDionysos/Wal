#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Wal {

	// define logger for Wal Engine
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	// define logger for Application (Client) that uses Wal 
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// set the pattern of the log message. (%^...%$-> color, %T-> timestamp, %n->which logger, %v->actual log message
		spdlog::set_pattern("%^[%T] %n: %v%$");
		// set a color for core logger
		s_CoreLogger = spdlog::stdout_color_mt("WAL");
		// level trace = print everything
		s_CoreLogger->set_level(spdlog::level::trace);

		// set a color for client logger
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		// level trace = print everything
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}