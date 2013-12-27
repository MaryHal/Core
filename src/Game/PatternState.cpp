#include "PatternState.hpp"
#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"
#include "../Utils/Log.hpp"

#include <queue>

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

    Bullet::StepFunc f1 = [this](Bullet* b) 
    {
        b->setWait(20);
        b->setSpeed(10);
        b->setCircle(0.2, 180);
    };

    std::queue<Bullet::StepFunc> a;
    a.push(f1);

    for (float x = 0.0f; x < 3.14 * 2; x += 3.14 / 2)
    {
        Bullet* b = BulletBuffer::fire();
        b->initialize(sf::Vector2f(320.0f, 320.0f), 5, x, a);
    }
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


