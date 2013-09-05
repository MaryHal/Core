#include "World.hpp"

World::World()
{
}

void World::update(sf::Time dt)
{
    while (!commands.isEmpty())
    {
        Command command = commands.pop();
        for (auto iter = commands.begin();
                  iter != commands.end();
                  ++iter)
        {
            iter->onCommand(command, dt);
        }
    }
}

