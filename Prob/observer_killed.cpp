#include "observer_killed.h"
#include "element.h"

void observer_killed::update()
{
    std::string str = "Stone kill player" +'\n';
    std::cout<< str;

    logfile logfile;
    logfile.addLog(str);
}
