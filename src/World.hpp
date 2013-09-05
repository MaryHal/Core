#ifndef _World_hpp_
#define _World_hpp_

#include <SFML/System/Time.hpp>

#include <list>
#include <memory>

#include "CommandQueue.hpp"
#include "Entity.hpp"

class World
{
    public:
        World();
        void update(sf::Time dt);

    private:
        typedef std::unique_ptr<Entity> EntityPtr;

        std::list<EntityPtr> entityList;
        CommandQueue commands;
};

#endif // _World_hpp_

