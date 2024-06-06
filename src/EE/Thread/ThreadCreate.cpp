#include "EE/Thread/Threads.hpp"
#include <utils.hpp>
#include <console.hpp>
EE::Thread::CreateThreadT EE::Thread::oCreateThread = (EE::Thread::CreateThreadT)ASLR(0x4233F0);

bool __fastcall EE::Thread::CreateThread(uintptr_t thread_structure,void* unused, int threadFunction, int _this, bool a4, bool a5, ThreadCreateArgs* a6)
{
    Console::log(__FUNCTION__, " Called with arguments ", std::hex, thread_structure, threadFunction, _this, a4, a5, a6);
    Console::log("New thread created ", a6->thread_name);
    return oCreateThread(thread_structure, threadFunction, _this, a4, a5, a6);
}