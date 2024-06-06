#include "EE/Thread/Threads.hpp"
#include <utils.hpp>
#include <console.hpp>
EE::Thread::CreateThreadT EE::Thread::oCreateThread = (EE::Thread::CreateThreadT)ASLR(0x4233F0);

bool __fastcall EE::Thread::CreateThread(uintptr_t thread_structure,void* unused, int threadFunction, int _this, bool a4, bool a5, uintptr_t a6)
{
    Console::log(__FUNCTION__, " Called with arguments ", std::hex, thread_structure, threadFunction, _this, a4, a5, a6);
    return oCreateThread(thread_structure, threadFunction, _this, a4, a5, a6);
}