#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include "Entity/Entity.h"
#include "Entity/Enemy/EnemyAbility.h"


// Defini le comportement de l'ennemi lorsqu'il va jouer ses cartes
class Behaviour
{
public:
    Behaviour(int l_rate = 0);                      // Constructeur avec valeur par defaut
    virtual ~Behaviour();                           // Destructeur
    Behaviour(const Behaviour &other);              // Constructeur de copie
    Behaviour &operator=(const Behaviour &other);   // Operateur d'affectation

    virtual string getClassName() = 0;              // Return le nom de la classe


    void useAbility(Entity &l_player, Entity &l_enemy, std::vector<EnemyAbility *> m_abilities);// Permet d'utiliser une ability recuperee aleatoirement
    int getRandomAbility(std::vector<EnemyAbility *> m_abilities);    // Permet de recuperer une ability de maniere aleatoire
    int searchAbilityType(std::vector<EnemyAbility *> m_abilities, std::string lookingForClassAbility);    // Permet de recuperer une ability d'un type precis donner en arguments


protected:
    int m_rate; //Defini le taux de carte defensive

private:
};

#endif // BEHAVIOUR_H
