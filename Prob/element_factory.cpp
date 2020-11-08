#include "element_factory.h"

element* money_factory::createElement()
{
    return new Money;
}

element* stone_factory::createElement()
{
    return new Stone;
}

element* teleport_factory::createElement()
{
    return new teleport;
}
