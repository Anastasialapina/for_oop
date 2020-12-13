#ifndef COMMANDDRAWPLAYER_H
#define COMMANDDRAWPLAYER_H
#include "command.h"

class Command_DrawPlayer:public Command
{
public:
    using Command::Command;
    void execute();
};

#endif
