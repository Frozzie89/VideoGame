#include "Cards/DefensiveCardGambler.h"

// Constructeur
DefensiveCardGambler::DefensiveCardGambler(std::string label, std::string path, int costAction, int value, SharedContext *l_context, bool isHealth) : DefensiveCard(label, path, costAction, value, l_context, isHealth) {}

// Destructeur
DefensiveCardGambler::~DefensiveCardGambler() {}

// Constructeur de copie
DefensiveCardGambler::DefensiveCardGambler(const DefensiveCardGambler &other) : DefensiveCard(other) {}

// Operateur d'affectation
DefensiveCardGambler &DefensiveCardGambler::operator=(const DefensiveCardGambler &rhs)
{
    if (this != &rhs)
    {
        DefensiveCard::operator=(rhs);
    }

    return *this;
}

// Clone
DefensiveCardGambler *DefensiveCardGambler::clone() const
{
    return new DefensiveCardGambler(*this);
}

// Active l'effet d'une carte defensive de la classe gambler
int DefensiveCardGambler::activateEffect(Entity &entity)
{
    return DefensiveCard::activateEffect(entity);
}

// Return le nom de la classe
std::string DefensiveCardGambler::getClassName() const
{
    return "DefensiveCardGambler";
}
