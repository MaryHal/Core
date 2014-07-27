#ifndef _Application_hpp_
#define _Application_hpp_

#include "ResourceIdentifiers.hpp"
#include "../Audio/MusicPlayer.hpp"
#include "../Utils/FpsCounter.hpp"

#include "StateStack.hpp"

#include <SFML/Graphics.hpp>

class Application
{
    public:
        Application();
        void run(States::ID initialState);
        virtual void registerStates() = 0;

    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();

    protected:
        sf::RenderWindow window;
        StateStack stateStack;

        TextureHolder textures;
        FontHolder fonts;
        MusicPlayer music;
        FpsCounter fps;

        static const int framesPerSecond;
        static const sf::Time timePerFrame;
};

#endif // _Application_hpp_

