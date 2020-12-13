#ifndef COMMANDCLEARCELL_H
#define COMMANDCLEARCELL_H
#include "command.h"

class Command_ClearCell:public Command
{
public:
    using Command::Command;
    void execute();
    
private:
    int x_c; 
    int y_c;
};

#endif
