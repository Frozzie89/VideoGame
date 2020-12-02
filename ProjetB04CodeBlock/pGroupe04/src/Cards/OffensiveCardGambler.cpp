#include "Cards/OffensiveCardGambler.h"

OffensiveCardGambler::OffensiveCardGambler(std::string label, std::string path, int costAction, int value, SharedContext* l_context) : OffensiveCard(label, path, costAction, value,l_context) {}

OffensiveCardGambler::~OffensiveCardGambler() {}

OffensiveCardGambler::OffensiveCardGambler(const OffensiveCardGambler &other) : OffensiveCard(other) {}

OffensiveCardGambler &OffensiveCardGambler::operator=(const OffensiveCardGambler &rhs)
{
    if (this != &rhs)
    {
        OffensiveCard::operator=(rhs);
    }
    return *this;
}

OffensiveCardGambler *OffensiveCardGambler::clone() const
{
    return new OffensiveCardGambler(*this);
}

int OffensiveCardGambler::activateEffect(Entity &entity)
{
    return OffensiveCard::activateEffect(entity);
}

std::string OffensiveCardGambler::getClassName() const
{
    return "OffsensiveCardGambler";
}
