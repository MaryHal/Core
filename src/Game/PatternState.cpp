#include "PatternState.hpp"
#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"
#include "../Utils/Log.hpp"

#include "Bullet/Patterns/easy.hpp"

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

    // for (float x = 0.0f; x < 3.14 * 2; x += 3.14 / 2)
    // {
    //     Bullet* b = BulletBuffer::fire();
    //     b->initialize(sf::Vector2f(320.0f, 320.0f), 4, x, a);
    // }
    BulletBuffer::initialize();
    Bullet* b =  genBulletFunc_2f8ce762a4f0544ddd5536127bb805a1(320.0f, 160.0f);
}

void PatternState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    BulletBuffer::draw(window);
}

bool PatternState::update(sf::Time dt)
{
    BulletBuffer::update();
    return false;
}

bool PatternState::handleEvent(const sf::Event& event)
{
    return false;
}


