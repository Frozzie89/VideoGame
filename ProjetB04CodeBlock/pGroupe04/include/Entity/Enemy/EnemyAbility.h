#ifndef ENEMYABILITY_H
#define ENEMYABILITY_H
#include <string>
#include <iostream>
#include "Entity/Entity.h"

// Les EnemyAbility correspondent au compétences que l'ennemi pourra utiliser durant la partie, comme des Cards bien plus simplifiées
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
    void setValue(const int l_value);

    std::string getName() const;
    void setName(const std::string l_name);
    // End GET & SET

    virtual int activateEffect(Entity &entity) = 0;
    virtual std::string getClassName() const;
    virtual EnemyAbility *clone() const = 0;

    virtual std::string toString() const = 0;

protected:
};

#endif // ENEMYABILITY_H
