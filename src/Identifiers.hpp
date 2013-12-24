#ifndef _Identifiers_hpp_
#define _Identifiers_hpp_

namespace States
{
    enum ID
    {
        None,
        Loading,
        Title,
        Test,
        Pattern,
        Music
    };
}

namespace Res
{
    enum class Textures { bg1, bg2, musicbg };
    enum class Fonts { normal };
    enum class Shaders {};
    enum class Sounds {};
    enum class Music { main, main2 };
};


#endif // _Identifiers_hpp_

