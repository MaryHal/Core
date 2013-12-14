#include "TestState.hpp"

#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

TestState::TestState(StateStack& stack, Context context)
    : State(stack, context)
{
    bg.setTexture(context.textures->get(Res::Textures::bg2));
}

void TestState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.draw(bg);
}

bool TestState::update(sf::Time dt)
{
    return false;
}

bool TestState::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
    }
    return false;
}
