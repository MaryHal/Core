#ifndef _StateStack_hpp_
#define _StateStack_hpp_

#include "State.hpp"
#include "ResourceIdentifiers.hpp"
#include "../Identifiers.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

#include <vector>
#include <utility>
#include <functional>
#include <map>

namespace sf
{
    class Event;
    class RenderWindow;
}

class StateStack : private sf::NonCopyable
{
    public:
        enum class Action { Push, Pop, Clear };

    public:
        explicit StateStack(State::Context context);

        template <typename T>
            void registerState(States::ID stateID);

        void update(sf::Time dt);
        void draw();
        void handleEvent(const sf::Event& event);

        void pushState(States::ID stateID);
        void popState();
        void clearStates();

        bool isEmpty() const;
        void applyPendingChanges();

    private:
        State::Ptr createState(States::ID stateID);

    private:
        struct PendingChange
        {
            explicit PendingChange(Action action, States::ID stateID = States::None);

            Action action;
            States::ID stateID;
        };

    private:
        std::vector<State::Ptr> stack;
        std::vector<PendingChange> pendingChangeList;

        State::Context stateContext;
        std::map<States::ID, std::function<State::Ptr()>> stateFactory;
};


    template <typename T>
void StateStack::registerState(States::ID stateID)
{
    stateFactory[stateID] = [this] ()
    {
        return State::Ptr(new T(*this, stateContext));
    };
}

#endif // _StateStack_hpp_

