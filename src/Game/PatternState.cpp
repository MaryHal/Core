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

    bulletTexture.loadFromFile("data/texture/bullet2.png");
    manager->setTexture(bulletTexture);

    manager->createBullet("data/lua/test2.lua", origin.get(), destination.get());
}

void PatternState::draw()
{
    sf::RenderWindow& window = *(getContext().window);

    window.draw(debugText);
    window.draw(*manager);
}

bool PatternState::update(sf::Time dt)
{
    // debugText.setString(formatString("Fps: %d\nBullets: %d\nFree: %d\nBlocks: %d\nHits: %d",
    //                                  getContext().fps->getFps(),
    //                                  manager.bulletCount(),
    //                                  manager.freeCount(),
    //                                  manager.blockCount(),
    //                                  hitCount));

    manager->tick();

    return false;
}

bool PatternState::handleEvent(const sf::Event& event)
{
    return false;
}
