#ifndef ABSTRACTFACTORY_PGROUPE04_H
#define ABSTRACTFACTORY_PGROUPE04_H
#include <string>
#include "Entity/Player.h"
#include "Cards/Card.h"

class AbstractFactory
{
private:
public:
    AbstractFactory();
    virtual ~AbstractFactory();
    AbstractFactory(const AbstractFactory &other);
    AbstractFactory &operator=(const AbstractFactory &rhs);

    virtual Player &buildPlayer(int actionsPoints) = 0;
    virtual Player &buildPlayer(int actionsPoints, int luck) = 0;
    virtual OffensiveCard &buildOffensiveCard(std::string label, std::string path, int costAction, int value) = 0;
    virtual DefensiveCard &buildDefensiveCard(std::string label, std::string path, int costAction, int value, bool isHealth) = 0;
};

#endif // ABSTRACTFACTORY_PGROUPE04_H