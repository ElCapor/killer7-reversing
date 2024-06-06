#ifndef THREADS_HPP
#define THREADS_HPP
#include <cstdint>

namespace EE
{
    namespace Thread
    {
        using CreateThreadT = bool(__thiscall*)(uintptr_t, int, int, bool, bool, uintptr_t);
        extern CreateThreadT oCreateThread;
        bool __fastcall CreateThread(uintptr_t thread_structure,void*, int threadFunction, int _this, bool a4, bool a5, uintptr_t a6);
    }
}

#endif /* THREADS_HPP */
