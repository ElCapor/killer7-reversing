#ifndef VFS_HPP
#define VFS_HPP
#include <cstdint>
#include <utils.hpp>
namespace EE
{
    namespace VfsArchive
    {
        DECLARE_THISCALL_FUNCTION(AccessFile, bool, char* src, uintptr_t a3, uintptr_t a4, uintptr_t a5);
        DECLARE_THISCALL_FUNCTION(ReadFile, int, int fileIndex, char* a3, char *a4, int a5);
        DECLARE_THISCALL_FUNCTION(OpenFile,int*, int* a2, int fileIndex);
    }
    
    namespace VfsFileZlib
    {
        DECLARE_THISCALL_FUNCTION(Read, int, int a2, int a3);
    }
} // namespace EE



#endif /* VFS_HPP */
