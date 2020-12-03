#ifndef ENEMYABILITYDEFENSIVE_H
#define ENEMYABILITYDEFENSIVE_H
#include "Entity/Enemy/EnemyAbility.h"

// EnemyAbility de type défensive, rendra de l'armure ou de la vie à l'ennemi
class EnemyAbilityDefensive : public EnemyAbility
{
private:
    bool m_isHealth;

public:
    EnemyAbilityDefensive(std::string l_name = "No_name", int l_value = 1, bool l_isHealt = true);
    virtual ~EnemyAbilityDefensive();
    EnemyAbilityDefensive(const EnemyAbilityDefensive &other);
    EnemyAbilityDefensive &operator=(const EnemyAbilityDefensive &other);

    int activateEffect(Entity &entity);

    // GET & SET
    bool getIsHealth() const;
    void setIsHealth(const bool l_isHealth);
    // End GET & SET
    std::string getClassName() const;

    //Clone
    EnemyAbilityDefensive *clone() const { return new EnemyAbilityDefensive(*this); }

    std::string toString() const;

protected:
};

#endif // ENEMYABILITYDEFENSIVE_H
