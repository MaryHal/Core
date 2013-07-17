#ifndef _Application_hpp_
#define _Application_hpp_

#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

#include "MusicPlayer.hpp"

class Application
{
    public:
    Application();
    void run();

    private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    void calculateStatistics(sf::Time elapsedTime);

    private:
    sf::RenderWindow window;

    MusicPlayer musicPlayer;

    TextureHolder textures;
    sf::Sprite background;

    FontHolder fonts;
    sf::Text statText;
    sf::Time statUpdateTime;
    std::size_t statFrameCount;

    static const int framesPerSecond;
    static const sf::Time timePerFrame;
};

#endif // _Application_hpp_
