#include <EE/Vfs/Vfs.hpp>
#include <utils.hpp>
#include <console.hpp>

EE::VfsArchive::ReadFileT EE::VfsArchive::oReadFile = (EE::VfsArchive::ReadFileT)ASLR(0x42D660);
EE::VfsArchive::OpenFileT EE::VfsArchive::oOpenFile = (EE::VfsArchive::OpenFileT)ASLR(0x42B8E0);
EE::VfsArchive::AccessFileT EE::VfsArchive::oAccessFile = (EE::VfsArchive::AccessFileT)ASLR(0x4213F0);

int __fastcall EE::VfsArchive::ReadFile(uintptr_t _this, void *unused, int fileIndex, char *a3, char *a4, int a5)
{
    auto ret = oReadFile(_this, fileIndex, a3, a4, a5);
    //Console::log(__FUNCTION__, " Called with arguments ", std::hex, _this, fileIndex, a3, a4, a5, " Returns ", ret);
    Console::log(__FUNCTION__, " Called with index ", std::dec, fileIndex, " Returns : ", ret);
    return ret;
}

int* __fastcall EE::VfsArchive::OpenFile(uintptr_t _this, void *unused, int *a2, int fileIndex)
{
    auto ret = EE::VfsArchive::oOpenFile(_this, a2, fileIndex);
    Console::log(__FUNCTION__, " Called with arguments, archive = ", std::hex , _this, "a2", a2, std::dec, " file index ", fileIndex, "return ", std::hex, ret);
    return ret;
}

bool __fastcall EE::VfsArchive::AccessFile(uintptr_t _this, void *unused, char *src, uintptr_t a3, uintptr_t a4, uintptr_t a5)
{
    auto ret = oAccessFile(_this, src, a3, a4, a5);
    Console::log(__FUNCTION__, " Called with arguments ", std::hex, _this, a3, a4, a5);
    Console::log(strdup(src));
    return ret;
}


EE::VfsFileZlib::ReadT EE::VfsFileZlib::oRead = (EE::VfsFileZlib::ReadT)ASLR(0x42D160);

int __fastcall EE::VfsFileZlib::Read(uintptr_t _this, void* unused, int a2, int a3)
{
    auto ret = oRead(_this, a2, a3);
    Console::log(__FUNCTION__, " Called with arguments ", std::hex, _this, a2, a3, " returns ", ret);
    return ret;
}