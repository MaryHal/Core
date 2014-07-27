#ifndef _Menu_hpp_
#define _Menu_hpp_

#include <SFML/System/String.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

class Menu : public sf::Drawable, public sf::Transformable
{
    private:
        static const int margin = 6;

    public:
        Menu();
        void addItem(const sf::String& str, const sf::Font& font, unsigned int size=20);
        void addList(const std::vector<std::string>& list, const sf::Font& font, unsigned int size=20);
        void build();

        bool handleEvent(const sf::Event& event);
        bool update(sf::Time dt);

        bool isSelected();
        const sf::String getSelection();
        unsigned int getIndex();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::RectangleShape style;
        std::vector<sf::Text> items;
        unsigned int index;
        bool selected;
};

#endif // _Menu_hpp_

