#include "BulletLuaManager.hpp"

#include "../../Utils/Log.hpp"

float BulletLuaManager::rank = 0.8;

BulletLuaManager::BulletLuaManager(unsigned int initialCapacity)
    : bullets(initialCapacity)
{
    // Throw all bullets into free stack
    for (auto iter = bullets.rend(); iter != bullets.rbegin(); --iter)
    {
        freeBullets.push(&*iter);
    }
}

void BulletLuaManager::createBullet(const std::string& filename, Mover* origin, Mover* target)
{
    BulletLua* b = getFreeBullet();
    b->set(filename, origin, target, this);
}

void BulletLuaManager::createBullet(std::shared_ptr<sol::state> lua, const std::string& func, Mover* origin, Mover* target)
{
    BulletLua* b = getFreeBullet();
    b->set(lua, func, origin, target, this);
}

void BulletLuaManager::createBullet(std::shared_ptr<sol::state> lua, const std::string& func,
                  double x, double y, double d, double s, Mover* target)
{
    BulletLua* b = getFreeBullet();
    Mover m(x, y, d, s);
    b->set(lua, func, &m, target, this);
}

void BulletLuaManager::tick()
{
    for (auto& bullet : bullets)
    {
        if (!bullet.isDead())
        {
            bullet.run();
        }
    }
}

void BulletLuaManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& bullet : bullets)
    {
        if (!bullet.isDead())
        {
            target.draw(bullet.getMover());
        }
    }
}

BulletLua* BulletLuaManager::getFreeBullet()
{
    BulletLua* bullet;

    if (freeBullets.empty())
    {
        bullets.emplace_back();
        bullet = &bullets.back();
    }
    else
    {
        bullet = freeBullets.top();
        freeBullets.pop();
    }

    return bullet;
}

void BulletLuaManager::printSizes()
{
    Console::log("------------------");
    Console::logf("Vector Size: %d", bullets.size());
    Console::logf("Free Size:   %d", freeBullets.size());
}

void BulletLuaManager::pushToStack(BulletLua* b)
{
    freeBullets.push(b);
}

