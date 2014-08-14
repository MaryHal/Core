#include "BulletLuaManager.hpp"

float BulletLuaManager::rank = 0.8;

BulletLuaManager::BulletLuaManager(unsigned int initialCapacity)
    : vertices(sf::Quads),
    vertexCount(0)
{
    increaseCapacity(initialCapacity);
}

BulletLuaManager::~BulletLuaManager()
{
    for (auto iter = blocks.begin(); iter != blocks.end(); ++iter)
    {
        delete [] *iter;
    }
}

void BulletLuaManager::createBullet(const std::string& filename, Bullet* origin, Bullet* target)
{
    BulletLua* b = getFreeBullet();
    b->set(filename, origin, target, this);
    bullets.push_back(b);
}

void BulletLuaManager::createBullet(std::shared_ptr<sol::state> lua, const std::string& func, Bullet* origin, Bullet* target)
{
    BulletLua* b = getFreeBullet();
    b->set(lua, func, origin, target, this);
    bullets.push_back(b);
}

void BulletLuaManager::createBullet(std::shared_ptr<sol::state> lua, const std::string& func,
                  double x, double y, double d, double s, Bullet* target)
{
    BulletLua* b = getFreeBullet();
    b->set(lua, func, x, y, d, s, target, this);
    bullets.push_back(b);
}

void BulletLuaManager::tick()
{
    vertices.clear();
    /* collision.reset(); */

    for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
    {
        BulletLua* bullet = *iter;

        if (bullet->isDead())
        {
            freeBullets.push(bullet);
            iter = bullets.erase(iter);
        }
        else
        {
            bullet->run();
            const Bullet* b = &bullet->getMover();

            sf::Vertex v1(sf::Vector2f(b->x       , b->y),
                          sf::Color(200, 200, 200));
            sf::Vertex v2(sf::Vector2f(b->x + 4.0f, b->y),
                          sf::Color(200, 200, 200));
            sf::Vertex v3(sf::Vector2f(b->x + 4.0f, b->y + 4.0f),
                          sf::Color(200, 200, 200));
            sf::Vertex v4(sf::Vector2f(b->x       , b->y + 4.0f),
                          sf::Color(200, 200, 200));
            vertices.append(v1);
            vertices.append(v2);
            vertices.append(v3);
            vertices.append(v4);

            /* collision.addBullet(&bullet->getMover()); */
        }
    }
}

void BulletLuaManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    /* for (auto& bullet : bullets) */
    /* { */
    /*     target.draw(bullet->getMover().sprite); */
    /* } */
    target.draw(vertices);
}

bool BulletLuaManager::checkCollision(Bullet& b)
{
    return collision.checkCollision(b);
}

unsigned int BulletLuaManager::bulletCount() const
{
    return bullets.size();
}

unsigned int BulletLuaManager::freeCount() const
{
    return freeBullets.size();
}

unsigned int BulletLuaManager::blockCount() const
{
    return blocks.size();
}

BulletLua* BulletLuaManager::getFreeBullet()
{
    if (freeBullets.empty())
        increaseCapacity();

    BulletLua* bullet = freeBullets.top();
    freeBullets.pop();

    return bullet;
}

void BulletLuaManager::increaseCapacity(unsigned int blockSize)
{
    blocks.push_back(new BulletLua[blockSize]);

    // Throw all bullets into free stack
    for (unsigned int i = 0; i < blockSize; ++i)
    {
        freeBullets.push(&blocks.back()[i]);
    }

    vertexCount += blockSize * 4;
    vertices.resize(vertexCount);
}

