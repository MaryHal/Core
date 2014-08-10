#include "TestState.hpp"

#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include "../Utils/Log.hpp"

TestState::TestState(StateStack& stack, Context context)
    : State(stack, context)
{
    bg.setTexture(context.textures->get(Res::Textures::bg2));

    Mover origin(320.0, 120.0, 0.0, 0.0);
    Mover target(320.0, 320.0, 0.0, 0.0);
    manager.createBullet("data/lua/test.lua", &origin, &target);
}

void TestState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.draw(bg);
    window.draw(manager);
}

bool TestState::update(sf::Time dt)
{
    manager.tick();
    manager.printSizes();
    return false;
}

bool TestState::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
    }
    return false;
}
