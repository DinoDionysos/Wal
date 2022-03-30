#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Wal {

	class WAL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// macros for core logging
#define WL_CORE_TRACE(...) ::Wal::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WL_CORE_INFO(...) ::Wal::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WL_CORE_WARN(...) ::Wal::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WL_CORE_ERROR(...) ::Wal::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WL_CORE_FATAL(...) ::Wal::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// macros for core logging
#define WL_CLIENT_TRACE(...) ::Wal::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WL_CLIENT_INFO(...) ::Wal::Log::GetClientLogger()->info(__VA_ARGS__)
#define WL_CLIENT_WARN(...) ::Wal::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WL_CLIENT_ERROR(...) ::Wal::Log::GetClientLogger()->error(__VA_ARGS__)
#define WL_CLIENT_FATAL(...) ::Wal::Log::GetClientLogger()->fatal(__VA_ARGS_lient