#ifndef _TestState_hpp_
#define _TestState_hpp_

#include "../Utils/MakeUnique.hpp"

#include "../System/State.hpp"
#include <SFML/Graphics.hpp>

#include "Platformer/Player.hpp"

class TestState : public State
{
    public:
        TestState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);

    private:
        sf::Sprite bg;
        Player player;
};

#endif // _TestState_hpp_
