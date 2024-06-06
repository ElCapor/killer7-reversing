#include <Windows.h>
#include <Hooks.hpp>
#include <detours.h>
#include <EE/Thread/Threads.hpp>
#include <EE/Vfs/Vfs.hpp>
#include <K7/Misc.hpp>
#include <console.hpp>
void EE::Hooks::HookThreads()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    Console::log(std::hex, EE::Thread::oCreateThread);
    DetourAttach(&(PVOID&)EE::Thread::oCreateThread, EE::Thread::CreateThread);
    DetourAttach(&(PVOID&)EE::VfsArchive::oReadFile, EE::VfsArchive::ReadFile);
    DetourAttach(&(PVOID&)EE::VfsArchive::oOpenFile, EE::VfsArchive::OpenFile);
    DetourAttach(&(PVOID&)EE::VfsArchive::oAccessFile, EE::VfsArchive::AccessFile);
    DetourAttach(&(PVOID&)EE::VfsFileZlib::oRead, EE::VfsFileZlib::Read);
    DetourAttach(&(PVOID&)K7::Graphics::oDrawMenuButton, K7::Graphics::DrawMenuButton);
    DetourTransactionCommit();
}

void EE::Hooks::UnHookThreads()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    //DetourDetach(&(PVOID&)EE::Thread::oCreateThread, EE::Thread::CreateThread);
    DetourTransactionCommit();
}
