#include "TestState.hpp"

#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include "../Utils/StringUtils.hpp"
#include "../Utils/Log.hpp"

TestState::TestState(StateStack& stack, Context context)
    : State(stack, context)
{
    bg.setTexture(context.textures->get(Res::Textures::bg2));

    const sf::Font& font = context.fonts->get(Res::Fonts::normal);
    debugText.setFont(font);
    debugText.setPosition(8.0f, 8.0f);
    debugText.setCharacterSize(11);

    Mover origin(320.0, 120.0, 0.0, 0.0);
    Mover target(320.0, 320.0, 0.0, 0.0);
    manager.createBullet("data/lua/test.lua", &origin, &target);
}

void TestState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    window.draw(bg);

    window.draw(manager);
    window.draw(debugText);
}

bool TestState::update(sf::Time dt)
{
    debugText.setString(formatString("Fps: %d\nBullets: %d\nFree: %d\nBlocks: %d",
                                     getContext().fps->getFps(),
                                     manager.bulletCount(),
                                     manager.freeCount(),
                                     manager.blockCount()));
    manager.tick();
    return false;
}

bool TestState::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
    }
    return false;
}

