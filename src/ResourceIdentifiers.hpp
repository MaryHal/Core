#ifndef _ResourceIdentifiers_hpp_
#define _ResourceIdentifiers_hpp_

namespace sf
{
    class Texture;
    class Font;
    class Shader;
    class SoundBuffer;
};

enum class Textures { bg1 };
enum class Fonts { normal, jp };
enum class Shaders {};
enum class Sounds {};
enum class Music { main, other };

template <typename Resource, typename Identifier> class ResourceHolder;
typedef ResourceHolder <sf::Texture,     Textures> TextureHolder;
typedef ResourceHolder <sf::Font,        Fonts>    FontHolder;
typedef ResourceHolder <sf::Shader,      Shaders>  ShaderHolder;
typedef ResourceHolder <sf::SoundBuffer, Sounds>   SoundHolder;

#endif // _ResourceIdentifiers_hpp_
