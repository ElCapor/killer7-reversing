# Killer 7 Reverse engineering

attempting to understand more about how is a commercial game made , and how can i modify it and improve it

This builds as a dll that you can inject at any time in game

All of this was reversed by hand without any debug symbols or source codes of the game, only with ida pro , x86dbg and this dll
# Classes

EE::Threads => Game threads
EE::Vfs => Vfs Archive code = game files

K7::Graphics::CMenuTitle => The game's start menu
K7::Graphics::ButtonLetter => a sprite representing the letter of the word

# cool notes

object + 0x4 = refcount
object + 0x0 = vtable
vtable + 0x0 = destructor

the game detects when u have a debugger and traps you, so u can try and nop out _scrt_fast_fail , but after that the game wont run idk why yet (i think the CrashReport thread fails to start), i need to find a way to disable their exception handler once for all

there's a boolean that tells the game if it should break when a debugger is on or not

their allocator defaults empty structs to 0xBAADF00D

they use too much templates fr

99% of funcs are direct vtable calls, this bothers me lol, maybe i should try using class informer ?
because rn i have to manually go to one func, then find it back by assembly in ida, so i have to do it dynamically each time, for example this made it very hard to even follow the entry point of the program, because it's all vtable calls, so you gotta find the window struct dynamically (after patching the above debug stuff)

# TODO
[ ] - Stop using hardcoded addresses (patterns instead)
[ ] - Make a vtable template struct (for easier manipulation etc)

# DOING RN
-> Reversing VFS archive format
-> Reversing Graphics Engine
-> Reversing startup routines