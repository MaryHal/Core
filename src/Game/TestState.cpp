#include "TestState.hpp"

#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include "../Utils/StringUtils.hpp"
#include "../Utils/Log.hpp"

TestState::TestState(StateStack& stack, Context context)
    : State(stack, context)
{
    try
    {
    }
    catch (std::runtime_error& e)
    {
        Console::logf("Resource loading block failed: %s", e.what());
    }

    bg.setTexture(context.textures->get(Res::Textures::bg2));
}

void TestState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    window.draw(bg);
    window.draw(player);
}

bool TestState::update(sf::Time dt)
{
    player.update(dt);
    return false;
}

bool TestState::handleEvent(const sf::Event& event)
{
    player.handleEvent(event);
    return false;
}
