#include "BulletManager.hpp"

#include "Bullet.hpp"
#include "BulletCommand.hpp"
// #include "BulletLua.hpp"

#include "../../Utils/Log.hpp"

BulletManager::BulletManager()
{
    // mLuaCommands.reserve(1024);
    mCommands.reserve(1024);
    mShots.reserve(1024);
    mPool.reserve(1024);
}

// BulletLua* BulletManager::createBullet(BulletLua* bullet, const std::string& func,
//                                        double x, double y, double d, double s,
//                                        Mover* target)
// {
//     Mover* shot_ = createProjectile(x, y, d, s);
//     BulletLua* ret;
//     ret = new BulletLua(bullet->getLuaState(), func, shot_, target, this);
//     mLuaCommands.push_back(ret);
//     return ret;
// }

// BulletLua* BulletManager::createBullet(const std::string& luaFile,
//                                        Mover* origin,
//                                        Mover* target)
// {
//     BulletLua* ret;
//     ret = new BulletLua(luaFile, origin, target, this);
//     mLuaCommands.push_back(ret);
//     return ret;
// }

BulletCommand* BulletManager::createBullet(BulletMLState* state,
                                           double x, double y, double d, double s,
                                           Mover* target)
{
    Mover* shot_ = createProjectile(x, y, d, s);
    BulletCommand* ret;
    ret = new BulletCommand(state, shot_, target, this);
    mCommands.push_back(ret);
    return ret;
}

BulletCommand* BulletManager::createBullet(BulletMLParser* parser,
                                           Mover* origin,
                                           Mover* target)
{
    BulletCommand* ret;
    ret = new BulletCommand(parser, origin, target, this);
    mCommands.push_back(ret);
    return ret;
}

void BulletManager::tick()
{
    unsigned int size = mShots.size();
    for (unsigned int i = 0; i < size; ++i)
    {
        if (mShots[i]->dead)
        {
            mPool.push_back(mShots[i]);
            mShots[i] = mShots.back();
            mShots.pop_back();
            --size;
        }
        if (i < size)
            mShots[i]->tick();
    }

    size = mCommands.size();
    for (unsigned int i = 0; i < size; ++i)
    {
        if (mCommands[i]->isDead())
        {
            delete mCommands[i];
            mCommands[i] = mCommands.back();
            mCommands.pop_back();
            --size;
        }
        if (i < size)
            mCommands[i]->run();
    }

    // size = mLuaCommands.size();
    // for (unsigned int i = 0; i < size; ++i)
    // {
    //     if (mLuaCommands[i]->isDead())
    //     {
    //         delete mLuaCommands[i];
    //         mLuaCommands[i] = mLuaCommands.back();
    //         mLuaCommands.pop_back();
    //         --size;
    //     }
    //     if (i < size)
    //         mLuaCommands[i]->run();
    // }

    Bullet::turn++;
}

void BulletManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for (Shot* shot : mShots)
    {
        /* if (!shot->dead) */
        target.draw(*shot);
    }
}

Shot* BulletManager::createProjectile(double x, double y, double d, double s)
{
    Shot* ret;
    if (mPool.empty())
    {
        ret = new Shot(x, y, d, s);
    }
    else
    {
        ret = mPool.back();
        ret->x = x;
        ret->y = y;
        ret->d = d;
        ret->s = s;
        mPool.pop_back();
    }
    ret->dead = false;
    mShots.push_back(ret);
    return ret;
}

void BulletManager::destroyProjectile(Shot* projectile)
{
    projectile->dead = true;
}

void BulletManager::clearAll()
{
    for (BulletCommand* command : mCommands)
    {
        delete command;
    }
    mCommands.clear();

    // for (BulletLua* command : mLuaCommands)
    // {
    //     delete command;
    // }
    // mLuaCommands.clear();

    for (Shot* shot : mShots)
    {
        delete shot;
    }
    mShots.clear();
}
