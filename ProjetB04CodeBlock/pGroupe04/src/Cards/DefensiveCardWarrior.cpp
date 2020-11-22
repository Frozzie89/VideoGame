#include "Cards/DefensiveCardWarrior.h"

;

DefensiveCardWarrior::DefensiveCardWarrior(std::string label, std::string description, int costAction, int value, bool isHealth)
{
    setLabel(label);
    setDescription(description);
    setCostAction(costAction);
    setValue(value);
    setIsHealth(isHealth);
}

DefensiveCardWarrior::~DefensiveCardWarrior() {}

DefensiveCardWarrior::DefensiveCardWarrior(const DefensiveCardWarrior &other)
{
    setLabel(other.getLabel());
    setDescription(other.getDescription());
    setCostAction(other.getCostAction());
    setValue(other.getValue());
    setIsHealth(other.getIsHealth());
}

DefensiveCardWarrior &DefensiveCardWarrior::operator=(const DefensiveCardWarrior &rhs)
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

DefensiveCardWarrior *DefensiveCardWarrior::clone() const
{
    return new DefensiveCardWarrior(*this);
}

void DefensiveCardWarrior::activateEffect()
{
    // Todo
}