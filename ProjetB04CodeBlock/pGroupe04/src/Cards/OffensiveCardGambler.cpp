#include "Cards/OffensiveCardGambler.h"

OffensiveCardGambler::OffensiveCardGambler(std::string label, std::string path, int costAction, int value) : OffensiveCard(label, path, costAction, value) {}

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

void OffensiveCardGambler::activateEffect(Entity &entity)
{
    // Todo
}
