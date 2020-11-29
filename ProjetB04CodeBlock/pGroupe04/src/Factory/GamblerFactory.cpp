#include "Factory/GamblerFactory.h"
#include "Entity/Gambler.h"
#include "Cards/DefensiveCardGambler.h"
#include "Cards/OffensiveCardGambler.h"

GamblerFactory::GamblerFactory() : AbstractFactory() {}

GamblerFactory::~GamblerFactory() {}

GamblerFactory::GamblerFactory(const GamblerFactory &other) : AbstractFactory(other) {}

GamblerFactory &GamblerFactory::operator=(const GamblerFactory &rhs)
{
    if (this != &rhs)
    {
        AbstractFactory::operator=(rhs);
    }

    return *this;
}

Player &GamblerFactory::buildPlayer(int actionsPoints)
{
    Gambler gambler(actionsPoints);
    return gambler;
}

Player &GamblerFactory::buildPlayer(int actionsPoints, int luck)
{
    Gambler gambler(actionsPoints, luck);
    return gambler;
}

OffensiveCard &GamblerFactory::buildOffensiveCard(std::string label, std::string path, int costAction, int value)
{
    OffensiveCardGambler ocg(label, path, costAction, value);
    return ocg;
}

DefensiveCard &GamblerFactory::buildDefensiveCard(std::string label, std::string path, int costAction, int value, bool isHealth)
{
    DefensiveCardGambler dcg(label, path, costAction, value, isHealth);
    return dcg;
}
