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

    int activateEffect(Entity &entity);     // Active l'effet d'une ability offensive
    // GET & SET
    std::string getClassName() const;
    // Fin GET & SET
    //Clone
    EnemyAbilityOffensive *clone() const { return new EnemyAbilityOffensive(*this); }   // Clone l'objet

    std::string str() const;    // Affiche l'objet

protected:
private:
};

#endif // ENEMYABILITYOFFENSIVE_H
