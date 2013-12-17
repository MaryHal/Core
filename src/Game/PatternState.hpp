#ifndef _PatternState_hpp_
#define _PatternState_hpp_

#include "../System/State.hpp"
#include <SFML/Graphics.hpp>

class PatternState : public State
{
    public:
    PatternState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

    private:
};

#endif // _PatternState_hpp_

