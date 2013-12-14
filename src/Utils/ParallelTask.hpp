#ifndef _ParallelTask_hpp_
#define _ParallelTask_hpp_

#include <SFML/System/Thread.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>
#include <SFML/System/Clock.hpp>

class ParallelTask
{
    public:
    ParallelTask();
    void execute();
    bool isFinished();
    virtual float getCompletion();

    private:
    virtual void runTask();

    private:
    sf::Thread thread;
    sf::Mutex mutex;

    sf::Clock elapsedTime;
    bool finished;
};

#endif // _ParallelTask_hpp_














