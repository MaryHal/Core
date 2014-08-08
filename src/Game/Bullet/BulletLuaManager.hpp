#ifndef _BulletLuaManager_hpp_
#define _BulletLuaManager_hpp_

#include "BulletManager.hpp"

class BulletLuaManager : public BulletManager
{
    public:
        BulletLuaManager();

        virtual void tick();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
};

#endif /* _BulletLuaManager_hpp_ */
