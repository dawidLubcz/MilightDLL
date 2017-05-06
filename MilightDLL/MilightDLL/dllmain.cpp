// dllmain.cpp : Defines the entry point for the DLL application.
#include "CLightsInterfacesFactory.h"

#include "milightDll.h"
#include <memory>

std::unique_ptr<ILEDInterface> g_upLEDInterface = 0;
ILEDInterface::eInterfaces g_eDefaultInterface = ILEDInterface::E_IF_MILIGTH;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

BOOL APIENTRY Initialize()
{
	using namespace smartLights::smartLightsBackend;

	g_upLEDInterface = CLightsInterfacesFactory::getInterface(g_eDefaultInterface);

	if (g_upLEDInterface)
	{
		return true;
	}
	return false;
}

BOOL APIENTRY Release()
{
	if (g_upLEDInterface)
	{
		g_upLEDInterface.reset();
		g_upLEDInterface = 0;

		return true;
	}
	return false;
}

BOOL APIENTRY turnOn(int a_iGroup)
{
	if (0 != g_upLEDInterface)
	{
		return g_upLEDInterface->sendTurnOnReq((ILEDInterface::eGroup)a_iGroup);
	}
	return false;
}

BOOL APIENTRY turnOff(int a_iGroup)
{
	if (0 != g_upLEDInterface)
	{
		return g_upLEDInterface->sendTurnOffReq((ILEDInterface::eGroup)a_iGroup);
	}
	return false;
}

BOOL APIENTRY setWhite(int a_iGroup)
{
	if (0 != g_upLEDInterface)
	{
		return g_upLEDInterface->sendWhiteReq((ILEDInterface::eGroup)a_iGroup);
	}
	return false;
}

BOOL APIENTRY setBrightness(int a_iGroup, int a_iProc)
{
	if (0 != g_upLEDInterface)
	{
		return g_upLEDInterface->sendBrightnessReq((ILEDInterface::eGroup)a_iGroup, a_iProc);
	}
	return false;
}

BOOL APIENTRY setColor(int a_iGroup, int a_iColor)
{
	if (0 != g_upLEDInterface)
	{
		return g_upLEDInterface->sendColourReq((ILEDInterface::eGroup)a_iGroup, a_iColor);
	}
	return false;
}