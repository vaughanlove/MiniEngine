#pragma once

#ifdef ME_PLATFORM_WINDOWS
	#ifdef ME_BUILD_DLL
		#define MINIENGINE_API __declspec(dllexport)
	#elif ME_SANDBOX
		#define MINIENGINE_API __declspec(dllimport)
	#else
		#define MINIENGINE_API __declspec(dllimport)
	#endif
#else
	#error MiniEngine only supports Windows.
#endif

#ifdef ME_ENABLE_ASSERTS
	#define ME_ASSERT(x, ...) {if (!(x)) {ME_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ME_CORE_ASSERT(x, ...) {if (!(x)) {ME_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ME_ASSERT(x, ...)
	#define ME_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x) 