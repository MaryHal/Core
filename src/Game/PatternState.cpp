#include "PatternState.hpp"
#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"
#include "../Utils/Log.hpp"
#include "../Utils/StringUtils.hpp"

#include "Bullet/BulletCommand.hpp"
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
        "5x5wide.xml",
        "10flower.xml",
        "circle_fireworks.xml",
        "dis_bee_hakkyou.xml",
        "homing_circle.xml",
        "las1.xml",
        "otk2-hanabi.xml",
        "self-mis02.xml",
        "sample.xml",
        "tsx_evac02.xml",
        "tsx_sanada.xml",
        "progear.xml",
    };

    // Load patterns from list of files
    for (const std::string& name : xmlFiles)
    {
        std::string filename = "data/pattern/" + name;
        parsers.push_back(make_unique<BulletMLParserTinyXML2>(filename.c_str()));
        parsers.back()->parse();
    }

    const sf::Font& font = context.fonts->get(Res::Fonts::normal);
    barrageInfo.setFont(font);
    barrageInfo.setPosition(8.0f, 8.0f);
    barrageInfo.setCharacterSize(11);

    bulletInfo.setFont(font);
    bulletInfo.setPosition(8.0f, 370.0f);
    bulletInfo.setCharacterSize(11);

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

    // Console::logf("%f %d", ship->x, ship->dead);
}

void PatternState::draw()
{
    sf::RenderWindow& window = *(getContext().window);
    window.draw(manager);
    window.draw(*ship);
    window.draw(*boss);

    if (menuVisible)
        window.draw(menu);

    window.draw(barrageInfo);
    window.draw(bulletInfo);
    window.draw(help);
}

bool PatternState::update(sf::Time dt)
{
    barrageInfo.setString(formatString("File: %s\nRank: %.2f", currentFile.toAnsiString().c_str(), Bullet::rank));
    // bulletInfo.setString(formatString("CommandCount: %d/%d\nBulletCount %d/%d\nPoolSize: %d/%d",
    //                                   manager.mCommands.size(), manager.mCommands.capacity(),
    //                                   manager.mShots.size(), manager.mShots.capacity(),
    //                                   manager.mPool.size(), manager.mPool.capacity()));

    /* Console::logf("%d %d %d", manager.mShots.size(), manager.mPool.size(), manager.mCommands.size()); */
    sf::Vector2i mousePos = sf::Mouse::getPosition(*getContext().window);
    ship->x = mousePos.x;
    ship->y = mousePos.y;
    ship->tick();

    menu.update(dt);

    manager.tick();

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
            if (Bullet::rank - dr >= 0.0)
                Bullet::rank -= dr;
        }
        if (event.key.code == sf::Keyboard::Right)
        {
            if (Bullet::rank + dr <= 1.0)
                Bullet::rank += dr;
        }
    }

    return false;
}
