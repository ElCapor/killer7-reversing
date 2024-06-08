#ifndef UTILS_HPP
#define UTILS_HPP
#include <windows.h>
#define ASLR(x)(x - 0x400000 + (DWORD)GetModuleHandleA(0))
#include <cstdint>
#define DECLARE_THISCALL_FUNCTION(function_name, return_type, ...) \
    using function_name##T = return_type(__thiscall*)(uintptr_t _this, __VA_ARGS__); \
    extern function_name##T o##function_name; \
    return_type __fastcall function_name(uintptr_t _this, void* unused, __VA_ARGS__);


template<typename T> T& GetRef(uint32_t addr)
{
    return *reinterpret_cast<T*>(ASLR(addr));
}

template <typename T> T Read(uintptr_t address)
{
    return *(T*)address;
}
#endif /* UTILS_HPP */
