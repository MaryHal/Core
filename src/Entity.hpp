#ifndef _Entity_hpp_
#define _Entity_hpp_

// #include "Command.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

#include "Category.hpp"

struct Command;

class Entity : public sf::Transformable, public sf::Drawable,
               private sf::NonCopyable
{
    public:
        Entity(Category c);
        virtual ~Entity() {};

        void onCommand(const Command& command, sf::Time dt);
        Category getCategory() const;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        Category category;
};

#endif // _Entity_hpp_
