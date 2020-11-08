#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream> 

class element;
class Observer
{
public:
    Observer(element* elem);
    virtual void update() =0 ;
private:
    element* elem;
    element* getElem(){ return elem;}
};

#endif // OBSERVER_H
