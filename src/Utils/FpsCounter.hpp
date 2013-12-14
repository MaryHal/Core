#ifndef _FpsCounter_hpp_
#define _FpsCounter_hpp_

#include <SFML/System/Time.hpp>
#include <ctime>

class FpsCounter
{
    public:
        FpsCounter();
        ~FpsCounter();
        void calculateFps(sf::Time elapsedTime);

        const unsigned int getFps() const;

    private:
        sf::Time updateTime;
        std::size_t frameCount;
        unsigned int fps;
};

#endif // _FpsCounter_hpp_

