#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include <string>
#include "Entity/Entity.h"
#include "Entity/Enemy/EnemyAbility.h"
#include "Entity/Enemy/EnemyAbilityDefensive.h"
#include "Entity/Enemy/EnemyAbilityOffensive.h"
#include "Entity/Enemy/Behaviour.h"

// défini un ennemi
class Enemy : public Entity
{

private:
    std::vector<EnemyAbility *> m_abilities;
    Behaviour *behaviour;
    std::string assetPath;

public:
    Enemy();
    Enemy(int l_healthPt, std::string assetPath);
    virtual ~Enemy();
    Enemy(const Enemy &other);
    Enemy &operator=(const Enemy &other);
    virtual std::string getClassName() const;

    //GET & SET
    void setStrategy(Behaviour *behaviour);
    //Fin GET & SET

    // M�thodes concerant le vector
    void addAbilities(EnemyAbility *l_enemyAbility);
    void removeAbilities(EnemyAbility *l_enemyAbility);
    int SearchAbility(EnemyAbility &l_enemyAbility);
    // Fin vector

    //Strategy
    void useAbility(Entity &entity);

    std::string str() const;
    std::string GetPath() const;

protected:
};

#endif // ENEMY_H
