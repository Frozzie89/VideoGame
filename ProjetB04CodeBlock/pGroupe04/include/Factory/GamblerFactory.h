#ifndef GAMBLERFACTORY_PGROUPE04_H
#define GAMBLERFACTORY_PGROUPE04_H
#include <string>
#include "AbstractFactory.h"
#include "Entity/Gambler.h"
#include "Cards/OffensiveCardGambler.h"
#include "Cards/DefensiveCardGambler.h"

class GamblerFactory : public AbstractFactory
{
private:
public:
    GamblerFactory();
    virtual ~GamblerFactory();
    GamblerFactory(const GamblerFactory &other);
    GamblerFactory &operator=(const GamblerFactory &rhs);

    Gambler &buildPlayer(int actionsPoints);
    Gambler &buildPlayer(int actionsPoints, int luck);
    OffensiveCardGambler &buildOffensiveCard(std::string label, std::string path, int costAction, int value);
    DefensiveCardGambler &buildDefensiveCard(std::string label, std::string path, int costAction, int value, bool isHealth);
};

#endif // GAMBLERFACTORY_PGROUPE04_H