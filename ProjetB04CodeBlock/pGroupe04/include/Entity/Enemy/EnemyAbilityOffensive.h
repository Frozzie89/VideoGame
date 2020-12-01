#ifndef ENEMYABILITYOFFENSIVE_H
#define ENEMYABILITYOFFENSIVE_H
#include "Entity/Enemy/EnemyAbility.h"

class EnemyAbilityOffensive : public EnemyAbility
{
private:
protected:
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
};

#endif // ENEMYABILITYOFFENSIVE_H
