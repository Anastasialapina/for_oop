#ifndef PLAYER_H
#define PLAYER_H

//#include "logplayer.h"

#include <ostream>

using namespace std;

class LogPlayer;

class Player
{
public:
    int x_now;
    int y_now;
    int money;
    int live;
    bool tele = true;
    LogPlayer* log;
    
/*public:*/
    friend class game;
    Player();
    int GetLive();
    int GetMoney();
    int GetX();
    int GetY();
    int Put_Money(); //добавить монет
    int Pull_Live(); //уменьшить жизни
    void Go(int x_go, int y_go);
    void teleport();
    friend ostream& operator<<(ostream & out, Player& player);

};

#endif // PLAYER_H
