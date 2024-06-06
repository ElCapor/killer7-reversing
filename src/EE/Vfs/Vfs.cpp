#include <EE/Vfs/Vfs.hpp>
#include <utils.hpp>
#include <console.hpp>

EE::Vfs::ReadFileT EE::Vfs::oReadFile = (EE::Vfs::ReadFileT)ASLR(0x42D660);

int __fastcall EE::Vfs::ReadFile(uintptr_t _this, void *unused, int fileIndex, char *a3, char *a4, int a5)
{
    auto ret = oReadFile(_this, fileIndex, a3, a4, a5);
    //Console::log(__FUNCTION__, " Called with arguments ", std::hex, _this, fileIndex, a3, a4, a5, " Returns ", ret);
    Console::log(__FUNCTION__, " Called with index ", std::dec, fileIndex);
    return ret;
}