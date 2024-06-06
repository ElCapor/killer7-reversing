#ifndef THREADS_HPP
#define THREADS_HPP
#include <cstdint>

namespace EE
{
    namespace Thread
    {
        struct ThreadCreateArgs
        {
            int flag1;
            int flag2;
            const char* thread_name;
            int flag3;
        };

        using CreateThreadT = bool(__thiscall*)(uintptr_t, int, int, bool, bool, ThreadCreateArgs*);
        extern CreateThreadT oCreateThread;
        bool __fastcall CreateThread(uintptr_t thread_structure,void*, int threadFunction, int _this, bool a4, bool a5, ThreadCreateArgs* a6);
    }
}

#endif /* THREADS_HPP */
