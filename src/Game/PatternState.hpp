#ifndef _PatternState_hpp_
#define _PatternState_hpp_

#include "../System/State.hpp"
#include <SFML/Graphics.hpp>

#include "../GUI/Menu.hpp"

#include <vector>
#include "../Utils/MakeUnique.hpp"

class PatternState : public State
{
    public:
        PatternState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);

    private:
        sf::Text debugText;
};

#endif // _PatternState_hpp_

