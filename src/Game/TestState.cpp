#include "TestState.hpp"

#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include "../Utils/Log.hpp"

TestState::TestState(StateStack& stack, Context context)
    : State(stack, context)
{
    bg.setTexture(context.textures->get(Res::Textures::bg2));

    ship = make_unique<Mover>(320, 370, 0, 0);
    boss = make_unique<Mover>(320, 120, 0, 0);
    ship->dead = false;
    boss->dead = false;

    bossBullet = make_unique<BulletLua>(boss.get(), ship.get());
    shipBullet = make_unique<BulletLua>(ship.get(), boss.get());

    bossBullet->__debugRun("dir = 0");
}

void TestState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    // window.draw(bg);

    window.draw(*ship);
    window.draw(*boss);
}

bool TestState::update(sf::Time dt)
{
    bossBullet->__debugRun("setPos(100*math.sin(dir)+320, 100*math.cos(dir) + 120) dir = dir + math.pi / 90");
    shipBullet->tick();
    bossBullet->tick();
    return false;
}

bool TestState::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
    }
    return false;
}
