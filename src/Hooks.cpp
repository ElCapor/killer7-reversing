#include <Windows.h>
#include <Hooks.hpp>
#include <detours.h>
#include <EE/Thread/Threads.hpp>
#include <EE/Vfs/Vfs.hpp>
#include <K7/Misc.hpp>
#include <console.hpp>

using sub_457400T = int(__thiscall*)(uintptr_t _this, int a2, int a3, char a4, void *Src, HICON hInstance, int a7, char a8, int a9);
sub_457400T osub_457400 = (sub_457400T)ASLR(0x457400);

int __fastcall sub_457400(uintptr_t _this, void* unused, int a2, int a3, char a4, void *Src, HICON hInstance, int a7, char a8, int a9)
{
    auto ret = osub_457400(_this, a2, a3, a4, Src, hInstance, a7, a8, a9);
    Console::log("Window struct : ", std::hex, ret);
    return ret;
}

BOOL WINAPI IsDebuggerPresentHook()
{
    return false;
}

template<typename T> T& GetRef(uint32_t addr)
{
    return *reinterpret_cast<T*>(ASLR(addr));
}

static inline auto& bShouldBreak = GetRef<bool>(0x007A3928); // even if it detects a debugger, setting this to 0 will make it not break on exceptions

void EE::Hooks::HookThreads()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    bShouldBreak = 0;
    DetourAttach(&(PVOID&)osub_457400, sub_457400);
    Console::log(std::hex, EE::Thread::oCreateThread);
    DetourAttach(&(PVOID&)EE::Thread::oCreateThread, EE::Thread::CreateThread);
    DetourAttach(&(PVOID&)EE::VfsArchive::oReadFile, EE::VfsArchive::ReadFile);
    DetourAttach(&(PVOID&)EE::VfsArchive::oOpenFile, EE::VfsArchive::OpenFile);
    DetourAttach(&(PVOID&)EE::VfsArchive::oAccessFile, EE::VfsArchive::AccessFile);
    DetourAttach(&(PVOID&)EE::VfsFileZlib::oRead, EE::VfsFileZlib::Read);
    DetourAttach(&(PVOID&)K7::Graphics::oDrawMenuButton, K7::Graphics::DrawMenuButton);
    DetourAttach(&(PVOID&)K7::Graphics::oRenderSprite, K7::Graphics::RenderSprite);
    DetourTransactionCommit();

    Console::log("GX PIPELINE", std::hex, ASLR(0x7EA280));
}

void EE::Hooks::UnHookThreads()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    //DetourDetach(&(PVOID&)EE::Thread::oCreateThread, EE::Thread::CreateThread);
    DetourTransactionCommit();
}
