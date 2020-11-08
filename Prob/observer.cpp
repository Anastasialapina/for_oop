#include "observer.h"
#include "element.h"

Observer::Observer(element *elem)
{
    this->elem = elem;
    elem->push(this);
}
