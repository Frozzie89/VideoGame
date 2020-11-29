#include "Factory/WarriorFactory.h"
#include "Entity/Warrior.h"
#include "Cards/OffensiveCardWarrior.h"
#include "Cards/DefensiveCardWarrior.h"

WarriorFactory::WarriorFactory() : AbstractFactory() {}

WarriorFactory::~WarriorFactory() {}

WarriorFactory::WarriorFactory(const WarriorFactory &other) : AbstractFactory(other) {}

WarriorFactory &WarriorFactory::operator=(const WarriorFactory &rhs)
{
    if (this != &rhs)
    {
        AbstractFactory::operator=(rhs);
    }
    return *this;
}

Player &WarriorFactory::buildPlayer(int actionsPoints)
{
    Warrior warrior(actionsPoints);
    return warrior;
}

OffensiveCard &WarriorFactory::buildOffensiveCard(std::string label, std::string path, int costAction, int value)
{
    OffensiveCardWarrior owc(label, path, costAction, value);
}

DefensiveCard &WarriorFactory::buildDefensiveCard(std::string label, std::string path, int costAction, int value, bool isHealth)
{
    DefensiveCardWarrior dcw(label, path, costAction, value, isHealth);
}