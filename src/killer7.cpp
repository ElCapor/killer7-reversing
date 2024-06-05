#include <killer7.hpp>
#include <globals.hpp>
DWORD WINAPI killer7::MainThread()
{
    return 0;
}

DWORD WINAPI killer7::EjectSelf()
{
    Sleep(5000);
    FreeLibraryAndExitThread(globals::hDll, 0);
}

void killer7::shutdown()
{

}