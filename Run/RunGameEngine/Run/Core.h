#pragma once

#ifdef RN_BUILD_DLL
	#define RUN_API __declspec(dllexport)
#else
	#define RUN_API __declspec(dllimport)
#endif // RN_BUILD_DLL