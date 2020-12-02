#include "Factory/GamblerFactory.h"
#include "Entity/Player/Gambler.h"
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

Gambler &GamblerFactory::buildPlayer(int actionsPoints)
{
    Gambler *gambler = new Gambler(actionsPoints);
    return *gambler;
}

Gambler &GamblerFactory::buildPlayer(int actionsPoints, int luck)
{
    Gambler *gambler = new Gambler(actionsPoints, luck);
    return *gambler;
}

OffensiveCardGambler &GamblerFactory::buildOffensiveCard(std::string label, std::string path, int costAction, int value, SharedContext *m_context)
{
    OffensiveCardGambler *ocg = new OffensiveCardGambler(label, path, costAction, value, m_context);
    return *ocg;
}

DefensiveCardGambler &GamblerFactory::buildDefensiveCard(std::string label, std::string path, int costAction, int value, SharedContext *m_context, bool isHealth)
{
    DefensiveCardGambler *dcg = new DefensiveCardGambler(label, path, costAction, value, m_context, isHealth);
    return *dcg;
}
