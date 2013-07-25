#include "Application.hpp"
#include "StateIdentifiers.hpp"

#include "Game/TitleState.hpp"
#include "Game/TestState.hpp"
#include "Game/LoadingState.hpp"

#include <cstdio>

const int Application::framesPerSecond = 60;
const sf::Time Application::timePerFrame = sf::seconds(1.0f / 60.0f);

Application::Application()
    : window(sf::VideoMode(640, 480, 32), "Testing...", sf::Style::Close)
    , stateStack(State::Context(window, textures, fonts, music))
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

    registerStates();
}

void Application::run(States::ID initialState)
{
    stateStack.pushState(States::Title);

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

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
                stateStack.clearStates();
            else if (event.key.code == sf::Keyboard::BackSpace)
                stateStack.popState();
        }
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
    // stateStack.registerState<LoadingState>(States::Loading);
    stateStack.registerState<TitleState>(States::Title);
    stateStack.registerState<TestState>(States::Test);
}
