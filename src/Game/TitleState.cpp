#include "TitleState.hpp"

#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"
#include "../Utils/Log.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

TitleState::TitleState(StateStack& stack, Context context)
    : State(stack, context)
{
    world = context.window->getDefaultView();

    try
    {
        context.fonts->load(Res::Fonts::normal,    "data/fonts/DroidSansFallback.ttf");
        context.textures->load(Res::Textures::bg1, "data/bg/Frac2.png");
        context.textures->load(Res::Textures::bg2, "data/bg/Frac3.png");
    }
    catch (std::runtime_error& e)
    {
        Console::logf("Resource loading block failed: %s", e.what());
    }

    bg.setTexture(context.textures->get(Res::Textures::bg1));

    const sf::Font& font = context.fonts->get(Res::Fonts::normal);
    text.setFont(font);
    text.setPosition(5.0f, 100.0f);
    text.setCharacterSize(32);
    text.setString(L"你好世界");

    menu.setPosition(128.0f, 300.0f);
    menu.addItem(L"Test", font, 16);
    menu.addItem(L"Pattern", font, 16);
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
    window.draw(text);

    window.draw(menu);
}

bool TitleState::update(sf::Time dt)
{
    menu.update(dt);

    if (menu.isSelected())
    {
        const sf::String selection = menu.getSelection();

        if (selection == "Test")
        {
            this->requestStackPush(States::Test);
        }
        else if (selection == "Pattern")
        {
            this->requestStackPush(States::Pattern);
        }
    }

    return false;
}

bool TitleState::handleEvent(const sf::Event& event)
{
    menu.handleEvent(event);

    return false;
}

