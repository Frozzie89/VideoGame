#ifndef WARRIORFACTORY_PGROUPE04_H
#define WARRIORFACTORY_PGROUPE04_H
#include <string>
#include "AbstractFactory.h"
#include "Entity/Player/Warrior.h"
#include "Cards/OffensiveCardWarrior.h"
#include "Cards/DefensiveCardWarrior.h"

// Factory de Warrior permettant d'instancier des Warrior et des cartes offensives et défensives pour Warrior
class WarriorFactory : public AbstractFactory
{
private:
public:
    WarriorFactory();
    virtual ~WarriorFactory();
    WarriorFactory(const WarriorFactory &other);
    WarriorFactory &operator=(const WarriorFactory &rhs);

    // Créer un Warrior
    Warrior &buildPlayer(int actionsPoints);

    // Crée une Carte Offensive pour Warrior
    OffensiveCardWarrior &buildOffensiveCard(std::string label, std::string path, int costAction, int value);

    // Crée une Carte Defensive pour Warrior
    DefensiveCardWarrior &buildDefensiveCard(std::string label, std::string path, int costAction, int value, bool isHealth);
};

#endif // WARRIORFACTORY_PGROUPE04_H