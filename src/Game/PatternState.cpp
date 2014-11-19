#include "PatternState.hpp"
#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"
#include "../Utils/Log.hpp"
#include "../Utils/StringUtils.hpp"

#include <SFML/System/Vector2.hpp>

#include "Bullet.hpp"
#include "Bullet/BulletManager.hpp"

PatternState::PatternState(StateStack& stack, Context context)
    : State(stack, context)
{
    try
    {
        /* context.fonts->load(Res::Fonts::normal,    "data/fonts/DroidSansFallback.ttf"); */
        /* context.textures->load(Res::Textures::bg1, "data/bg/Frac2.png"); */
        /* context.textures->load(Res::Textures::bg2, "data/bg/Frac3.png"); */
        /* context.music->addSong(Res::Music::main,   "data/music/ReflectionEternal.ogg"); */
    }
    catch (std::runtime_error& e)
    {
        Console::logf("Resource loading block failed: %s", e.what());
    }

    manager = make_unique<BulletManager>(-100, -100, 840, 680);

    origin = make_unique<Bullet>(320.0f, 120.0f, 0.0f, 0.0f);
    destination = make_unique<Bullet>(320.0f, 240.0f, 0.0f, 0.0f);

    bulletTexture.loadFromFile("data/texture/bullet.png");
    manager->setTexture(bulletTexture);

    const sf::Font& font = context.fonts->get(Res::Fonts::normal);
    debugText.setFont(font);
    debugText.setPosition(4.0f, 4.0f);
    debugText.setCharacterSize(12);

    menu.setPosition(16.0f, 120.0f);
    menu.addList({"test.lua"
                , "test2.lua"
                , "test3.lua"
                , "test4.lua"
                , "test5.lua"
                , "test6.lua"
                , "test7.lua"
                , "test8.lua"
                },
        font, 12);
    menu.build();
}

void PatternState::draw()
{
    sf::RenderWindow& window = *(getContext().window);

    window.draw(debugText);
    window.draw(*manager);

    window.draw(menu);
}

bool PatternState::update(sf::Time dt)
{
    debugText.setString(formatString("Fps: %d\nBullets: %d\nFree: %d\nBlocks: %d",
                                     getContext().fps->getFps(),
                                     manager->bulletCount(),
                                     manager->freeCount(),
                                     manager->blockCount()));

    menu.update(dt);

    if (menu.isSelected())
    {
        const sf::String selection = menu.getSelection();

        manager->clear();
        manager->createBullet("data/lua/" + selection, origin.get(), destination.get());
    }

    manager->tick();

    sf::Vector2i mousePos = sf::Mouse::getPosition(*(getContext().window));
    destination->x = mousePos.x;
    destination->y = mousePos.y;

    if (manager->checkCollision(*destination.get()))
    {
        manager->vanishAll();
    }

    return false;
}

bool PatternState::handleEvent(const sf::Event& event)
{
    menu.handleEvent(event);

    return false;
}
