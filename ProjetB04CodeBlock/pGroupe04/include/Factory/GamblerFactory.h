#ifndef GAMBLERFACTORY_PGROUPE04_H
#define GAMBLERFACTORY_PGROUPE04_H
#include <string>
#include "AbstractFactory.h"
#include "Entity/Player/Gambler.h"
#include "Cards/OffensiveCardGambler.h"
#include "Cards/DefensiveCardGambler.h"

// Factory de Gambler permettant d'instancier des Gambler et des cartes offensives et défensives pour Gambler
class GamblerFactory : public AbstractFactory
{
private:
public:
    GamblerFactory();
    virtual ~GamblerFactory();
    GamblerFactory(const GamblerFactory &other);
    GamblerFactory &operator=(const GamblerFactory &rhs);

    // Crée un Gambler
    Gambler &buildPlayer(int actionsPoints = 10, int luck = 50);

    // Crée une Carte Offensive pour Gambler
    OffensiveCardGambler &buildOffensiveCard(std::string label, std::string path, int costAction, int value, SharedContext *m_context);

    // Crée une Carte Defensive pour Gambler
    DefensiveCardGambler &buildDefensiveCard(std::string label, std::string path, int costAction, int value, SharedContext *m_context, bool isHealth);
};

#endif // GAMBLERFACTORY_PGROUPE04_H
