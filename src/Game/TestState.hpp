#ifndef _TestState_hpp_
#define _TestState_hpp_

#include "../System/State.hpp"
#include <SFML/Graphics.hpp>

#include "Bullet/Mover.hpp"
#include "Bullet/BulletLua.hpp"

#include "../Utils/MakeUnique.hpp"

class TestState : public State
{
    public:
        TestState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);

    private:
        sf::Sprite bg;

        std::unique_ptr<Mover> ship;
        std::unique_ptr<Mover> boss;
        std::unique_ptr<BulletLua> shipBullet;
        std::unique_ptr<BulletLua> bossBullet;
};

#endif // _TestState_hpp_
