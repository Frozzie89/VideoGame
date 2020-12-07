#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include <string>
#include "Entity/Entity.h"
#include "Entity/Enemy/EnemyAbilityDefensive.h"
#include "Entity/Enemy/EnemyAbilityOffensive.h"
#include "Entity/Enemy/Behaviour.h"

// Defini un ennemi
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
    void getStrategy();
    std::string GetPath() const;    // Retourne le chemin de la texture de notre ennemi
    //Fin GET & SET

    // Methodes concerant le vector
    void addAbilities(EnemyAbility *l_enemyAbility);    // Ajoute une ability a notre liste d'abilities
    void removeAbilities(EnemyAbility *l_enemyAbility); // Retire l'ability envoyee en argument de notre liste
    int SearchAbility(EnemyAbility &l_enemyAbility);    // Recherche une ability dans la liste et en renvoie l'indice
    std::vector<EnemyAbility *> getAbilitiesList();     // Retourne la liste d'abilities
    // Fin vector

    //Strategy
    void useAbility(Entity &entity);

    std::string str() const;        // Affiche l'objet

protected:
};

#endif // ENEMY_H
