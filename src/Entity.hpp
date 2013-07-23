#ifndef _Entity_hpp_
#define _Entity_hpp_

// #include "Command.hpp"
#include <SFML/Graphics/Drawable.hpp>

class Entity : public sf::Drawable
{
    public:
    // void onCommand(const Command& command, sf::Time dt);

    private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // _Entity_hpp_
