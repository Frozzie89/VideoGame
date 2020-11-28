#include "Cards/DefensiveCardGambler.h"

DefensiveCardGambler::DefensiveCardGambler(std::string label, std::string path, int costAction, int value, bool isHealth) : DefensiveCard(label, path, costAction, value, isHealth) {}

DefensiveCardGambler::~DefensiveCardGambler() {}

DefensiveCardGambler::DefensiveCardGambler(const DefensiveCardGambler &other) : DefensiveCard(other) {}

DefensiveCardGambler &DefensiveCardGambler::operator=(const DefensiveCardGambler &rhs)
{
    if (this != &rhs)
    {
        DefensiveCard::operator=(rhs);
    }

    return *this;
}

DefensiveCardGambler *DefensiveCardGambler::clone() const
{
    return new DefensiveCardGambler(*this);
}

int DefensiveCardGambler::activateEffect()
{
    // Todo
}

std::string DefensiveCardGambler::getClassName() const
{
    return "DefensiveCardGambler";
}