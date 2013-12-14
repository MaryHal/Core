#ifndef _ResourceIdentifiers_hpp_
#define _ResourceIdentifiers_hpp_

#include "ResourceHolder.hpp"
#include "../Identifiers.hpp"

namespace sf
{
    class Texture;
    class Font;
    class Shader;
    class SoundBuffer;
};

template <typename Resource, typename Identifier> class ResourceHolder;
typedef ResourceHolder <sf::Texture,     Res::Textures> TextureHolder;
typedef ResourceHolder <sf::Font,        Res::Fonts>    FontHolder;
typedef ResourceHolder <sf::Shader,      Res::Shaders>  ShaderHolder;
typedef ResourceHolder <sf::SoundBuffer, Res::Sounds>   SoundHolder;

#endif // _ResourceIdentifiers_hpp_

