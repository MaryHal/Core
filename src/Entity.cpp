#include "Entity.hpp"
#include "Command.hpp"

Entity::Entity(Category c)
    : category(c)
{
}

void Entity::onCommand(const Command& command, sf::Time dt)
{
    if (category & command.category)
        command.action(*this, dt);
}

Category Entity::getCategory() const
{
    return category;
}


void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}


