#ifndef WARRIORFACTORY_PGROUPE04_H
#define WARRIORFACTORY_PGROUPE04_H
#include <string>
#include "AbstractFactory.h"
#include "Entity/Warrior.h"
#include "Cards/OffensiveCardWarrior.h"
#include "Cards/DefensiveCardWarrior.h"

class WarriorFactory : public AbstractFactory
{
private:
public:
    WarriorFactory();
    virtual ~WarriorFactory();
    WarriorFactory(const WarriorFactory &other);
    WarriorFactory &operator=(const WarriorFactory &rhs);

    Warrior &buildPlayer(int actionsPoints);
    OffensiveCardWarrior &buildOffensiveCard(std::string label, std::string path, int costAction, int value);
    DefensiveCardWarrior &buildDefensiveCard(std::string label, std::string path, int costAction, int value, bool isHealth);
};

#endif // WARRIORFACTORY_PGROUPE04_H