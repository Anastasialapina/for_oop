#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

class Cell
{
private:
    int xn;
    int yn;
public:
    int size = 70;
    enum type {o, s, m, t, i, e};
    type Tip;
    Cell();
    ~Cell(){};
};

#endif // CELL_H
