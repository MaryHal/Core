#include "TitleState.hpp"
#include "../ResourceHolder.hpp"
#include "../ResourceIdentifiers.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

TitleState::TitleState(StateStack& stack, Context context)
    : State(stack, context)
{
    world = context.window->getDefaultView();

    context.textures->load(Res::Textures::bg1, "data/bg/Frac2.png");
    context.textures->load(Res::Textures::bg2, "data/bg/Frac3.png");

    bg.setTexture(context.textures->get(Res::Textures::bg1));

    text.setFont(context.fonts->get(Res::Fonts::jp));
    text.setPosition(5.0f, 100.0f);
    text.setCharacterSize(32);
    text.setString(L"我是美国人.\n私はアメリカ人です.");

    menu.setPosition(64.0f, 300.0f);
    menu.addItem({L"Hello"});
    menu.addItem({L"你好"});
    menu.addItem({L"今日は"});
    menu.build(context.fonts->get(Res::Fonts::jp));
}

void TitleState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.setView(world);

    window.draw(bg);
    window.draw(menu);

    window.draw(text);
}

bool TitleState::update(sf::Time dt)
{
    menu.update(dt);
    return false;
}

bool TitleState::handleEvent(const sf::Event& event)
{
    menu.handleEvent(event);

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Space)
            getContext().music->play(Res::Music::other);
        else if (event.key.code == sf::Keyboard::Z)
            getContext().music->pause();
        else if (event.key.code == sf::Keyboard::T)
            requestStackPush(States::Test);
    }
    return false;
}
