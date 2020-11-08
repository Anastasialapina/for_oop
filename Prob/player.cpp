#include "player.h"
#include "logplayer.h"

Player::Player()
{
    x_now = 0;
    y_now = 0;
    money = 0;
    live = 3;
}

int Player::GetLive(){
    return live;
}

int Player::GetMoney(){
    return money;
}

int Player::Put_Money(){
    money++;
    log->money(money);
    return money;
}

int Player::Pull_Live(){
    live--;
    log->live(live);
    return live;
}

int Player::GetX(){
    return x_now;
}

int Player::GetY(){
    return y_now;
}

void Player::teleport()
{
    if (x_now==4 && y_now==3){
        tele = false;
        x_now = 10;
        y_now = 8;
    }
}

void Player::Go(int x_go, int y_go){
    if (x_now>0&&x_now<12){
        x_now = x_now+x_go;   
    }
    if (x_now==0&&x_go>0)
        x_now = x_now+x_go;
        
    if (x_now==12&&x_go<0)
        x_now = x_now+x_go;
        
    if (y_now>0&&y_now<9){
        y_now = y_now+y_go;   
    }
    if (y_now==0&&y_go>0)
        y_now = y_now+y_go;
    if (y_now==9&&y_go<0)
        y_now = y_now+y_go;
   
    log->X_Y(x_now, y_now);
}

ostream& operator<<(ostream & out, Player &player)
{
    out << "Player  at  (" << player.x_now << ',' << player.y_now <<"). Player have " << player.live << " live "<< "and " << player.money << " money.";
    return out;
}
