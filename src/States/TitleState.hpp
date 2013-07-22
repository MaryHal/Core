#ifndef _TitleState_hpp_
#define _TitleState_hpp_

#include "../State.hpp"

#include <SFML/Graphics.hpp>

class TitleState : public State
{
    public:
    TitleState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

    private:
    sf::Sprite background;
};

#endif // _TitleState_hpp_
