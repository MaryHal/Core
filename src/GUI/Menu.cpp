#include "Menu.hpp"

Menu::Menu()
    : index(0)
{
}

void Menu::addItem(sf::String string, const sf::Font& font, unsigned int size)
{
    sf::Text text(string, font, size);
    items.push_back(text);
}

void Menu::build()
{
    // Build Text Drawables
    float y = 0;
    for (sf::Text& text : items)
    {
        text.setPosition(0.0f, y);
        y += text.getCharacterSize();
    }
    items[index].setColor(sf::Color::Magenta);
}

bool Menu::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Up)
        {
            index--;
            if (index > items.size())
                index = items.size() - 1;
        }
        if (event.key.code == sf::Keyboard::Down)
        {
            index++;
            if (index > items.size() - 1)
                index = 0;
        }
    }
    return true;
}

bool Menu::update(sf::Time dt)
{
    for (sf::Text& text : items)
    {
        text.setColor(sf::Color::White);
    }
    items[index].setColor(sf::Color::Magenta);

    return true;
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for (const sf::Text& text : items)
    {
        target.draw(text, states);
    }
}

