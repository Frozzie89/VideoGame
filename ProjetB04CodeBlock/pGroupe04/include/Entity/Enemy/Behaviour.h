#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H
#include "Entity/Entity.h"
#include "Entity/Enemy/EnemyAbility.h"
#include "Entity/Enemy/EnemyAbilityDefensive.h"
#include "Entity/Enemy/EnemyAbilityOffensive.h"

// Défini le comportement de l'ennemi lorsqu'il va jouer ses cartes
class Behaviour
{
public:
    Behaviour(int l_rate = 0);
    virtual ~Behaviour();
    Behaviour(const Behaviour &other);
    Behaviour &operator=(const Behaviour &other);

    virtual string getClassName() = 0;

    void useAbility(Entity &l_player, Entity &l_enemy, std::vector<EnemyAbility *> m_abilities);
    int getRandomAbility(std::vector<EnemyAbility *> m_abilities);
    int searchAbilityType(std::vector<EnemyAbility *> m_abilities, std::string lookingForClassAbility);

protected:
    //Defini le taux de carte defensive
    int m_rate;

private:
};

#endif // BEHAVIOUR_H
