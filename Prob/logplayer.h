#ifndef LOGPLAYER_H
#define LOGPLAYER_H

#include <iostream>

using namespace std;

class Player;

class LogPlayer{
    public:
        LogPlayer(Player *player);
        void live(int live);
        void X_Y(int x, int y);
        void money(int money);

    private:
        Player *player;
        void addToFile(std::string str);
};

#endif
