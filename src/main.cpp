#include "System/Application.hpp"

#include "Game/TitleState.hpp"
#include "Game/TestState.hpp"
#include "Game/LoadingState.hpp"
#include "Game/PatternState.hpp"
#include "Game/MusicState.hpp"

class MyApp : public Application
{
    public:
        MyApp()
            : Application()
        {
            registerStates();
        }

        virtual void registerStates()
        {
            // stateStack.registerState<LoadingState>(States::Loading);
            stateStack.registerState<TitleState>(States::Title);
            stateStack.registerState<TestState>(States::Test);
            stateStack.registerState<PatternState>(States::Pattern);
            stateStack.registerState<MusicState>(States::Music);
        }
};

int main(int argc, char* argv[])
{
    MyApp app;
    app.run(States::Title);

    return 0;
}

