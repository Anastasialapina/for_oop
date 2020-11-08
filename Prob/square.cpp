#include "square.h"

#include <iostream>

//конструктор
Square::Square(int x, int y)
{
    {
        obj = new Cell** [x];
        std::cout<<"конст"<<"\n";
        for (int i = 0; i < x; i++){
            obj[i] = new Cell *[y];
            for (int j = 0; j < y; j++){
                obj[i][j] = new Cell;
            }

        }
    }
}

//конструктор копирования
Square::Square(Square &square): x(square.x), y(square.y), obj(square.obj){
    obj = new Cell **[x];
    for (int i = 0; i < x; i++){
        obj[i] = new Cell *[y];
        for (int j = 0; j < y; j++){
            obj[i][j] = nullptr;
        }
    }

for (int i = 0; i < x; ++i){
    for (int j = 0; j < y; ++j){
        obj[i][j] = square.obj[i][j];
    }
}
}

//конструктор перемещения
Square::Square(Square &&square): x(square.x), y(square.y), obj(square.obj){

    obj = new Cell **[x];
   for (int i = 0; i < x; i++){
        obj[i] = new Cell *[y];
        for (int j = 0; j < y; j++){
            obj[i][j] = nullptr;
        }
    }
        for(int i = 0; i < x; i++){
            swap(obj[i], square.obj[i]);
        }
        swap(obj, square.obj);
}

//деструктор
Square::~Square()
{
    std::cout<<"дест"<<"\n";
   for (int i = 0; i < x; i++) {
   for (int j = 0; j < y; j++){
       delete obj[i][j];
   }
    delete [] obj[i];
    }
    //std::cout<<"дест"<<"\n";
    delete [] obj;
    
    singleton_ = nullptr;
    
}


Square* Square::getInstance(const int x, const int y)
{
    if (!singleton_)
    {
        singleton_ = new Square(x, y);
    }
    return singleton_;
}

Square* Square::singleton_= nullptr;

int Square::GetX()
{
    return x;
}

int Square::GetY()
{
    return y;
}

/*void Square::CreateSquare(){
    Square square;
    sf::RenderWindow window(sf::VideoMode((square.x)*72+2, (square.y)*72+2), "Game created by Lapina Anastasia");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //SquareInterator *s;

        int size = 70;
        int xn = 2;
        int yn = 2;
        Cell a;
        //a.DrawCell();
        for (xn = 2; xn < 720; xn = xn + 72){
            for (yn = 2; yn < 910; yn = yn +72){
                sf::RectangleShape rectangle(sf::Vector2f(size, size));
                a.DrawCell(xn, yn, rectangle);
                // Отрисовка прямоугольника
                window.draw(rectangle);
            }

       }

        window.display();
    }
}*/
