#ifndef VFS_HPP
#define VFS_HPP
#include <cstdint>

namespace EE
{
    namespace Vfs
    {
        using ReadFileT = int(__thiscall*)(uintptr_t, int, char*, char*, int);
        extern ReadFileT oReadFile;

        int __fastcall ReadFile(uintptr_t _this, void* unused, int fileIndex, char* a3, char *a4, int a5);
    }
    
} // namespace EE



#endif /* VFS_HPP */
