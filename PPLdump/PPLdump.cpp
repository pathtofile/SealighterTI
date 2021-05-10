#include "exploit.h"
#include "sealighter_provider.h"
#include <iostream>

BOOL g_bVerbose = TRUE;
BOOL g_bDebug = TRUE;
BOOL g_bForce = FALSE;
LPWSTR g_pwszDLLPath = NULL;

int wmain(int argc, wchar_t* argv[])
{
    BOOL bReturnValue = FALSE;

    if (!ParseArguments(argc, argv))
        return 1;

    // Add Sealighter ETW Provider
    int status = EventRegisterSealighter();
    if (ERROR_SUCCESS != status) {
        return 1;
    }

    bReturnValue = LoadDLL(g_pwszDLLPath);
    if (bReturnValue) {
        return 0;
    }
    return 1;
}
