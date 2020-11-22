#include "OffensiveCardGambler.h"

using namespace std;

OffensiveCardGambler::OffensiveCardGambler(string label, string description, int costAction, int value)
{
    setLabel(label);
    setDescription(description);
    setCostAction(costAction);
    setValue(value);
}

OffensiveCardGambler::~OffensiveCardGambler() {}

OffensiveCardGambler::OffensiveCardGambler(const OffensiveCardGambler &other)
{
    setLabel(other.getLabel());
    setDescription(other.getDescription());
    setCostAction(other.getCostAction());
    setValue(other.getValue());
}

OffensiveCardGambler &OffensiveCardGambler::operator=(const OffensiveCardGambler &rhs)
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

OffensiveCardGambler *OffensiveCardGambler::clone() const
{
    return new OffensiveCardGambler(*this);
}

void OffensiveCardGambler::activateEffect(Entity &entity)
{
    // Todo
}