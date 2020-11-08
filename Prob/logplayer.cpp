#include "logfile.h"
#include "logplayer.h"
#include "observer_killed.h"


LogPlayer::LogPlayer(Player* player)
{
    this->player=player;
}


void LogPlayer::money(int money) //при увеличении денег
{
    string str = "Player took the money!:)\n Now money:"+ std::to_string(money) + '\n';
    std::cout<< str;
    addToFile(str);
}

void LogPlayer::live(int live)  //при уменьшении жизней
{
    if (live==0){
    
    std::string str = "Player lost the live!:(\n Now live:"+ std::to_string(live)+'\n'+"Stone kill player!\nYOU LOSE!\n";
    std::cout<<str;
        addToFile(str);
        Killed->update();       //!!!!!!здесь ошибка
    }
    else{
        std::string str = "Player lost the live!:(\n Now live:"+ to_string(live)+'\n';
        std::cout<<str;
            addToFile(str);
    }
}

void LogPlayer::X_Y(int x, int y) //позиция игрока
{   

    if (x==12&&y==9){
    std::string str = "X:" + to_string(x) + "   " + "Y:" + std::to_string(y) + "\nYOU WIN!\n";
    std::cout<<str;
    addToFile(str);
    }
    else{
        std::string str = "X:" + to_string(x) + "   " + "Y:" + std::to_string(y) + '\n';
        std::cout<<str;
        addToFile(str);
    }

}

void LogPlayer::addToFile(std::string str)
{
    logfile logfile;
    logfile.addLog(str);
}
