#include <Windows.h>
#include <Hooks.hpp>
#include <detours.h>
#include <EE/Thread/Threads.hpp>
#include <EE/Vfs/Vfs.hpp>
#include <K7/Misc.hpp>
#include <ghmGC/ghmgcfile.hpp>
#include <console.hpp>
#include <EE/Application/ApplicationBase.hpp>
#define HOOK(namespace, function) DetourAttach(&(PVOID&)##namespace::o##function, ##namespace::##function)
static inline auto& bShouldBreak = GetRef<bool>(0x007A3928); // even if it detects a debugger, setting this to 0 will make it not break on exceptions

using AppLoopT = int(__thiscall*)(uintptr_t _this);
AppLoopT oAppLoop = nullptr;

int __fastcall AppLoop(uintptr_t _this, void* unused)
{
    Console::log("AppLoop ", "status ", std::hex, _this);
    if (EE::ApplicationBase::App == nullptr)
        EE::ApplicationBase::App = (EE::ApplicationBase::CApplicationBase*)_this;
    return oAppLoop(_this);
}

void GetAppLoop()
{
    oAppLoop = (AppLoopT)Read<uintptr_t>(EE::ApplicationBase::vtable + 0x8);
}

void EE::Hooks::HookThreads()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    bShouldBreak = 0; // disable breaking when a debugger is attached
    Console::log(std::hex, EE::Thread::oCreateThread);
    Console::log("EE::Thread::Current ", std::hex, ASLR(0x7E9FE8));
    GetAppLoop();
    // Hook the app loop to get applicationbase struct
    HOOK(ghmGC::File, Read);
    HOOK(, AppLoop);
    HOOK(EE::Thread, CreateThread);
    HOOK(EE::VfsArchive, ReadFile);
    HOOK(EE::VfsArchive, OpenFile);
    HOOK(EE::VfsArchive, AccessFile);
    HOOK(EE::VfsFileZlib,Read);
    HOOK(K7::Graphics, DrawMenuButton);
    HOOK(K7::Graphics, RenderSprite);
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
