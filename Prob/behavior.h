#ifndef BEHAVIOR_H
#define BEHAVIOR_H
#include "player.h"

class Behavior
{
public:
    void live();
    void money();
    void position();
private:
    Player player;
};

#endif
