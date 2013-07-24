#include "LoadingState.hpp"

LoadingState::LoadingState(StateStack& stack, Context context)
    : State(stack, context)
{
    task.execute();
    loadingText.setString("Hello");
}

void LoadingState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    window.draw(loadingText);
}

bool LoadingState::update(sf::Time dt)
{
    // Update the progress bar from the remote task or finish it
    if (task.isFinished())
    {
        requestStackPop();
        requestStackPush(States::Title);
    }
    else
    {
        loadingText.setString(std::to_string(task.getCompletion()));
    }
    return false;
}

bool LoadingState::handleEvent(const sf::Event& event)
{
    return false;
}
