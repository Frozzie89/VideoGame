#include "Cards/OffensiveCardGambler.h"

// Constructeur
OffensiveCardGambler::OffensiveCardGambler(std::string label, std::string path, int costAction, int value, SharedContext *l_context) : OffensiveCard(label, path, costAction, value, l_context) {}

// Destructeur
OffensiveCardGambler::~OffensiveCardGambler() {}

// Constructeur de copie
OffensiveCardGambler::OffensiveCardGambler(const OffensiveCardGambler &other) : OffensiveCard(other) {}

// Operateur d'affectation
OffensiveCardGambler &OffensiveCardGambler::operator=(const OffensiveCardGambler &rhs)
{
    if (this != &rhs)
    {
        OffensiveCard::operator=(rhs);
    }
    return *this;
}

// Clone
OffensiveCardGambler *OffensiveCardGambler::clone() const
{
    return new OffensiveCardGambler(*this);
}

// Active l'effet d'une carte offensive de la classe Gambler
int OffensiveCardGambler::activateEffect(Entity &entity)
{
    return OffensiveCard::activateEffect(entity);
}

// Return le nom de la classe
std::string OffensiveCardGambler::getClassName() const
{
    return "OffensiveCardGambler";
}
