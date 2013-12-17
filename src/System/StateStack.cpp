#include "StateStack.hpp"

#include "../Utils/Log.hpp"

StateStack::StateStack(State::Context context)
    : stack()
    , pendingChangeList()
    , stateContext(context)
    , stateFactory()
{
}

void StateStack::update(sf::Time dt)
{
    // Iterate from top to bottom, stop as soon as update() returns false
    // for (auto iter = stack.rbegin(); iter != stack.rend(); ++iter)
    // {
    //     if (!(*iter)->update(dt))
    //         break;
    // }

    // Just update the last thing
    if (!stack.empty())
        stack.back()->update(dt);
}

void StateStack::draw()
{
    // Draw all active states from bottom to top
    // for (State::Ptr& state : stack)
    //     state->draw();

    // Just draw the last thing
    if (!stack.empty())
        stack.back()->draw();
}

void StateStack::handleEvent(const sf::Event& event)
{
    // Iterate from top to bottom, stop as soon as handleEvent() returns false
    // for (auto iter = stack.rbegin(); iter != stack.rend(); ++iter)
    // {
    //     if (!(*iter)->handleEvent(event))
    //         break;
    // }

    // Just handle the last thing
    if (!stack.empty())
        stack.back()->handleEvent(event);
}

void StateStack::pushState(States::ID stateID)
{
    pendingChangeList.push_back(PendingChange(Action::Push, stateID));
}

void StateStack::popState()
{
    pendingChangeList.push_back(PendingChange(Action::Pop));
}

void StateStack::clearStates()
{
    pendingChangeList.push_back(PendingChange(Action::Clear));
}

bool StateStack::isEmpty() const
{
    return stack.empty();
}

State::Ptr StateStack::createState(States::ID stateID)
{
    auto found = stateFactory.find(stateID);
    pAssert(found != stateFactory.end(), "State not found");

    return found->second();
}

void StateStack::applyPendingChanges()
{
    for (PendingChange change : pendingChangeList)
    {
        switch (change.action)
        {
        case Action::Push:
            stack.push_back(createState(change.stateID));
            break;

        case Action::Pop:
            stack.pop_back();
            break;

        case Action::Clear:
            stack.clear();
            break;
        }
    }

    pendingChangeList.clear();
}

StateStack::PendingChange::PendingChange(Action action, States::ID stateID)
    : action(action)
    , stateID(stateID)
{
}

