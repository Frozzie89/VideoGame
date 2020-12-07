#ifndef ENEMYABILITYDEFENSIVE_H
#define ENEMYABILITYDEFENSIVE_H

#include "Entity/Enemy/EnemyAbility.h"

// EnemyAbility de type defensive, rendra de l'armure ou de la vie à l'ennemi
class EnemyAbilityDefensive : public EnemyAbility
{
private:
    bool m_isHealth;

public:
    EnemyAbilityDefensive(std::string l_name = "No_name", int l_value = 1, bool l_isHealt = true);
    virtual ~EnemyAbilityDefensive();
    EnemyAbilityDefensive(const EnemyAbilityDefensive &other);
    EnemyAbilityDefensive &operator=(const EnemyAbilityDefensive &other);

    int activateEffect(Entity &entity);     // Active l'effet d'une ability defensive

    // GET & SET
    bool getIsHealth() const;
    std::string getClassName() const;
    // End GET & SET


    //Clone
    EnemyAbilityDefensive *clone() const { return new EnemyAbilityDefensive(*this); }   // Clone l'objet

    std::string str() const;    // Affiche l'objet

protected:
};

#endif // ENEMYABILITYDEFENSIVE_H
