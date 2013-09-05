#ifndef _Category_hpp_
#define _Category_hpp_

enum class Category
{
    None   = 0,
    Player = 1 << 0,
    Enemy  = 1 << 1,

    Thing  = Player | Enemy,
};

#endif // _Category_hpp_

