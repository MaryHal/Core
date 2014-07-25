#include "PatternState.hpp"
#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"
#include "../Utils/Log.hpp"

PatternState::PatternState(StateStack& stack, Context context)
    : State(stack, context)
{
    try
    {
        // context.fonts->load(Res::Fonts::normal,    "data/fonts/DroidSansFallback.ttf");
        // context.textures->load(Res::Textures::bg1, "data/bg/Frac2.png");
        // context.textures->load(Res::Textures::bg2, "data/bg/Frac3.png");
        // context.music->addSong(Res::Music::main,   "data/music/ReflectionEternal.ogg");
    }
    catch (std::runtime_error& e)
    {
        Console::logf("Resource loading block failed: %s", e.what());
    }

    parser = make_unique<BulletMLParserTinyXML>("data/pattern/10flower.xml");
    parser2 = make_unique<BulletMLParserTinyXML2>("data/pattern/10flower.xml");
    parser->parse();
    parser2->parse();

    ship = make_unique<Mover>(320, 120, 0, 0);
    boss = make_unique<Mover>(320, 370, 0, 0);
    manager.createBullet(parser.get(), ship.get(), boss.get());
}

void PatternState::draw()
{
    sf::RenderWindow& window = *(getContext().window);
    window.draw(manager);
    window.draw(*ship);
    window.draw(*boss);
}

bool PatternState::update(sf::Time dt)
{
    manager.tick();
    return false;
}

bool PatternState::handleEvent(const sf::Event& event)
{
    return false;
}

