#ifndef _MusicState_hpp_
#define _MusicState_hpp_

#include "../System/State.hpp"
#include <SFML/Graphics.hpp>
#include "../GUI/Menu.hpp"

class MusicState : public State
{
    public:
    MusicState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

    private:
    sf::Sprite bg;
    Menu menu;
};

#endif // _MusicState_hpp_
