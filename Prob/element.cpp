#include "element.h"
#include "observer.h"
#include "player.h"

void Money::operator+(Player &player)
{
    player.Put_Money();
}

ostream& operator<<(ostream &out, Money &money)
{
    out << "Here money\n ";
    return out;
}

void Stone::operator+(Player &player)
{
    player.Pull_Live();
}

ostream& operator<<(ostream &out, Stone &stone)
{
    out << "Here stone\n ";
    return out;
}

void teleport::operator+(Player &player)
{
    player.teleport();
}

void element::push(Observer *obs)
{
    observersVector.push_back(obs); //добавляем
}

void element::give()
{
    for(Observer* i : observersVector)
    {
        i->update();      //обновляем все состояния
    }
}


element::~element()
{
    for(Observer* i :observersVector)
    {
        delete i;        
    }
}

