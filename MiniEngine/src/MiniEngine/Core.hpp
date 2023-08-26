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

#define BIT(x) (1 << x) 