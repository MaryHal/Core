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
        b->setSpeed(30);
        b->setWait(2);
        b->setCircle(10, 60);
    };

    std::queue<Bullet::StepFunc> a;
    a.push(f1);

    Bullet* b = BulletBuffer::fire();
    b->initialize(sf::Vector2f(320.0f, 320.0f), 20, 3 * 3.14/4, a);
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


