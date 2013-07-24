#ifndef _LoadingState_hpp_
#define _LoadingState_hpp_

#include "../State.hpp"
#include "../ParallelTask.hpp"
#include <SFML/Graphics.hpp>

class LoadingState : public State
{
    public:
    LoadingState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

    private:
    sf::Text loadingText;
    ParallelTask task;
};

#endif // _LoadingState_hpp_
