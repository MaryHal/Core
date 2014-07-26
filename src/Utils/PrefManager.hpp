#ifndef _PrefManager_hpp_
#define _PrefManager_hpp_

#include <string>

class PrefManager
{
    private:
        int windowWidth;
        int windowHeight;
        int windowType;

    public:
        PrefManager(const std::string& prefFile);

        int getWidth();
        int getHeight();
        int getType();
};

#endif // _PrefManager_hpp_
