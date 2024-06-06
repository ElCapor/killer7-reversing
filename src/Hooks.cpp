#include <Windows.h>
#include <Hooks.hpp>
#include <detours.h>
#include <EE/Thread/Threads.hpp>
#include <console.hpp>
#include <jhook.hpp>
void EE::Hooks::HookThreads()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    Console::log(std::hex, EE::Thread::oCreateThread);
    DetourAttach(&(PVOID&)EE::Thread::oCreateThread, EE::Thread::CreateThread);
    DetourTransactionCommit();
}

void EE::Hooks::UnHookThreads()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    //DetourDetach(&(PVOID&)EE::Thread::oCreateThread, EE::Thread::CreateThread);
    DetourTransactionCommit();
}
