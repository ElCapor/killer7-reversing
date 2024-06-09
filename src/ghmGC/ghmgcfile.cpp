#include <ghmGC/ghmgcfile.hpp>
#include <console.hpp>
ghmGC::File::ReadT ghmGC::File::oRead = (ghmGC::File::ReadT)ASLR(0x4A4520);

void* __fastcall ghmGC::File::Read(uintptr_t _this, void* unused, int a2, int a3, void* a4)
{
    auto ret = oRead(_this, a2, a3, a4);
    Console::log(__FUNCTION__, " Called with File ", std::hex, _this, "Arguments", a2, a3, a4);
    return ret;
}