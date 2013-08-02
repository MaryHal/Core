#ifndef _Menu_hpp_
#define _Menu_hpp_

#include <SFML/System/String.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

class Menu : public sf::Drawable, public sf::Transformable
{
    public:
    Menu();
    void addItem(sf::String string, const sf::Font& font, unsigned int size=20);
    void build();

    bool handleEvent(const sf::Event& event);
    bool update(sf::Time dt);

    private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
    std::vector<sf::Text> items;
    unsigned int index;
};

#endif // _Menu_hpp_
