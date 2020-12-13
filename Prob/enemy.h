#ifndef ENEMY_H
#define ENEMY_H
#include "behavior.h"
#include <iostream>

template<class T>
class Enemy
{
private:
    T behavior;
    int x_e;
    int y_e;
    bool there;
    Player player;
    bool killed;
public:
    friend class Game;
    void operator++(){
    go();
    }
    Enemy(int x, int y){
       x_e = x;
       y_e = y;
    
    }
    void go(int x_p, int y_p){
    
    there = false;
    if ((x_p - x_e)==1&&y_p==y_e)
        there = true;
    if ((x_e - x_p)==1&&y_p==y_e)
        there = true;
    if ((y_p - y_e)==1&&x_p==x_e)
        there = true;
    if ((y_e - y_p)==1&&x_p==x_e)
        there = true;
        
    killed = false;
    if (x_p ==x_e && y_p==y_e)
        killed = true;
        
    if (x_e == 0)
        x_e = 10;
    x_e --;
    }
    
    int GetX(){
        return x_e;
    }
    int GetY(){
        return y_e;
    }
    
    
};

#endif
