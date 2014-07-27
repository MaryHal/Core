#include "PatternState.hpp"
#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"
#include "../Utils/Log.hpp"
#include "../Utils/StringUtils.hpp"

#include "Bullet/Bullet.hpp"
#include <bulletmlparser-tinyxml2.h>

#include <SFML/System/Vector2.hpp>

PatternState::PatternState(StateStack& stack, Context context)
    : State(stack, context)
{
    try
    {
        /* context.fonts->load(Res::Fonts::normal,    "data/fonts/DroidSansFallback.ttf"); */
        /* context.textures->load(Res::Textures::bg1, "data/bg/Frac2.png"); */
        /* context.textures->load(Res::Textures::bg2, "data/bg/Frac3.png"); */
        /* context.music->addSong(Res::Music::main,   "data/music/ReflectionEternal.ogg"); */
    }
    catch (std::runtime_error& e)
    {
        Console::logf("Resource loading block failed: %s", e.what());
    }

    xmlFiles = 
    {
        "10flower.xml",
        "circle_fireworks.xml",
        "dis_bee_hakkyou.xml",
        "homing_circle.xml",
        "las1.xml",
        "otk2-hanabi.xml",
        "self-mis02.xml",
        "tsx_evac02.xml",
        "tsx_sanada.xml",
    };

    // Load patterns from list of files
    for (const std::string& name : xmlFiles)
    {
        std::string filename = "data/pattern/" + name;
        parsers.push_back(make_unique<BulletMLParserTinyXML2>(filename.c_str()));
        parsers.back()->parse();
    }

    const sf::Font& font = context.fonts->get(Res::Fonts::normal);
    info.setFont(font);
    info.setPosition(8.0f, 8.0f);
    info.setCharacterSize(11);
    info.setString(formatString("File: %s\nRank: %.2f", currentFile.toAnsiString().c_str(), BulletCommand::rank));

    help.setFont(font);
    help.setPosition(8.0f, 432.0f);
    help.setCharacterSize(11);
    help.setString("Enter - run bullet file\nc - clear bullets\nh - toggle menu");

    menu.setPosition(8.0f, 42.0f);
    menu.addList(xmlFiles, font, 10);
    menu.build();

    menuVisible = true;

    ship = make_unique<Mover>(320, 370, 0, 0);
    boss = make_unique<Mover>(320, 120, 0, 0);
    ship->dead = false;
    boss->dead = false;
}

void PatternState::draw()
{
    sf::RenderWindow& window = *(getContext().window);
    window.draw(manager);
    window.draw(*ship);
    window.draw(*boss);

    if (menuVisible)
        window.draw(menu);

    window.draw(info);
    window.draw(help);
}

bool PatternState::update(sf::Time dt)
{
    /* Console::logf("%d %d %d", manager.mShots.size(), manager.mPool.size(), manager.mCommands.size()); */
    sf::Vector2i mousePos = sf::Mouse::getPosition(*getContext().window);
    ship->x = mousePos.x;
    ship->y = mousePos.y;
    ship->tick();

    manager.tick();

    menu.update(dt);

    return false;
}

bool PatternState::handleEvent(const sf::Event& event)
{
    menu.handleEvent(event);

    if (menu.isSelected())
    {
        currentFile = menu.getSelection();
        int index = menu.getIndex();

        manager.createBullet(parsers[index].get(), boss.get(), ship.get());

        info.setString(formatString("File: %s\nRank: %.2f", currentFile.toAnsiString().c_str(), BulletCommand::rank));
    }

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::C)
        {
            manager.clearAll();
        }

        if (event.key.code == sf::Keyboard::H)
        {
            menuVisible = !menuVisible;
        }

        double dr = 0.1;
        if (event.key.code == sf::Keyboard::Left)
        {
            if (BulletCommand::rank - dr >= 0.0)
                BulletCommand::rank -= dr;
        }
        if (event.key.code == sf::Keyboard::Right)
        {
            if (BulletCommand::rank + dr <= 1.0)
                BulletCommand::rank += dr;
        }

        info.setString(formatString("File: %s\nRank: %.2f", currentFile.toAnsiString().c_str(), BulletCommand::rank));
    }

    return false;
}

