#include "MusicState.hpp"

#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"
#include "../Utils/Log.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

MusicState::MusicState(StateStack& stack, Context context)
    : State(stack, context)
{

    try
    {
        context.textures->load(Res::Textures::musicbg, "data/bg/Frac5.png");

        context.music->addSong(Res::Music::main,   "data/music/ReflectionEternal.ogg");
        context.music->addSong(Res::Music::main2,  "data/music/Melodica.ogg");
    }
    catch (std::runtime_error& e)
    {
        Console::logf("Resource loading block failed: %s", e.what());
    }

    bg.setTexture(context.textures->get(Res::Textures::musicbg));

    const sf::Font& font = context.fonts->get(Res::Fonts::normal);
    menu.setPosition(128.0f, 300.0f);
    menu.addItem(L"Melodica", font, 16);
    menu.addItem(L"ReflectionEternal", font, 16);
    menu.build();

    fullBar.setOutlineColor(sf::Color(255, 255, 255, 128));
    fullBar.setOutlineThickness(2);
    fullBar.setFillColor(sf::Color::Transparent);
    fullBar.setPosition(8.0f, 48.0f);
    fullBar.setSize(sf::Vector2f(320.0f, 8.0f));

    progressBar.setFillColor(sf::Color(128, 0, 128, 200));
    progressBar.setPosition(8.0f, 48.0f);
    progressBar.setSize(sf::Vector2f(0.0f, 8.0f));

    progressText.setFont(font);
    progressText.setString("");
    progressText.setPosition(8.0f, 8.0f);
}

void MusicState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    window.draw(bg);
    window.draw(progressText);
    window.draw(progressBar);
    window.draw(fullBar);
    window.draw(menu);
}

bool MusicState::update(sf::Time dt)
{
    menu.update(dt);

    if (menu.isSelected())
    {
        const sf::String selection = menu.getSelection();

        if (selection == "Melodica")
        {
            getContext().music->play(Res::Music::main2);
        }
        else if (selection == "ReflectionEternal")
        {
            getContext().music->play(Res::Music::main);
        }
    }

    float currentTime = getContext().music->getTime().asSeconds();
    float duration    = getContext().music->getDuration().asSeconds();
    float ratio       = currentTime / duration;
    progressText.setString(std::to_string(currentTime) + 
                           " / " +
                           std::to_string(duration));

    progressBar.setSize(sf::Vector2f(ratio * 320.0f, 8.0f));

    return false;
}

bool MusicState::handleEvent(const sf::Event& event)
{
    menu.handleEvent(event);

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::A)
            getContext().music->relSeek(sf::seconds(-2.0f));
        else if (event.key.code == sf::Keyboard::D)
            getContext().music->relSeek(sf::seconds(2.0f));
        else if (event.key.code == sf::Keyboard::Space)
            getContext().music->pause();
    }
    return false;
}

