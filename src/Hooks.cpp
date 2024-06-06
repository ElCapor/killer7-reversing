#include <Windows.h>
#include <Hooks.hpp>
#include <detours.h>
#include <EE/Thread/Threads.hpp>
#include <EE/Vfs/Vfs.hpp>
#include <console.hpp>
void EE::Hooks::HookThreads()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    Console::log(std::hex, EE::Thread::oCreateThread);
    DetourAttach(&(PVOID&)EE::Thread::oCreateThread, EE::Thread::CreateThread);
    DetourAttach(&(PVOID&)EE::Vfs::oReadFile, EE::Vfs::ReadFile);
    DetourTransactionCommit();
}

void EE::Hooks::UnHookThreads()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    //DetourDetach(&(PVOID&)EE::Thread::oCreateThread, EE::Thread::CreateThread);
    DetourTransactionCommit();
}
