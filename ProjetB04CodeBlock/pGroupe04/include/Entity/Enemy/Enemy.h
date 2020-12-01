#ifndef ENEMY_H
#define ENEMY_H
#include "Entity/Entity.h"
#include "Entity/Enemy/EnemyAbility.h"
#include "Entity/Enemy/EnemyAbilityDefensive.h"
#include "Entity/Enemy/EnemyAbilityOffensive.h"
#include "Entity/Enemy/Behaviour.h"
#include <vector>

class Enemy : public Entity
{

private:
    std::vector<EnemyAbility *> m_abilities;
    Behaviour *behaviour;

protected:
public:
    Enemy();
    Enemy(int l_healthPt);
    virtual ~Enemy();
    Enemy(const Enemy &other);
    Enemy &operator=(const Enemy &other);
    virtual std::string getClassName() const;

    //GET & SET
    void setStrategy(Behaviour *behaviour);
    //Fin GET & SET

    // M�thodes concerant le vector
    void addAbility(EnemyAbility *l_enemyAbility);
    void removeAbility(EnemyAbility *l_enemyAbility);
    int searchAbility(EnemyAbility &l_enemyAbility);
    // Fin vector

    //Strategy
    void useAbility(Entity &entity);
};

#endif // ENEMY_H
