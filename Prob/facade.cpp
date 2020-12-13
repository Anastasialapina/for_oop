#include "facade.h"

Facade::Facade()
{
        command_clearcell = new Command_ClearCell(&game);
        command_move = new Command_Move(&game);
        command_createsquare = new Command_CreateSquare(&game);
        command_drawplayer = new Command_DrawPlayer(&game);
        command_gameend = new Command_GameEnd(&game);
        command_info = new Command_Info(&game); 
}

Facade::~Facade()
{
    delete command_clearcell;
    delete command_move;
    delete command_createsquare;
    delete command_drawplayer;
    delete command_gameend;
    delete command_info;
}

void Facade::start()
{
    command_createsquare->execute();
}

