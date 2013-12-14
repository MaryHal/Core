#ifndef _Identifiers_hpp_
#define _Identifiers_hpp_

namespace States
{
    enum ID
    {
        None,
        Loading,
        Title,
        Test
    };
}

namespace Res
{
    enum class Textures { bg1, bg2 };
    enum class Fonts { normal };
    enum class Shaders {};
    enum class Sounds {};
    enum class Music { main, other };
};


#endif // _Identifiers_hpp_

