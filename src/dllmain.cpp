#include <Windows.h>
#include <globals.hpp>
#include <killer7.hpp>
BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,
    DWORD fdwReason,
    LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hinstDLL);
        globals::hDll = hinstDLL;
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)killer7::MainThread, NULL, 0, NULL);
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    case DLL_PROCESS_DETACH:
        killer7::shutdown();
        break;
    }
    return TRUE; // Successful DLL_PROCESS_ATTACH.
}