#include "Entity/Enemy/Behaviour.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>

// Constructeur
Behaviour::Behaviour()
{
    srand((unsigned)time(0));
}

// Destructeur
Behaviour::~Behaviour() {}

// Constructeur de copie
Behaviour::Behaviour(const Behaviour &other)
{
    m_rate = other.m_rate;
}

// Operateur d'affectation
Behaviour &Behaviour::operator=(const Behaviour &rhs)
{
    if (this != &rhs)
        m_rate = rhs.m_rate;
    return *this;
}

// Methode dont le but sera de recuperer une ability via la methode "getRandomAbility"
// Pour ensuite activer l'effet de cette ability dependant de si elle est offensive ou defensive
void Behaviour::useAbility(Entity &l_player, Entity &l_enemy, std::vector<EnemyAbility *> l_abilities)
{

    // Retourne l'indice d'une ability aléatoire
    int i = getRandomAbility(l_abilities);
    cout<<i<<endl;
    // Si on a récupérer -1 alors on stoppe la méthode
    if (i == -1)
        return;

    // On enregistre l'ability recuperee
    EnemyAbility *m_e = l_abilities[i];
    cout<<"Ability used : " << m_e->getName()<<endl;
    if (m_e->getClassName() == "EnemyAbilityOffensive"){
        cout<<"Offensive"<<endl;
        m_e->activateEffect(l_player); // On utilise une ability offensive
    }else{
        cout<<"Defensive"<<endl;
        m_e->activateEffect(l_enemy); // On utilise une ability defensive
    }
    cout<<"AAAA"<<endl;


}

// Permet de recuperer une ability de maniere aleatoire
// On depend ici de m_rate qui correspond au % de chance de recuperer une ability defensive
int Behaviour::getRandomAbility(std::vector<EnemyAbility *> l_abilities)
{
    int rate = rand() % 100 + 1;

    // Si notre liste d'ability est vide, on return -1
    if ((int)l_abilities.size() == 0){
        return -1;
    }

    // Test si on recupere une ability defensive ou offensive a partir du nombre aleatoires
    if (rate > m_rate)
        return searchAbilityType(l_abilities, "EnemyAbilityOffensive"); // On return une ability offensive
    else
        return searchAbilityType(l_abilities, "EnemyAbilityDefensive"); // On return une ability defensive
}
// Recherche une ability d'un type precis dans la liste et retourne son indice
int Behaviour::searchAbilityType(std::vector<EnemyAbility *> l_abilities, std::string lookingForClassAbility)
{
    bool ok = true;
    int ind;
    // Boucle infinie jusqu'a trouver une ability correspondant au type demande
    while (ok)
    {
        ind = rand() % ((int)l_abilities.size());
        if (l_abilities[ind]->getClassName() == lookingForClassAbility)
        {
            ok = false;
            return ind;
        }
    }
    return -1;
}
