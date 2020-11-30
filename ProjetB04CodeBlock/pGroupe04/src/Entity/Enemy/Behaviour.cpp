#include "Entity/Enemy/Behaviour.h"

Behaviour::Behaviour()
{
    //ctor
}

Behaviour::~Behaviour()
{
    //dtor
}

Behaviour::Behaviour(const Behaviour& other)
{
    //copy ctor
}

Behaviour& Behaviour::operator=(const Behaviour& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
