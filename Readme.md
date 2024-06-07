# Killer 7 Reverse engineering

attempting to understand more about how is a commercial game made , and how can i modify it and improve it

This builds as a dll that you can inject at any time in game

ALl of this was reversed by hand without any debug symbols or source codes of the game
# Classes

EE::Threads => Game threads
EE::Vfs => Vfs Archive code = ggame files

K7::Graphics::CMenuTitle => The game's start menu
K7::Graphics::ButtonLetter => a sprite representing the letter of the word