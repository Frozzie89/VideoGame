#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Entity/Enemy/Behaviour.h"

// Constructeur
Behaviour::Behaviour()
{
    srand((unsigned)time(0));
}

//Destructeur
Behaviour::~Behaviour() {}

Behaviour::Behaviour(const Behaviour &other)
{
    m_rate = other.m_rate;
}

Behaviour &Behaviour::operator=(const Behaviour &rhs)
{
    if (this != &rhs)
        m_rate = rhs.m_rate;

    return *this;
}

// M�thode dont le but sera de r�cup�rer une ability via la m�thode "getRandomAbility"
// Pour ensuite activer l'effet de cette ability d�pendant de si elle est offensive ou d�fensive
void Behaviour::useAbility(Entity &l_player, Entity &l_enemy, std::vector<EnemyAbility *> l_abilities)
{
    int i = getRandomAbility(l_abilities);
    if (i == -1)
        return;

    EnemyAbility *m_e = l_abilities[i];
    if (m_e->getClassName() == "EnemyAbilityOffensive")
        m_e->activateEffect(l_player);

    else
        m_e->activateEffect(l_enemy);
}

// Permet de r�cup�rer une ability de mani�re al�atoire
// On d�pend ici de m_rate qui correspond au % de chance de r�cuperer une ability d�fensive
int Behaviour::getRandomAbility(std::vector<EnemyAbility *> l_abilities)
{

    int rate = rand() % 100 + 1;
    std::cout << rate << ">" << m_rate << std::endl;
    // Si notre liste d'ability est vide, on return -1
    if ((int)l_abilities.size() == 0)
        return -1;

    if (rate > m_rate)
        return searchAbilityType(l_abilities, "EnemyAbilityOffensive");

    else
        return searchAbilityType(l_abilities, "EnemyAbilityDefensive");
}
// Recherche une ability d'un type pr�cis dans la liste et retourne son indice
int Behaviour::searchAbilityType(std::vector<EnemyAbility *> l_abilities, std::string lookingForClassAbility)
{
    bool ok = true;
    int ind;
    std::cout << lookingForClassAbility << std::endl;
    while (ok)
    {
        ind = rand() % ((int)l_abilities.size());
        if (l_abilities[ind]->getClassName() == lookingForClassAbility)
            return ind;
    }

    return -1;
}
