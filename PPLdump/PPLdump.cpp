#include "exploit.h"
#include "sealighter_provider.h"
#include <iostream>

BOOL g_bVerbose = FALSE;
BOOL g_bDebug = FALSE;
BOOL g_bForce = FALSE;
HANDLE g_hEventStopTrace = NULL;

int wmain(int argc, wchar_t* argv[])
{
    BOOL bReturnValue = FALSE;
    DWORD dwPidToKill = 0;

    if (!ParseArguments(argc, argv))
        return 1;

    // Add Sealighter ETW Provider
    int status = EventRegisterSealighter();
    if (ERROR_SUCCESS != status) {
        return 1;
    }

    bReturnValue = StartETWLogger();
    if (!bReturnValue) {
        return 1;
    }
    (void)EventUnregisterSealighter();
    return 0;
}
