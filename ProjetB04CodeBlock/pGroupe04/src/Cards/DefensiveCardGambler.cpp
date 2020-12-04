#include "Cards/DefensiveCardGambler.h"

DefensiveCardGambler::DefensiveCardGambler(std::string label, std::string path, int costAction, int value, SharedContext *l_context, bool isHealth) : DefensiveCard(label, path, costAction, value, l_context, isHealth) {}

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

int DefensiveCardGambler::activateEffect(Entity &entity)
{
    return DefensiveCard::activateEffect(entity);
}

std::string DefensiveCardGambler::getClassName() const
{
    return "DefensiveCardGambler";
}
