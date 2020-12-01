#include "Entity/Enemy/BehaviourHighLife.h"
#include <iostream>

BehaviourHighLife::BehaviourHighLife()
{
    m_rate = 25;
}

BehaviourHighLife::~BehaviourHighLife(){    }

BehaviourHighLife::BehaviourHighLife(const BehaviourHighLife& other):Behaviour(other){      }

BehaviourHighLife& BehaviourHighLife::operator=(const BehaviourHighLife& rhs){
    if (this != &rhs)
        Behaviour::operator=(rhs);
    return *this;
}

