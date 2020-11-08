#ifndef LOGPLAYER_H
#define LOGPLAYER_H

//#include <iostream>
//#include "logfile.h"

//using namespace std;

//class logfile;

class Player;
//class observer_act;
class observer_killed;
class LogPlayer{
    public:
        LogPlayer(Player *player);
        void live(int live);
        void X_Y(int x, int y);
        void money(int money);

    private:
        Player *player;
        //ObserverAct *Act;
        observer_killed *Killed;
        void addToFile(std::string str);
};

#endif
