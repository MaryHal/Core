#include "Application.hpp"
#include "../Identifiers.hpp"

const int Application::framesPerSecond = 60;
const sf::Time Application::timePerFrame = sf::seconds(1.0f / 60.0f);

Application::Application()
    : window(sf::VideoMode(640, 480, 32), "Testing...", sf::Style::Close),
    stateStack(State::Context(window, textures, fonts, music))
{
    window.setFramerateLimit(framesPerSecond);
    window.setVerticalSyncEnabled(false);
    window.setKeyRepeatEnabled(false);
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
    window.display();
}

