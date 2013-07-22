#include "TitleState.hpp"
#include "../ResourceHolder.hpp"
#include "../ResourceIdentifiers.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

TitleState::TitleState(StateStack& stack, Context context)
    : State(stack, context)
{
    context.textures->load(Res::Textures::bg1, "data/bg/Frac2.png");
    background.setTexture(context.textures->get(Res::Textures::bg1));
}

void TitleState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.draw(background);
}

bool TitleState::update(sf::Time dt)
{
    return true;
}

bool TitleState::handleEvent(const sf::Event& event)
{
    return true;
}
