#ifndef _Command_hpp_
#define _Command_hpp_

#include <functional>
#include <SFML/System/Time.hpp>
#include "Category.hpp"

class Entity;

struct Command
{
    public:
    typedef std::function<void(Entity&, sf::Time)> Action;

    public:
    Command();
    Action action;
    Category category;
};

#endif // _Command_hpp_

