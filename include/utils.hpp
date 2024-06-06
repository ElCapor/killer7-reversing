#ifndef UTILS_HPP
#define UTILS_HPP
#include <windows.h>
#define ASLR(x)(x - 0x400000 + (DWORD)GetModuleHandleA(0))

#endif /* UTILS_HPP */
