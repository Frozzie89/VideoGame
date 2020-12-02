#include "Factory/WarriorFactory.h"
#include "Entity/Player/Warrior.h"
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

Warrior &WarriorFactory::buildPlayer(int actionsPoints)
{
    Warrior *warrior = new Warrior(actionsPoints);
    return *warrior;
}

OffensiveCardWarrior &WarriorFactory::buildOffensiveCard(std::string label, std::string path, int costAction, int value, SharedContext *m_context)
{
    OffensiveCardWarrior *owc = new OffensiveCardWarrior(label, path, costAction, value, m_context);
    return *owc;
}

DefensiveCardWarrior &WarriorFactory::buildDefensiveCard(std::string label, std::string path, int costAction, int value, SharedContext *m_context, bool isHealth)
{
    DefensiveCardWarrior *dcw = new DefensiveCardWarrior(label, path, costAction, value, m_context, isHealth);
    return *dcw;
}
