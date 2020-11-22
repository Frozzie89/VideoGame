#include "Cards/OffensiveCardWarrior.h"

;

OffensiveCardWarrior::OffensiveCardWarrior(std::string label, std::string description, int costAction, int value)
{
    setLabel(label);
    setDescription(description);
    setCostAction(costAction);
    setValue(value);
}

OffensiveCardWarrior::~OffensiveCardWarrior() {}

OffensiveCardWarrior::OffensiveCardWarrior(const OffensiveCardWarrior &other)
{
    setLabel(other.getLabel());
    setDescription(other.getDescription());
    setCostAction(other.getCostAction());
    setValue(other.getValue());
}

OffensiveCardWarrior &OffensiveCardWarrior::operator=(const OffensiveCardWarrior &rhs)
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

OffensiveCardWarrior *OffensiveCardWarrior::clone() const
{
    return new OffensiveCardWarrior(*this);
}

void OffensiveCardWarrior::activateEffect(Entity &entity)
{
    // Todo
}