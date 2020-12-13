#ifndef COMMANDENDGAME_H
#define COMMANDENDGAME_H
#include "command.h"

class Command_Move:public Command
{
public:
    using Command::Command;
    void execute();
};

#endif
