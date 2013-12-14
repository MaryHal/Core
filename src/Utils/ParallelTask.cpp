#include "ParallelTask.hpp"

ParallelTask::ParallelTask()
    : thread(&ParallelTask::runTask, this)
    , finished(false)
{
}

void ParallelTask::execute()
{
    finished = false;
    elapsedTime.restart();
    thread.launch();
}

bool ParallelTask::isFinished()
{
    sf::Lock lock(mutex);
    return finished;
}

float ParallelTask::getCompletion()
{
    sf::Lock lock(mutex);
    return elapsedTime.getElapsedTime().asSeconds() / 3.0f;
}

void ParallelTask::runTask()
{
    bool ended = false;
    while (!ended)
    {
        sf::Lock lock(mutex);
        if (elapsedTime.getElapsedTime().asSeconds() >= 3.0f)
        {
            ended = true;
        }
    }

    {
        sf::Lock lock(mutex);
        finished = true;
    }
}

