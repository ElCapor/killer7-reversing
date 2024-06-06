#ifndef CTITLEMENU_HPP
#define CTITLEMENU_HPP
#include <cstdint>
namespace K7
{
    namespace Graphics
    {
        struct CMenuTitle
        {
            char pad_0000[7840]; //0x0000
	        int32_t GameState; //0x1EA0
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
