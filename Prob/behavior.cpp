#include "behavior.h"

void Behavior::live(){

    player.Pull_Live();
}

void Behavior::money(){

    player.Pull_Money();
}

void Behavior::position(){
    
    player.start();
}


