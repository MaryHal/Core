#ifndef _PatternState_hpp_
#define _PatternState_hpp_

#include "../System/State.hpp"
#include <SFML/Graphics.hpp>

#include "Bullet/BulletManager.hpp"
#include <bulletmlparser.h>
#include <bulletmlparser-tinyxml.h>
#include <bulletmlparser-tinyxml2.h>

#include "../Utils/MakeUnique.hpp"

class PatternState : public State
{
    public:
        PatternState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);

    private:
        BulletManager manager;
        std::unique_ptr<Mover> ship;
        std::unique_ptr<Mover> boss;
        std::unique_ptr<BulletMLParserTinyXML> parser;
        std::unique_ptr<BulletMLParserTinyXML2> parser2;
};

#endif // _PatternState_hpp_

