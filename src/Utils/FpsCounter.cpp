#include "FpsCounter.hpp"

FpsCounter::FpsCounter()
    : updateTime(),
    frameCount(0),
    fps(0)
{
}

FpsCounter::~FpsCounter()
{
}

void FpsCounter::calculateFps(sf::Time elapsedTime)
{
    updateTime += elapsedTime;
    frameCount += 1;

    if (updateTime >= sf::seconds(1.0f))
    {
        fps = frameCount;
        // statText.setString(
        //     "Frames / Second = " + std::to_string(statFrameCount) + "\n" +
        //     "Time / Update = " + std::to_string(statUpdateTime.asMicroseconds() / statFrameCount) + "us");
        updateTime -= sf::seconds(1.0f);
        frameCount = 0;
    }
}

const unsigned int FpsCounter::getFps() const
{
    return fps;
}

