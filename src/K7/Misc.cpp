#include <K7/Misc.hpp>
#include <console.hpp>

using namespace K7::Graphics;
DrawMenuButtonT K7::Graphics::oDrawMenuButton = (DrawMenuButtonT)ASLR(0x5A9380);

bool __fastcall DrawMenuButton(uintptr_t _this, void* unused, uintptr_t a2, uint16_t x, uint16_t y, const char* text)
{
    auto ret = oDrawMenuButton(_this, a2, x, y, text);
    Console::log(__FUNCTION__, " Called with arguments " , std::hex , _this, a2, std::dec, x, y, text);
    return ret;
}
