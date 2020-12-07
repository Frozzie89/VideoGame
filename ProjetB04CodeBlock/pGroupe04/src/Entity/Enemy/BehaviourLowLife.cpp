#include "Entity/Enemy/BehaviourLowLife.h"

// Constructeur
BehaviourLowLife::BehaviourLowLife(int l_rate)
{
    m_rate = l_rate; // Defini le taux de chance d'utiliser une ability offensive
}

// Destructeur
BehaviourLowLife::~BehaviourLowLife() {}

// Constructeur de copie
BehaviourLowLife::BehaviourLowLife(const BehaviourLowLife &other) : Behaviour(other) {}

// Operateur d'affectation
BehaviourLowLife &BehaviourLowLife::operator=(const BehaviourLowLife &rhs)
{
    if (this != &rhs)
        Behaviour::operator=(rhs);
    return *this;
}

// Return le nom de la classe
string BehaviourLowLife::getClassName()
{
    return "BehaviourLowLife";
}
