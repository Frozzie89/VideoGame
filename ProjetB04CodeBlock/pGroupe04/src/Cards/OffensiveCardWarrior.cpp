#include "Cards/OffensiveCardWarrior.h"

// Constructeur
OffensiveCardWarrior::OffensiveCardWarrior(std::string label, std::string path, int costAction, int value, SharedContext *l_context) : OffensiveCard(label, path, costAction, value, l_context) {}

// Destructeur
OffensiveCardWarrior::~OffensiveCardWarrior() {}

// Constructeur de copie
OffensiveCardWarrior::OffensiveCardWarrior(const OffensiveCardWarrior &other) : OffensiveCard(other) {}

// Operateur d'affectation
OffensiveCardWarrior &OffensiveCardWarrior::operator=(const OffensiveCardWarrior &rhs)
{
    if (this != &rhs)
    {
        OffensiveCard::operator=(rhs);
    }
    return *this;
}

// Clone
OffensiveCardWarrior *OffensiveCardWarrior::clone() const
{
    return new OffensiveCardWarrior(*this);
}

// Active l'effet d'une carte offensive de Warrior
int OffensiveCardWarrior::activateEffect(Entity &entity)
{
    return OffensiveCard::activateEffect(entity);
}

// Return le nom de la classe
std::string OffensiveCardWarrior::getClassName() const
{
    return "OffensiveCardWarrior";
}
