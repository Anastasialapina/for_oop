#ifndef STRATEGY_H
#define STRATEGY_H

#include "square.h"
#include "player.h"
#include "element.h"
#include "element_factory.h"

class Strategy {
public:
    //virtual ~Strategy () {};
    virtual element *set (Square *, Player &, element *) = 0;

};

class Context {
public:
    Context (Square *, Strategy *);
    ~Context ();
    element *logic (Player &, element *);

private:
    Square *square;
    Strategy *strategy;

};

class setLive : public Strategy {
public:
    element *set (Field *, Player &, element *);

};

class setMoney : public Strategy {
public:
    element *set (Square *, Player &, element *);

};

class setTeleport : public Strategy {
public:
    element *set (Square *, Player &, element *);

};

#endif //STRATEGY_H
