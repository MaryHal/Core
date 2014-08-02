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

    controller1 = make_unique<BulletLua>(boss.get(), ship.get());
    controller2 = make_unique<BulletLua>(controller1->luaState, "", ship.get(), boss.get());

    controller1->__debugRun("dir = 0");
    controller1->__debugRun("setPos(100.0, 100.0)");
    controller2->__debugRun("setPos(400.0, 400.0)");
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
    controller1->__debugRun("setVel(2 * math.cos(dir), 2 * math.sin(dir))");
    controller2->__debugRun("setVel(2 * math.cos(dir), 2 * math.sin(dir))");
    controller2->__debugRun("dir = dir + math.pi / 180");

    controller1->tick();
    controller2->tick();
    return false;
}

bool TestState::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
    }
    return false;
}
