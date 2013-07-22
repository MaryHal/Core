#include "Application.hpp"
#include "StateIdentifiers.hpp"

#include "States/TitleState.hpp"

#include <cstdio>

const int Application::framesPerSecond = 60;
const sf::Time Application::timePerFrame = sf::seconds(1.0f / 60.0f);

Application::Application()
    : window(sf::VideoMode(640, 480, 32), "Testing...", sf::Style::Close)
    , stateStack(State::Context(window, textures, fonts))
    , statUpdateTime()
    , statFrameCount(0)
{
    window.setFramerateLimit(framesPerSecond);
    window.setVerticalSyncEnabled(false);
    window.setKeyRepeatEnabled(false);

    try
    {
        fonts.load(Res::Fonts::normal, "data/fonts/DroidSans.ttf");
        fonts.load(Res::Fonts::jp, "data/fonts/ipag.ttf");
    }
    catch (std::runtime_error& e)
    {
        printf("Exception: %s\n", e.what());
    }

    statText.setFont(fonts.get(Res::Fonts::normal));
    statText.setPosition(5.0f, 5.0f);
    statText.setCharacterSize(12);
    statText.setString(
            "Frames / Second = \nTime / Update = ");

    // background.setTexture(textures.get(Res::Textures::bg1));

    // stuff.setFont(fonts.get(Res::Fonts::jp));
    // stuff.setPosition(5.0f, 100.0f);
    // stuff.setCharacterSize(32);
    // stuff.setString(L"我是美国人.\n私はアメリカ人です.");

    registerStates();
    stateStack.pushState(States::Title);
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
            processEvents();
            update(timePerFrame);

            if (stateStack.isEmpty())
                window.close();
        }

        calculateFps(dt);
        render();
    }
}

void Application::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        stateStack.handleEvent(event);

        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Application::update(sf::Time deltaTime)
{
    stateStack.update(deltaTime);
}

void Application::render()
{
    window.clear();
    stateStack.draw();
    window.draw(statText);
    window.display();
}

void Application::calculateFps(sf::Time elapsedTime)
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

void Application::registerStates()
{
    stateStack.registerState<TitleState>(States::Title);
}
