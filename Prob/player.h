#ifndef PLAYER_H
#define PLAYER_H

//#include "logplayer.h"

#include <ostream>

using namespace std;

class LogPlayer;

class Player
{
private:
    int x_now;
    int y_now;
    int money;
    int live;
    bool tele = true;
    LogPlayer* log;
    
public:
    friend class Game;
    Player();
    int GetLive();
    int GetMoney();
    int GetX();
    int GetY();
    void Put_Money(); //добавить монет
    void Pull_Money();
    void Pull_Live(); //уменьшить жизни
    void Go(int x_go, int y_go);
    void teleport();
    void start();
    friend ostream& operator<<(ostream & out, Player& player);

};

#endif // PLAYER_H
