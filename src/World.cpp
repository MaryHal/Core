#include "World.hpp"

World::World()
{
}

void World::update(sf::Time dt)
{
    while (!commands.isEmpty())
    {
        Command command = commands.pop();
        for (auto iter = entityList.begin();
                  iter != entityList.end();
                  ++iter)
        {
            (*iter)->onCommand(command, dt);
        }
    }
}

