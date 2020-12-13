#ifndef COMMANDGAMEEND_H
#define COMMANDGAMEEND_H
#include "command.h"

class Command_GameEnd:public Command
{
public:
    using Command::Command;
    void execute();
};

#endif
