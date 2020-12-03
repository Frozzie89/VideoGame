#include "Cards/OffensiveCard.h"

OffensiveCard::OffensiveCard(std::string label, std::string path, int costAction, int value, SharedContext *l_context) : Card(label, path, costAction, value, l_context) {}

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

int OffensiveCard::activateEffect(Entity &entity)
{
    Health enemyHealth;

    entity.LowerCharacteristic(enemyHealth, getValue());
    return getValue();
}

std::string OffensiveCard::str() const
{
    return Card::str();
}

std::string OffensiveCard::getClassName() const
{
    return "OffensiveCard";
}
