#ifndef _ResourceHolder_hpp_
#define _ResourceHolder_hpp_

#include <map>
#include <string>
#include <memory>
#include <stdexcept>

template <typename Resource, typename Identifier>
class ResourceHolder
{
    public:
    void load(Identifier id, const std::string& filename);

    template <typename Parameter>
    void load(Identifier id, const std::string& filename, const Parameter& secondParam);

    Resource& get(Identifier id);
    const Resource& get(Identifier id) const;

    // Resource& operator[](Identifier id);
    // const Resource& operator[](Identifier id) const;

    protected:
    void insertResource(Identifier id, std::unique_ptr<Resource> resource);

    protected:
    std::map<Identifier, std::unique_ptr<Resource>> resourceMap;
};

// #include <SFML/Graphics.hpp>

// template <typename Identifier>
// class FontManager : public ResourceHolder<sf::Font, Identifier>
// {
//     public:
//     sf::Text makeText(Identifier id, sf::String string)
//     {
//         return sf::Text(string, this->get(id));
//     }
// };

#include "ResourceHolder.inl"

#endif // _ResourceHolder_hpp_

