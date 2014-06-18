#ifndef _QuadTree_hpp_
#define _QuadTree_hpp_

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <vector>
#include <array>

class QuadTreeNode
{
    public:
        QuadTreeNode();
        ~QuadTreeNode();

        bool insert(sf::Vector2f* point);
        std::vector<sf::Vector2f*> get(const sf::FloatRect& area, 
                                       std::vector<sf::Vector2f*>& collection);
        const sf::FloatRect& getBounds();

    protected:
        void splitNode();
        QuadTreeNode* getChild();

    private:
        std::vector<sf::Vector2f*> items;
        std::array<QuadTreeNode*, 4>* children;
        sf::FloatRect bounds;

        static const unsigned int MAX_ITEMS = 128;
};

class QuadTree
{
    public:
        QuadTree();
        bool insert(sf::Vector2f point);
        std::vector<sf::Vector2f*> get();

    private:
        QuadTreeNode* root;
};

#endif // _QuadTree_hpp_

