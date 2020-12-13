#ifndef OBSERVER_ACT_H
#define OBSERVER_ACT_H
#include "observer.h"

class logfile;

class observer_act:public Observer
{
    public:
        void update();

};

#endif // OBSERVER_ACT_H
