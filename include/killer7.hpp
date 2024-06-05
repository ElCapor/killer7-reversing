#ifndef KILLER7_HPP
#define KILLER7_HPP
#include <Windows.h>

namespace killer7
{
    DWORD WINAPI MainThread();
    DWORD WINAPI EjectSelf();
    void shutdown();
}

#endif /* KILLER7_HPP */
