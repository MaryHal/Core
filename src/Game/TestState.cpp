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
        context.textures->load(Res::Textures::bullet, "data/texture/bullet2.png");
    }
    catch (std::runtime_error& e)
    {
        Console::logf("Resource loading block failed: %s", e.what());
    }

    bg.setTexture(context.textures->get(Res::Textures::bg2));
    manager.setTexture(context.textures->get(Res::Textures::bullet));

    const sf::Font& font = context.fonts->get(Res::Fonts::normal);
    debugText.setFont(font);
    debugText.setPosition(8.0f, 8.0f);
    debugText.setCharacterSize(11);

    hitCount = 0;

    boss = make_unique<Bullet>(320.0f, 120.0f, 0.0f, 0.0f);
    ship = make_unique<Bullet>(320.0f, 370.0f, 0.0f, 0.0f);

    manager.createBullet("data/lua/test.lua", boss.get(), ship.get());
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
    sf::Vector2i mousePos = sf::Mouse::getPosition(*getContext().window);
    if (mousePos.x > 0 && mousePos.x < 640 && mousePos.y > 0 && mousePos.y < 480)
    {
        ship->x = mousePos.x;
        ship->y = mousePos.y;
    }

    manager.tick();
    if (manager.checkCollision(*ship.get()))
        hitCount++;

    debugText.setString(formatString("Fps: %d\nBullets: %d\nFree: %d\nBlocks: %d\nHits: %d",
                                     getContext().fps->getFps(),
                                     manager.bulletCount(),
                                     manager.freeCount(),
                                     manager.blockCount(),
                                     hitCount));

    return false;
}

bool TestState::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
    }
    return false;
}

