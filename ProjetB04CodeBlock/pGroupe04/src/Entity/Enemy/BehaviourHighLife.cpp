#include "Entity/Enemy/BehaviourHighLife.h"

// Constructeur
BehaviourHighLife::BehaviourHighLife()
{
    m_rate = 25; // Defini le taux de chance d'utiliser une ability offensive
}

// Destructeur
BehaviourHighLife::~BehaviourHighLife() {}

// Constructeur de copie
BehaviourHighLife::BehaviourHighLife(const BehaviourHighLife &other) : Behaviour(other) {}

// Operateur d'affectation
BehaviourHighLife &BehaviourHighLife::operator=(const BehaviourHighLife &rhs)
{
    if (this != &rhs)
        Behaviour::operator=(rhs);
    return *this;
}
