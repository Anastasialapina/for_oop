#include "command_gameend.h"

void Command_GameEnd::execute()
{
    sf::RenderWindow window(sf::VideoMode(572, 548), "Game created by Lapina Anastasia");
    game->GameEnd(&window);
}
