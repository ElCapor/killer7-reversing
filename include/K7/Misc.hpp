#ifndef MISC_HPP
#define MISC_HPP

#include <cstdint>
#include <utils.hpp>
namespace K7
{
    namespace Graphics
    {
        struct MenuButtonDescriptor
        {
            int text_len;
            const char* text;
            void* flag1;
            void* flag2;
            int flag4;
            void* flag5;
        };
        DECLARE_THISCALL_FUNCTION(DrawMenuButton,bool, MenuButtonDescriptor* a2, uint16_t x, uint16_t y, const char* text);
    }
}

#endif /* MISC_HPP */
