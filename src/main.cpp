#include "System/Application.hpp"

#include "Game/TitleState.hpp"
#include "Game/TestState.hpp"
#include "Game/LoadingState.hpp"

class MyApp : public Application
{
    public:
        MyApp()
        {
            registerStates();
        }

        virtual void registerStates()
        {
            // stateStack.registerState<LoadingState>(States::Loading);
            stateStack.registerState<TitleState>(States::Title);
            stateStack.registerState<TestState>(States::Test);
        }
};

int main(int argc, char* argv[])
{
    MyApp app;
    app.run(States::Title);

    return 0;
}

