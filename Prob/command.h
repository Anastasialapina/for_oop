#ifndef COMMAND_H
#define COMMAND_H
#include "game.h"

class Command
{
public:
    Command(Game* game){game=game;}
    virtual void execute() = 0;
protected:
    Game *game;
};

#endif
