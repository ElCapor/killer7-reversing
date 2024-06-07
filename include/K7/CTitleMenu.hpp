#ifndef CTITLEMENU_HPP
#define CTITLEMENU_HPP
#include <cstdint>
namespace K7
{
    namespace Graphics
    {
        struct Color
        {
            uint8_t a;
            uint8_t b;
            uint8_t g;
            uint8_t r;
        };

        // 0075575C
        class mk7sprite
        {
            uintptr_t vtable[7]; // 6 is render
            char pad[24];
            uint16_t width;
            uint16_t height;
        };

        DECLARE_THISCALL_FUNCTION(RenderSprite, int);

        struct MenuButtonDescriptor
        {
            int text_len;
            const char* text;
            void* flag1;
            void* flag2;
            int flag4;
            void* flag5;
        };

        

        struct CMenuTitle
        {
            char pad_0000[7736]; //0x0000
            MenuButtonDescriptor PressStartButton;
            MenuButtonDescriptor ContinueButton;
            MenuButtonDescriptor OptionsButton;
            MenuButtonDescriptor ExitButton;
            char pad_1E98[8]; //0x1E98
	        int32_t GameState; //0x1EA0
            int32_t SelectedButtonIndex; //0x1EA4
	        char pad_1EA8[31320]; //0x1EA8
            Color color1; // hover color ?
            Color color2; // idle color ??

            /*
            * STATES : 0x0 = PRESS START
            * STATES : 0x2 = MENU TITLE
            * STATES : 0x5 = NEW GAME
            * STATES : 0x6 = INSIDE GAME
            * MENU IS DELETED WHEN GAME IS STARTED
            * */
        };
    }
}

#endif /* CTITLEMENU_HPP */
