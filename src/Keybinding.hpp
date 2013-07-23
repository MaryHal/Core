#ifndef _Keybinding_hpp_
#define _Keybinding_hpp_

#include <SFML/Window/Keyboard.hpp>
#include <map>

#include "Command.hpp"

class Keybinding
{
    public:
    explicit Keybinding();

    private:
    std::map<sf::Keyboard::Key, Command> keymap;
};

#endif // _Keybinding_hpp_










