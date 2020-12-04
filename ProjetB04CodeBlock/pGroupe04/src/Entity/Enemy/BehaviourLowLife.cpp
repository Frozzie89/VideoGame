#include "Entity/Enemy/BehaviourLowLife.h"

// Constructeur
BehaviourLowLife::BehaviourLowLife()
{
    m_rate = 75;    // Defini le taux de chance d'utiliser une ability offensive
}

// Destructeur
BehaviourLowLife::~BehaviourLowLife(){   }

// Constructeur de copie
BehaviourLowLife::BehaviourLowLife(const BehaviourLowLife& other):Behaviour(other){     }

// Operateur d'affectation
BehaviourLowLife& BehaviourLowLife::operator=(const BehaviourLowLife& rhs){
    if (this != &rhs)
        Behaviour::operator=(rhs);
    return *this;
}
