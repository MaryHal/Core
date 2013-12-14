#include "TitleState.hpp"
#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

TitleState::TitleState(StateStack& stack, Context context)
    : State(stack, context)
{
    world = context.window->getDefaultView();

    try
    {
        context.fonts->load(Res::Fonts::normal, "data/fonts/DroidSansFallback.ttf");
        context.textures->load(Res::Textures::bg1, "data/bg/Frac2.png");
        context.textures->load(Res::Textures::bg2, "data/bg/Frac3.png");
    }
    catch (std::runtime_error& e)
    {
    }

    bg.setTexture(context.textures->get(Res::Textures::bg1));

    text.setFont(context.fonts->get(Res::Fonts::normal));
    text.setPosition(5.0f, 100.0f);
    text.setCharacterSize(32);
    text.setString(L"我是美国人.\n私はアメリカ人です.\n나는 미국 해요");

    const sf::Font& font = context.fonts->get(Res::Fonts::normal);
    menu.setPosition(64.0f, 300.0f);
    menu.addItem(L"Hello", font, 16);
    menu.addItem(L"Bonjour", font, 16);
    menu.addItem(L"Hola", font, 16);
    menu.build();
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

