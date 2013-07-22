#ifndef _ResourceIdentifiers_hpp_
#define _ResourceIdentifiers_hpp_

namespace sf
{
    class Texture;
    class Font;
    class Shader;
    class SoundBuffer;
};

namespace Res
{
    enum class Textures { bg1 };
    enum class Fonts { normal, jp };
    enum class Shaders {};
    enum class Sounds {};
    enum class Music { main, other };
};

template <typename Resource, typename Identifier> class ResourceHolder;
typedef ResourceHolder <sf::Texture,     Res::Textures> TextureHolder;
typedef ResourceHolder <sf::Font,        Res::Fonts>    FontHolder;
typedef ResourceHolder <sf::Shader,      Res::Shaders>  ShaderHolder;
typedef ResourceHolder <sf::SoundBuffer, Res::Sounds>   SoundHolder;

#endif // _ResourceIdentifiers_hpp_
