#ifndef SQUAREITERATOR_H
#define SQUAREITERATOR_H

//#include "cell.h"
#include "square.h"
#include "squareiterator.h"
#include <iostream>

class SquareIterator
{
private:
    int xi;
    int yi;
    Square *square;
    SquareIterator(int xi, int yi);
    SquareIterator begin();
    SquareIterator end();
    void left();
    void right();
    void up();
    void down();
    bool isBegin();
    bool isEnd();
    void operator++();
    void operator--();
    Cell& operator*();
    Cell& getCell();
    Cell cell;
    bool operator !=(SquareIterator& square);
    bool operator ==(SquareIterator& square);

};
#endif // SQUAREITERATOR_H
