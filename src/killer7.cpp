#include <killer7.hpp>
#include <globals.hpp>
#include <console.hpp>
#include <Hooks.hpp>

DWORD WINAPI killer7::MainThread()
{
    Console::Open();
    Console::log("Killer7 Dll");
    EE::Hooks::HookThreads();
    Console::Wait();
    Console::log("Press any key to exit...");
    Console::Close();
    //CreateThread(0, 0, (LPTHREAD_START_ROUTINE)killer7::EjectSelf, 0, 0, 0);
    CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)FreeLibrary, globals::hDll, 0, nullptr);
    return 0;
}

DWORD WINAPI killer7::EjectSelf()
{
    Sleep(5000);
    FreeLibraryAndExitThread(globals::hDll, 0);
}

void killer7::shutdown()
{
    EE::Hooks::UnHookThreads();
}