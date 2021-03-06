#include "Application.hpp"
#include "../Identifiers.hpp"

const int Application::framesPerSecond = 60;
const sf::Time Application::timePerFrame = sf::seconds(1.0f / framesPerSecond);

Application::Application()
    : window(sf::VideoMode(640, 480, 32), "BR", sf::Style::Default),
    stateStack(State::Context(window, textures, fonts, music, fps))
{
    window.setFramerateLimit(framesPerSecond);
    window.setVerticalSyncEnabled(false);
    window.setKeyRepeatEnabled(false);
}

void Application::run(States::ID initialState, bool timeIndependent)
{
    stateStack.pushState(initialState);
    stateStack.applyPendingChanges();

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        fps.calculateFps(dt);

        do
        {
            timeSinceLastUpdate -= timePerFrame;
            processEvents();
            update(timePerFrame);

            stateStack.applyPendingChanges();

            if (stateStack.isEmpty())
            {
                window.close();
                break;
            }
        } while (timeIndependent && timeSinceLastUpdate > timePerFrame);

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
            else if (event.key.code == sf::Keyboard::F12)
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
