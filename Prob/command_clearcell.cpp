#include "command_clearcell.h"

void Command_ClearCell::execute()
{
    game->clearCell(x_c, y_c);
}
