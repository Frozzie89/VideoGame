#include "DefensiveCard.h"

using namespace std;

DefensiveCard::DefensiveCard(string label, string description, int costAction, int value, bool isHealth) : isHealth(isHealth)
{
    setLabel(label);
    setDescription(description);
    setCostAction(costAction);
    setValue(value);
}

DefensiveCard::~DefensiveCard() {}

DefensiveCard::DefensiveCard(const DefensiveCard &other)
{
    setLabel(other.getLabel());
    setDescription(other.getDescription());
    setCostAction(other.getCostAction());
    setValue(other.getValue());
}

DefensiveCard &DefensiveCard::operator=(const DefensiveCard &rhs)
{
    if (this != &rhs)
    {
        setLabel(rhs.getLabel());
        setDescription(rhs.getDescription());
        setCostAction(rhs.getCostAction());
        setValue(rhs.getValue());
    }
    return *this;
}

bool DefensiveCard::getIsHealth() const
{
    return isHealth;
}

void DefensiveCard::setIsHealth(const bool isHealth)
{
    this->isHealth = isHealth;
}
