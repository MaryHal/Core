#include "Application.hpp"
#include <cstdio>

const int Application::framesPerSecond = 60;
const sf::Time Application::timePerFrame = sf::seconds(1.0f / 60.0f);

Application::Application()
    : window(sf::VideoMode(640, 480, 32), "Testing...", sf::Style::Close),
      world(window.getDefaultView()),
      statUpdateTime(),
      statFrameCount(0)
{
    window.setFramerateLimit(framesPerSecond);
    window.setVerticalSyncEnabled(false);
    window.setKeyRepeatEnabled(false);

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
    statText.setCharacterSize(12);
    statText.setString(
            "Frames / Second = \nTime / Update = ");

    stuff.setFont(fonts.get(Fonts::jp));
    stuff.setPosition(5.0f, 100.0f);
    stuff.setCharacterSize(32);
    stuff.setString(L"我是美国人.\n私はアメリカ人です.");
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
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            world.rotate(-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            world.rotate(1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            world.zoom(0.99);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            world.zoom(1.01);

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        //     world.move(-1, 0);
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        //     world.move(0, 1);
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        //     world.move(0, -1);
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        //     world.move(1, 0);

        calculateFps(dt);
        render();
    }
}

void Application::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Application::update(sf::Time deltaTime)
{
}

void Application::render()
{
    window.setView(world);

    window.clear();
    window.draw(background);
    window.draw(statText);
    window.draw(stuff);
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
