#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Angine {


	class ANGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define AG_CORE_TRACE(...)	::Angine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AG_CORE_INFO(...)	::Angine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AG_CORE_WARN(...)	::Angine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AG_CORE_ERROR(...)	::Angine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AG_CORE_FATAL(...)	::Angine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define AG_TRACE(...)	::Angine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AG_INFO(...)	::Angine::Log::GetClientLogger()->info(__VA_ARGS__)
#define AG_WARN(...)	::Angine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AG_ERROR(...)	::Angine::Log::GetClientLogger()->error(__VA_ARGS__)
#define AG_FATAL(...)	::Angine::Log::GetClientLogger()->fatal(__VA_ARGS__)
