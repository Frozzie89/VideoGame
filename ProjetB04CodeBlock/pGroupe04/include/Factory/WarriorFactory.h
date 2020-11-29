#ifndef WARRIORFACTORY_PGROUPE04_H
#define WARRIORFACTORY_PGROUPE04_H
#include <string>
#include "AbstractFactory.h"

class WarriorFactory : public AbstractFactory
{
private:
public:
    WarriorFactory();
    virtual ~WarriorFactory();
    WarriorFactory(const WarriorFactory &other);
    WarriorFactory &operator=(const WarriorFactory &rhs);

    Player &buildPlayer(int actionsPoints);
    OffensiveCard &buildOffensiveCard(std::string label, std::string path, int costAction, int value);
    DefensiveCard &buildDefensiveCard(std::string label, std::string path, int costAction, int value, bool isHealth);
};

#endif // WARRIORFACTORY_PGROUPE04_H