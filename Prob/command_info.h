#ifndef COMMANDINFO_H
#define COMMANDINFO_H
#include "command.h"

class Command_Info:public Command
{
public:
    using Command::Command;
    void execute();
};

#endif
