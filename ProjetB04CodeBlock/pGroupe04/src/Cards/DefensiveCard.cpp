#include "Cards/DefensiveCard.h"

DefensiveCard::DefensiveCard(std::string label, std::string path, int costAction, int value, bool isHealth) : Card(label, path, costAction, value), isHealth(isHealth) {}

DefensiveCard::~DefensiveCard() {}

DefensiveCard::DefensiveCard(const DefensiveCard &other) : Card(other)
{
    isHealth = other.isHealth;
}

DefensiveCard &DefensiveCard::operator=(const DefensiveCard &rhs)
{
    if (this != &rhs)
    {
        Card::operator=(rhs);
        isHealth = rhs.isHealth;
    }
    return *this;
}

std::string DefensiveCard::str() const
{
    return Card::str() + " IsHealth : " + std::to_string(isHealth);
}

bool DefensiveCard::getIsHealth() const
{
    return isHealth;
}

void DefensiveCard::setIsHealth(const bool isHealth)
{
    this->isHealth = isHealth;
}

std::string DefensiveCard::getClassName() const
{
    return "DefensiveCard";
}