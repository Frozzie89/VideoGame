#include "Cards/DefensiveCardWarrior.h"

DefensiveCardWarrior::DefensiveCardWarrior(std::string label, std::string path, int costAction, int value, SharedContext *l_context, bool isHealth) : DefensiveCard(label, path, costAction, value, l_context, isHealth) {}

DefensiveCardWarrior::~DefensiveCardWarrior() {}

DefensiveCardWarrior::DefensiveCardWarrior(const DefensiveCardWarrior &other) : DefensiveCard(other) {}

DefensiveCardWarrior &DefensiveCardWarrior::operator=(const DefensiveCardWarrior &rhs)
{
    if (this != &rhs)
    {
        DefensiveCard::operator=(rhs);
    }

    return *this;
}

DefensiveCardWarrior *DefensiveCardWarrior::clone() const
{
    return new DefensiveCardWarrior(*this);
}

int DefensiveCardWarrior::activateEffect(Entity &entity)
{
    return DefensiveCard::activateEffect(entity);
}

std::string DefensiveCardWarrior::getClassName() const
{
    return "DefensiveCardWarrior";
}
//Permet d'afficher les elements presents dans la classe
string DefensiveCardWarrior::str() const
{
    return DefensiveCard::str();
}
