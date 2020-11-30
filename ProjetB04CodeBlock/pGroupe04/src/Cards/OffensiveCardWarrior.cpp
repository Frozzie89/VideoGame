#include "Cards/OffensiveCardWarrior.h"

OffensiveCardWarrior::OffensiveCardWarrior(std::string label, std::string path, int costAction, int value) : OffensiveCard(label, path, costAction, value) {}

OffensiveCardWarrior::~OffensiveCardWarrior() {}

OffensiveCardWarrior::OffensiveCardWarrior(const OffensiveCardWarrior &other) : OffensiveCard(other) {}

OffensiveCardWarrior &OffensiveCardWarrior::operator=(const OffensiveCardWarrior &rhs)
{
    if (this != &rhs)
    {
        OffensiveCard::operator=(rhs);
    }
    return *this;
}

OffensiveCardWarrior *OffensiveCardWarrior::clone() const
{
    return new OffensiveCardWarrior(*this);
}

int OffensiveCardWarrior::activateEffect(Entity &entity)
{
    return OffensiveCard::activateEffect(entity);
}

std::string OffensiveCardWarrior::getClassName() const
{
    return "OffsensiveCardWarrior";
}