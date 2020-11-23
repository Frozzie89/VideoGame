#include "Cards/OffensiveCard.h"

OffensiveCard::OffensiveCard(std::string label, std::string path, int costAction, int value) : Card(label, path, costAction, value) {}

OffensiveCard::~OffensiveCard() {}

OffensiveCard::OffensiveCard(const OffensiveCard &other) : Card(other) {}

OffensiveCard &OffensiveCard::operator=(const OffensiveCard &rhs)
{
    if (this != &rhs)
    {
        Card::operator=(rhs);
    }
    return *this;
}
