#include "Application.hpp"
#include <cstdio>

const int Application::framesPerSecond = 60;
const sf::Time Application::timePerFrame = sf::seconds(1.0f / 60.0f);

Application::Application()
    : window(sf::VideoMode(640, 480), "Testing...", sf::Style::Close)
{
    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(framesPerSecond);

    try
    {
        textures.load(Textures::bg1, "data/bg/Frac1.png");
        fonts.load(Fonts::normal, "data/fonts/DroidSans.ttf");
        fonts.load(Fonts::jp, "data/fonts/ipag.ttf");
    }
    catch (std::runtime_error& e)
    {
        printf("Exception: %s\n", e.what());
    }

    background.setTexture(textures.get(Textures::bg1));
    statText.setFont(fonts.get(Fonts::normal));
    statText.setPosition(5.0f, 5.0f);
    statText.setCharacterSize(16);
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        // timeSinceLastUpdate += dt;
        // printf("%.4f\n", timeSinceLastUpdate.asSeconds());

        // while (timeSinceLastUpdate > timePerFrame)
        // {
        //     timeSinceLastUpdate -= timePerFrame;
        //     processEvents();
        //     update(timePerFrame);
        // }
        processEvents();
        update(dt);

        calculateStatistics(dt);
        render();
    }
}

void Application::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}

void Application::update(sf::Time deltaTime)
{
}

void Application::render()
{
    window.clear();
    window.draw(background);
    window.draw(statText);
    window.display();
}

void Application::calculateStatistics(sf::Time elapsedTime)
{
    statUpdateTime += elapsedTime;
    statFrameCount += 1;

    if (statUpdateTime >= sf::seconds(1.0f))
    {
        statText.setString(
            "Frames / Second = " + std::to_string(statFrameCount) + "\n" +
            "Time / Update = " + std::to_string(statUpdateTime.asMicroseconds() / statFrameCount) + "us");
        statUpdateTime -= sf::seconds(1.0f);
        statFrameCount = 0;
    }
}
