#include <K7/Misc.hpp>
#include <console.hpp>

K7::Graphics::DrawMenuButtonT K7::Graphics::oDrawMenuButton = (K7::Graphics::DrawMenuButtonT)ASLR(0x5A9380);


bool isAdded = false;
bool __fastcall K7::Graphics::DrawMenuButton(uintptr_t _this, void* unused, MenuButtonDescriptor* a2, uint16_t x, uint16_t y, const char* text)
{
    auto ret = oDrawMenuButton(_this, a2, x, y, text);
    if (!isAdded && strcmp(text, "NEW GAME") == 0)
    {
        auto ctitle = (CMenuTitle*)_this;
        Console::log(ctitle->GameState);   
        ctitle->color1.r = 0x00;
        ctitle->color1.g = 0xFF;
        ctitle->color1.b = 0x00;
    }
    Console::log(__FUNCTION__, " Called with arguments " , std::hex , _this, a2, std::dec, x, y, text);
    return ret;
}
