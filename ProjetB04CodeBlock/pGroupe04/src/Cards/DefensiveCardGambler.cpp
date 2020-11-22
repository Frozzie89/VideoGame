#include "Cards/DefensiveCardGambler.h"

;

DefensiveCardGambler::DefensiveCardGambler(std::string label, std::string description, int costAction, int value, bool isHealth)
{
    setLabel(label);
    setDescription(description);
    setCostAction(costAction);
    setValue(value);
    setIsHealth(isHealth);
}

DefensiveCardGambler::~DefensiveCardGambler() {}

DefensiveCardGambler::DefensiveCardGambler(const DefensiveCardGambler &other)
{
    setLabel(other.getLabel());
    setDescription(other.getDescription());
    setCostAction(other.getCostAction());
    setValue(other.getValue());
    setIsHealth(other.getIsHealth());
}

DefensiveCardGambler &DefensiveCardGambler::operator=(const DefensiveCardGambler &rhs)
{
    if (this != &rhs)
    {
        setLabel(rhs.getLabel());
        setDescription(rhs.getDescription());
        setCostAction(rhs.getCostAction());
        setValue(rhs.getValue());
        setIsHealth(rhs.getIsHealth());
    }

    return *this;
}

DefensiveCardGambler *DefensiveCardGambler::clone() const
{
    return new DefensiveCardGambler(*this);
}

void DefensiveCardGambler::activateEffect()
{
    // Todo
}