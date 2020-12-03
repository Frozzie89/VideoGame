#ifndef ABSTRACTFACTORY_PGROUPE04_H
#define ABSTRACTFACTORY_PGROUPE04_H
#include <string>
#include "Entity/Player/Player.h"
#include "Cards/Card.h"
#include "SharedContext.h"

// Factory abstraite permettant d'instancier des Players et des cartes offensives et défensives
class AbstractFactory
{
private:
public:
    AbstractFactory();
    virtual ~AbstractFactory();
    AbstractFactory(const AbstractFactory &other);
    AbstractFactory &operator=(const AbstractFactory &rhs);

    // crée un joueur
    virtual Player &buildPlayer(int actionsPoints = 10) = 0;

    // crée une carte offensive
    virtual OffensiveCard &buildOffensiveCard(std::string label, std::string path, int costAction, int value, SharedContext *m_context) = 0;

    // crée une carte défensive
    virtual DefensiveCard &buildDefensiveCard(std::string label, std::string path, int costAction, int value, SharedContext *m_context, bool isHealth) = 0;
};

#endif // ABSTRACTFACTORY_PGROUPE04_H