#ifndef _TestState_hpp_
#define _TestState_hpp_

#include "../Utils/MakeUnique.hpp"

#include "../System/State.hpp"
#include <SFML/Graphics.hpp>

#include "Bullet/BulletManager.hpp"

class TestState : public State
{
    public:
        TestState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);

    private:
        sf::Sprite bg;

        sf::Text debugText;
        int hitCount;

        std::unique_ptr<Bullet> boss;
        std::unique_ptr<Bullet> ship;
        BulletManager manager;
};

#endif // _TestState_hpp_
