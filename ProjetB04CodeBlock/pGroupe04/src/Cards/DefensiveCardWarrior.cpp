#include "Cards/DefensiveCardWarrior.h"

// Constructeur
DefensiveCardWarrior::DefensiveCardWarrior(std::string label, std::string path, int costAction, int value, SharedContext *l_context, bool isHealth) : DefensiveCard(label, path, costAction, value, l_context, isHealth) {}

// Destructeur
DefensiveCardWarrior::~DefensiveCardWarrior() {}

// Constructeur de copie
DefensiveCardWarrior::DefensiveCardWarrior(const DefensiveCardWarrior &other) : DefensiveCard(other) {}

// Operateur d'affectation
DefensiveCardWarrior &DefensiveCardWarrior::operator=(const DefensiveCardWarrior &rhs)
{
    if (this != &rhs)
    {
        DefensiveCard::operator=(rhs);
    }

    return *this;
}

// Clone
DefensiveCardWarrior *DefensiveCardWarrior::clone() const
{
    return new DefensiveCardWarrior(*this);
}

// Active l'effet d'une carte defensive de la classe Warrior
int DefensiveCardWarrior::activateEffect(Entity &entity)
{
    return DefensiveCard::activateEffect(entity);
}

//Permet d'afficher les elements presents dans la classe
string DefensiveCardWarrior::str() const
{
    return DefensiveCard::str();
}

// Return le nom de la classe
std::string DefensiveCardWarrior::getClassName() const
{
    return "DefensiveCardWarrior";
}
