#ifndef SQUARE_H
#define SQUARE_H

#include "cell.h"

using namespace std;

class Square
{
private:
    friend class Game;
    friend class SquareIterator;
    int x = 10;
    int y = 13;
    Cell** *obj;
    static Square* singleton_;

    //Square(); //конструктор
    //~Square(); //деструктор

    Square(Square &square); //конструктор копирования
    Square(Square &&square);//конструктор перемещения
    //оператор копирования
    Square &operator=(Square &square){
        //Исключение самоприсваивания
        if (&square == this)
            return *this;
        //очищаем память (указатели до исключения)
        for (int i = 0; i < y; ++i){
            delete (obj[i]);
        }
        delete (obj);
      //Копирование
      obj = new Cell **[x];
      for (int i = 0; i < x; i++) {
          obj[i] = new Cell *[y];
          for (int j = 0; j < y; j++) {
              obj[i][j] = nullptr;
          }
      }
      for (int i = 0; i < x; ++i) {
          for (int j = 0; j < y; ++j) {
              obj[i][j] = square.obj[i][j];
          }
      }
      return *this;
}

    //оператор перемещения
    Square &operator=(Square &&square){
    //исключение самоприсваивания
    if (&square == this)
        return *this;
    //очищаем память (указатели до исключения)
    this->x = square.x;
    this->y = square.y;
    this->obj = square.obj;
    return *this;
    }

public:

    static Square* getInstance(const int x, const int y);
    Square(int x, int y);
    ~Square(); //деструктор
    int GetX();
    int GetY();
};

#endif // SQUARE_H
