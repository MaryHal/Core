#include "State.hpp"
#include "StateStack.hpp"

State::Context::Context(sf::RenderWindow& window,
                        TextureHolder& textures,
                        FontHolder& fonts,
                        MusicPlayer& music,
                        FpsCounter& fps)
    : window(&window)
    , textures(&textures)
    , fonts(&fonts)
    , music(&music)
    , fps(&fps)
{
}

State::State(StateStack& stack, Context& context)
    : stack(&stack)
    , context(context)
{
}

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{
    stack->pushState(stateID);
}

void State::requestStackPop()
{
    stack->popState();
}

void State::requestStateClear()
{
    stack->clearStates();
}

const State::Context& State::getContext()
{
    return context;
}
