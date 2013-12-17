#include "QuadTree.hpp"

QuadTreeNode::QuadTreeNode(float x, float y, float w, float h)
{
    children = nullptr;
}

QuadTreeNode::QuadTreeNode(const sf::FloatRect& area)
{
    children = nullptr;
}

QuadTreeNode::~QuadTreeNode()
{
}

bool QuadTreeNode::insert(sf::Vector2f* point)
{
    if (children == nullptr)
    {
        items.push_back(point);

        if (items.size() > QuadTreeNode::MAX_ITEMS)
            splitNode();

        return true;
    }
    else
    {
        QuadTreeNode* node = getChild(point->x, point->y);
        if (node != nullptr)
        {
            return node->insert(point);
        }
    }
    return false;
}

std::vector<sf::Vector2f*> QuadTreeNode::get(const sf::FloatRect& area, 
                                             std::vector<sf::Vector2f*>& collection)
{
    if (children == nullptr)
    {
        for (sf::Vector2f* point : items)
        {
            if (area.contains(*point))
            {
                collection.push_back(point);
            }
        }
    }
    else
    {
        for (QuadTreeNode* child : *children)
        {
            if (area.intersects(child->getBounds()))
            {
                child->get(area, collection);
            }
        }

    }

    return collection;
}

const sf::FloatRect& QuadTreeNode::getBounds()
{
    return bounds;
}

void QuadTreeNode::splitNode()
{
}

QuadTreeNode* QuadTreeNode::getChild(float x, float y)
{
    return nullptr;
}




QuadTree::QuadTree()
{
    root = nullptr;
}

bool QuadTree::insert(sf::Vector2f point)
{
    return false;
}

std::vector<sf::Vector2f*> QuadTree::get(float x, float y, float w, float h)
{
    return std::vector<sf::Vector2f*>();
}

std::vector<sf::Vector2f*> QuadTree::get(const sf::FloatRect& area)
{
    return std::vector<sf::Vector2f*>();
}

