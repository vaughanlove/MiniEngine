#pragma once

#include <memory>

#include "Core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace MiniEngine {
	class MINIENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define ME_CORE_ERROR(...)  ::MiniEngine::Log::GetCoreLogger() -> error(__VA_ARGS__)
#define ME_CORE_WARN(...)   ::MiniEngine::Log::GetCoreLogger() -> warn(__VA_ARGS__)
#define ME_CORE_INFO(...)   ::MiniEngine::Log::GetCoreLogger() -> info(__VA_ARGS__)
#define ME_CORE_TRACE(...)  ::MiniEngine::Log::GetCoreLogger() -> trace(__VA_ARGS__)
#define ME_CORE_FATAL(...)  ::MiniEngine::Log::GetCoreLogger() -> critical(__VA_ARGS__)

// Client log macros
#define ME_ERROR(...)  ::MiniEngine::Log::GetClientLogger() -> error(__VA_ARGS__)
#define ME_WARN(...)   ::MiniEngine::Log::GetClientLogger() -> warn(__VA_ARGS__)
#define ME_INFO(...)   ::MiniEngine::Log::GetClientLogger() -> info(__VA_ARGS__)
#define ME_TRACE(...)  ::MiniEngine::Log::GetClientLogger() -> trace(__VA_ARGS__)
#define ME_FATAL(...)  ::MiniEngine::Log::GetClientLogger() -> critical(__VA_ARGS__)