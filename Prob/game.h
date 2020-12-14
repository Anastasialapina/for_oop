#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "squareiterator.h"
#include "enemy.h"
#include "safe.h"
#include "run.h"

class Game
{
private:
    int x = 10;
    int y = 13;
    int size = 40;
    
    Square *square = Square::getInstance(x, y); 
    sf::RectangleShape **rect;
    sf::RectangleShape money;
    sf::RectangleShape live;
    sf::Texture texture[7];
    sf::Sprite sprite;
    sf::Font font;
    sf::Text moneyInfo, liveInfo;
    sf::Event event; //для нажатия клавиш
    Player player;
    Enemy<Behavior> enemy1 = Enemy<Behavior>(9,9);
    Enemy<Behavior> enemy2 = Enemy<Behavior>(9,6);
    Enemy<Behavior> enemy3 = Enemy<Behavior>(9,3);
    Behavior behavior;
    void addToFile(std::string str);
    
public:
    friend class Enemy<Behavior>;
    Game();
    ~Game(); 
    void Move();
    void Info_for_safe();
    void Info();
    void CreateSquare();
    void drawPlayer();
    void clearCell(int x_c, int y_c);
    void GameEnd(sf::RenderWindow* window);
    void drawEnemy(int x_e, int y_e);
    void clearEnemy(int x_e, int y_e);
};

#endif // GAME_H
