#ifndef ENEMYABILITY_H
#define ENEMYABILITY_H

#include <string>
#include "Entity/Entity.h"

// Les EnemyAbility correspondent au competences que l'ennemi pourra utiliser durant la partie, comme des Cards bien plus simplifiees
class EnemyAbility
{
private:
    std::string m_name;
    int m_value;

public:
    EnemyAbility(std::string l_name = "No_name", int l_value = 0);
    virtual ~EnemyAbility();
    EnemyAbility(const EnemyAbility &other);
    EnemyAbility &operator=(const EnemyAbility &other);

    // GET & SET
    int getValue() const;
    std::string getName() const;
    // End GET & SET

    virtual int activateEffect(Entity &entity) = 0; // Active l'effet d'une ability
    virtual std::string getClassName() const;       // Retourne le nom de la classe
    virtual EnemyAbility *clone() const = 0;        // Clone notre objet

    virtual std::string str() const = 0;            // Affiche notre objet

protected:
};

#endif // ENEMYABILITY_H
