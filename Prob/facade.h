#ifndef FACADE_H
#define FACADE_H
#include "command_clearcell.h"
#include "command_move.h"
#include "command_createsquare.h"
#include "command_drawplayer.h"
#include "command_gameend.h"
#include "command_info.h"

class Facade
{
    public:
        Facade();
        ~Facade();
        void start();

    private:
        Game game;
        Command *command_clearcell;
        Command *command_move;
        Command *command_createsquare;
        Command *command_drawplayer;
        Command *command_gameend;
        Command *command_info;     
};

#endif
