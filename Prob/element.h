#ifndef ELEMENT_H
#define ELEMENT_H
#include <fstream>
#include <vector>

using namespace std;

class Observer;
class Player;

class element
{
    public:
        virtual void operator+(Player &player) = 0;
        void push(Observer* obs);
        void give();
        vector<Observer*> observersVector;
        ~element();
};

class Money:public element //добавляет количество монет
{
public:
    void operator+(Player &player);
    friend ostream& operator<<(ostream & out, Money& money);

private:
    Player *player;
};

class Stone:public element //камень - отнимает жизни
{
public:
    void operator+(Player &player);
    friend ostream& operator<<(ostream & out, Stone& stone);
private:
    Player *player;
};

class teleport:public element 
{
public:
    bool tele = true;
    void operator+(Player &player);

private:
    int x_from = 4;
    int y_from = 3;
    int x_to = 10;
    int y_to = 8;
    Player *player;
};

#endif
