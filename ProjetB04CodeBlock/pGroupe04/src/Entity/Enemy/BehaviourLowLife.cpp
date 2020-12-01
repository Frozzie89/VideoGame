#include "Entity/Enemy/BehaviourLowLife.h"

BehaviourLowLife::BehaviourLowLife()
{
    m_rate = 75;
}

BehaviourLowLife::~BehaviourLowLife() {}

BehaviourLowLife::BehaviourLowLife(const BehaviourLowLife &other) : Behaviour(other) {}

BehaviourLowLife &BehaviourLowLife::operator=(const BehaviourLowLife &rhs)
{
    if (this != &rhs)
        Behaviour::operator=(rhs);

    return *this;
}
