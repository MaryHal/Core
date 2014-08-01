#include "PrefManager.hpp"

// #include <sol.hpp>

PrefManager::PrefManager(const std::string& prefFile)
{
    // sol::state lua;
    // lua.open_file(prefFile);

    // windowWidth  = lua.get<int>("width");
    // windowHeight = lua.get<int>("height");
    // windowType   = lua.get<int>("style");
}

int PrefManager::getWidth()
{
    return windowWidth;
}

int PrefManager::getHeight()
{
    return windowHeight;
}

int PrefManager::getType()
{
    return windowType;
}

