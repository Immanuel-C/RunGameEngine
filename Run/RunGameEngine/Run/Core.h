#pragma once


#ifdef RN_EXPORT
	#define RUN_API __declspec(dllexport)
#else
	#define RUN_API __declspec(dllimport)
#endif