#include <EE/Application/ApplicationBase.hpp>
#include <utils.hpp>
#include <console.hpp>
#include <eyestep/eyestep.h>

/*
* ApplicationBase class size : 0x248
* PlatformWindows class size = 0xB8
* 
* Potential way to get the struct :
* hook malloc and check for size ?
* */

uintptr_t EE::ApplicationBase::vtable = ASLR(0x74CC6C);
EE::ApplicationBase::CApplicationBase* EE::ApplicationBase::App = nullptr;

uintptr_t EE::ApplicationBase::GetApplicationBase()
{
    Console::log("Starting Application Scan");
    return 0;
}