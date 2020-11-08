#include "observer_act.h"
#include "logfile.h"

void observer_act::update()   
{
    std::string str = " Element of square impact on the player."+'\n';
    std::cout << str;

    logfile logfile;
    logfile.addLog(str);
}
