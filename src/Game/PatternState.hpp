#ifndef _PatternState_hpp_
#define _PatternState_hpp_

#include "../System/State.hpp"
#include <SFML/Graphics.hpp>

#include "../GUI/Menu.hpp"
#include "Bullet/BulletML/BulletMLManager.hpp"
#include <bulletmlparser.h>

#include <vector>
#include "../Utils/MakeUnique.hpp"

class PatternState : public State
{
    public:
        PatternState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);

    private:
        BulletMLManager manager;
        std::unique_ptr<Mover> ship;
        std::unique_ptr<Mover> boss;

        std::vector<std::string> xmlFiles;
        std::vector<std::unique_ptr<BulletMLParser>> parsers;

        bool menuVisible;
        Menu menu;

        sf::Text help;
        sf::Text barrageInfo;
        sf::Text bulletInfo;
        sf::String currentFile;
};

#endif // _PatternState_hpp_

