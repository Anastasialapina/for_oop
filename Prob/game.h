#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

//#include "cell.h"
//#include "square.h"
#include "squareiterator.h"
#include "player.h"
//#include <string>

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
    sf::Texture texture[6];
    sf::Font font;
    sf::Text moneyInfo, liveInfo;
    Player player;
   // Game()=default;
public:
    void CreateSquare();
    void drawPlayer();
    void clearCell(int x_c, int y_c);
};

#endif // GAME_H
