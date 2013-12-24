#include "Menu.hpp"
#include <algorithm>

Menu::Menu()
    : index(0), selected(false)
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
    float longest = 0;
    float y = 0;
    for (sf::Text& text : items)
    {
        longest = std::max(longest, text.getLocalBounds().width);

        text.setPosition(margin, y + margin);
        y += text.getCharacterSize() + margin;
    }

    style.setSize(sf::Vector2f(longest + 2 * margin, y + 2 * margin));
    style.setFillColor(sf::Color(0, 0, 0, 200));
    style.setOutlineThickness(2.0f);
    style.setOutlineColor(sf::Color(255, 255, 255, 128));

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
        if (event.key.code == sf::Keyboard::Return)
        {
            selected = true;
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

    target.draw(style, states);
    for (const sf::Text& text : items)
    {
        target.draw(text, states);
    }
}

const bool Menu::isSelected() const
{
    return selected;
}

const sf::String Menu::getSelection()
{
    if (selected)
    {
        selected = false;
        return items[index].getString();
    }
    return "";
}

