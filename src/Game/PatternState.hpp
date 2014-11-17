#ifndef _PatternState_hpp_
#define _PatternState_hpp_

#include "../System/State.hpp"
#include "../Utils/MakeUnique.hpp"

#include <SFML/Graphics.hpp>

// From BulletLua
class Bullet;
class BulletManager;

class PatternState : public State
{
    public:
        PatternState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);

    private:
        std::unique_ptr<BulletManager> manager;

        std::unique_ptr<Bullet> origin;
        std::unique_ptr<Bullet> destination;

        sf::Texture bulletTexture;
        sf::Text debugText;
};

#endif // _PatternState_hpp_
