#ifndef MISC_HPP
#define MISC_HPP

#include <cstdint>
#include <utils.hpp>
#include <K7/CTitleMenu.hpp>
namespace K7
{
    namespace Graphics
    {
        DECLARE_THISCALL_FUNCTION(DrawMenuButton,bool, MenuButtonDescriptor* a2, uint16_t x, uint16_t y, const char* text);
    }
}

#endif /* MISC_HPP */
