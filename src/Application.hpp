#ifndef _Application_hpp_
#define _Application_hpp_

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "MusicPlayer.hpp"

#include "StateStack.hpp"

#include <SFML/Graphics.hpp>

class Application
{
    public:
        Application();
        void run(States::ID initialState);

    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();

        void calculateFps(sf::Time elapsedTime);
        void registerStates();

    private:
        sf::RenderWindow window;
        StateStack stateStack;

        TextureHolder textures;
        FontHolder fonts;
        MusicPlayer music;

        sf::Text statText;
        sf::Time statUpdateTime;
        std::size_t statFrameCount;

        static const int framesPerSecond;
        static const sf::Time timePerFrame;
};

#endif // _Application_hpp_
