#ifndef ENEMYABILITYOFFENSIVE_H
#define ENEMYABILITYOFFENSIVE_H
#include "Entity/Enemy/EnemyAbility.h"

// EnemyAbility de type Offensive, infligera des degats au joueur
class EnemyAbilityOffensive : public EnemyAbility
{
public:
    EnemyAbilityOffensive(std::string l_name = "No_name", int l_value = 1);
    virtual ~EnemyAbilityOffensive();
    EnemyAbilityOffensive(const EnemyAbilityOffensive &other);
    EnemyAbilityOffensive &operator=(const EnemyAbilityOffensive &other);

    int activateEffect(Entity &entity);
    std::string getClassName() const;

    //Clone
    EnemyAbilityOffensive *clone() const { return new EnemyAbilityOffensive(*this); }

    std::string toString() const;

protected:
private:
};

#endif // ENEMYABILITYOFFENSIVE_H
