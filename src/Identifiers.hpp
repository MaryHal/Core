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
        Pattern
    };
}

namespace Res
{
    enum class Textures { bg1, bg2, musicbg, bullet };
    enum class Fonts { normal };
    enum class Shaders {};
    enum class Sounds {};
    enum class Music {};
};


#endif // _Identifiers_hpp_

