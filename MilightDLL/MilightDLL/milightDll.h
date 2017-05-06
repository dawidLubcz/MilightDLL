#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define DLL_EXPORT
#if defined DLL_EXPORT
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

EXTERN_C
{
	/*
		Function creates all objects on dll side
		shall be called first.
	*/
	DLL_API BOOL APIENTRY Initialize();

	/* Release resources */
	DLL_API BOOL APIENTRY Release();

	/* Turn on the LED bulbs */
	DLL_API BOOL APIENTRY turnOn(int a_iGroup);

	/* Turn off the LED bulbs */
	DLL_API BOOL APIENTRY turnOff(int a_iGroup);

	/* Reset color to default */
	DLL_API BOOL APIENTRY setWhite(int a_iGroup);

	/* Set power, 0 - 100%*/
	DLL_API BOOL APIENTRY setBrightness(int a_iGroup, int a_iProc);

	/* Set color, for details look at ILEDInterface.h */
	DLL_API BOOL APIENTRY setColor(int a_iGroup, int a_iColor);
}
