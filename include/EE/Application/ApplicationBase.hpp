#ifndef APPLICATIONBASE_HPP
#define APPLICATIONBASE_HPP
#include <cstdint>
namespace EE
{
    namespace ApplicationBase
    {
        struct CApplicationBase
        {

        };

        extern CApplicationBase* App;
        extern uintptr_t vtable;

        /// @brief Perform a memory scan to find ApplicationBase in memory
        /// @return ApplicationBase memory pointer
        uintptr_t GetApplicationBase();
    }
}

#endif /* APPLICATIONBASE_HPP */
