#include "OffensiveCard.h"

using namespace std;

OffensiveCard::OffensiveCard(string label, string description, int costAction, int value)
{
    setLabel(label);
    setDescription(description);
    setCostAction(costAction);
    setValue(value);
}

OffensiveCard::~OffensiveCard() {}

OffensiveCard::OffensiveCard(const OffensiveCard &other)
{
    setLabel(other.getLabel());
    setDescription(other.getDescription());
    setCostAction(other.getCostAction());
    setValue(other.getValue());
}

OffensiveCard &OffensiveCard::operator=(const OffensiveCard &rhs)
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