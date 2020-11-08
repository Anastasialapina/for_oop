#include "squareiterator.h"

SquareIterator::SquareIterator(int xi, int yi){
    //square = Square::getInstance(xi, yi);
    //Square square(10, 10);
    Square square = Square(10, 10);
    if (xi >= 0 && square . GetX() >xi && yi >= 0 && square . GetY() > yi){
        this->xi = xi;
        this->yi = yi;
    }
    else
        std::cout << "Invalid coordinates!" << "\n";

}

SquareIterator SquareIterator::begin(){
    return SquareIterator(0, 0);
}

SquareIterator SquareIterator::end(){
    Square square(xi,yi);
    return SquareIterator(square.x - 1, square.y - 1);
}

void SquareIterator::left(){
    if (xi!=0){
        xi = xi - cell.size;
    }
}

void SquareIterator::right(){
    if (xi!= square -> GetX() - cell.size){
        xi = xi + cell.size;
    }
}

void SquareIterator::up(){
    if (yi!=0){
        yi = yi - cell.size;
    }
}

void SquareIterator::down(){
    if (yi!= square -> GetY() - cell.size){
        yi = yi - cell.size;
    }
}

Cell& SquareIterator::getCell(){
    return cell;
}

bool SquareIterator::isBegin(){
    return (xi == 0 && yi == 0);
}

bool SquareIterator::isEnd(){
     return (xi == square -> GetY() - cell.size && yi == square->GetX() - cell.size);
}

void SquareIterator::operator++(){
    right();
}

void SquareIterator::operator--(){
    left();
}

Cell& SquareIterator::operator*(){
    return getCell();    //возвращает ссылку на клетку
}

bool SquareIterator::operator !=(SquareIterator &square){
    if (this->xi!=square.xi && this->yi!=square.yi)
        return true;
    else
        return false;
}

bool SquareIterator::operator ==(SquareIterator &square){
    if (this->xi==square.xi && this->yi==square.yi)
        return true;
    else
        return false;
}
