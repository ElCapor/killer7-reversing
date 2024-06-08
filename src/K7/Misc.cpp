#include <K7/Misc.hpp>
#include <console.hpp>
#include <vector>

K7::Graphics::DrawMenuButtonT K7::Graphics::oDrawMenuButton = (K7::Graphics::DrawMenuButtonT)ASLR(0x5A9380);

// Set the color of each letter in the button
void sub_5A9930(uintptr_t a1, K7::Graphics::Color a2)
{
    if (a1 != 0)
    {
        int counter = 0;
        int v4 = 0; // current letter index
        do {
            ++counter;
            uintptr_t v5 = v4 + *(uintptr_t*)(a1 + 8);
            v4 += 0x128; // sizeof(ButtonLetter)
            Console::log("Got letter ", std::hex, v5);

        } while (counter < *(uint32_t*)a1); // *a1 holds the len of the word
    } else {
        Console::error("a1 was null");
    }
}

bool isAdded = false;
bool __fastcall K7::Graphics::DrawMenuButton(uintptr_t _this, void* unused, MenuButtonDescriptor* a2, uint16_t x, uint16_t y, const char* text)
{
    auto ret = oDrawMenuButton(_this, a2, x, y, text);
    if (!isAdded && strcmp(text, "NEW GAME") == 0)
    {
        auto ctitle = (CMenuTitle*)_this;
        Console::log(ctitle->GameState);
        sub_5A9930((uintptr_t)a2, ctitle->color1);
        

    }
    Console::log(__FUNCTION__, " Called with arguments " , std::hex , _this, a2, std::dec, x, y, text);
    return ret;
}

std::vector<uintptr_t> vLetters;

template <typename T>
bool isInVector(std::vector<T> vec, T target)
{
    for (auto& elem : vec)
    {
        if (elem == target)
            return true;
    }
    return false;
}

// this is located at 0x11C offset of any sprite
K7::Graphics::RenderSpriteT K7::Graphics::oRenderSprite  = (K7::Graphics::RenderSpriteT)ASLR(0x4A6250);
int __fastcall K7::Graphics::RenderSprite(uintptr_t _this, void* unused)
{
    auto ret = oRenderSprite(_this);
    if (!isInVector<uintptr_t>(vLetters, _this))
    {
        vLetters.push_back(_this);
        Console::log("Render sprite called : ", std::hex , _this);
    }
        
    //Console::log("Render letter called : ", std::hex , _this);

    return ret;
}