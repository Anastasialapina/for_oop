#ifndef ELEMENT_FACTORY_H
#define ELEMENT_FACTORY_H
#include "element.h"

class element_factory
{
    public:
        virtual element* createElement() = 0;
};

class money_factory:public element_factory
{
    public:
        element* createElement();

};

class stone_factory:public element_factory
{
    public:
        element* createElement();

};

class teleport_factory:public element_factory
{
    public:
        element* createElement();

};

#endif
