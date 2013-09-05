#ifndef _CommandQueue_hpp_
#define _CommandQueue_hpp_

#include "Command.hpp"
#include <queue>

class CommandQueue
{
    public:
        void push(const Command& command);
        Command pop();
        bool isEmpty();

    private:
        std::queue<Command> commands;
};

#endif // _CommandQueue_hpp_

