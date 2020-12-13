#ifndef COMMANDCREATESQIARE_H
#define COMMANDCREATESQUARE_H
#include "command.h"

class Command_CreateSquare:public Command
{
public:
    using Command::Command;
    void execute();
};

#endif
