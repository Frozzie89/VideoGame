#ifndef GAMBLERFACTORY_PGROUPE04_H
#define GAMBLERFACTORY_PGROUPE04_H
#include <string>
#include "AbstractFactory.h"

class GamblerFactory : public AbstractFactory
{
private:
public:
    GamblerFactory();
    virtual ~GamblerFactory();
    GamblerFactory(const GamblerFactory &other);
    GamblerFactory &operator=(const GamblerFactory &rhs);

    Player &buildPlayer(int actionsPoints);
    Player &buildPlayer(int actionsPoints, int luck);
    OffensiveCard &buildOffensiveCard(std::string label, std::string path, int costAction, int value);
    DefensiveCard &buildDefensiveCard(std::string label, std::string path, int costAction, int value, bool isHealth);
};

#endif // GAMBLERFACTORY_PGROUPE04_H