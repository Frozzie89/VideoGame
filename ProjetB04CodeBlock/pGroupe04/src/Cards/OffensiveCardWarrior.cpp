#include "Cards/OffensiveCardWarrior.h"

OffensiveCardWarrior::OffensiveCardWarrior(std::string label, std::string path, int costAction, int value, SharedContext *l_context) : OffensiveCard(label, path, costAction, value, l_context) {}

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
    return "OffensiveCardWarrior";
}
