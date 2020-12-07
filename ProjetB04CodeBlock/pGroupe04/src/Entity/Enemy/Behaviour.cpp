#include "Entity/Enemy/Behaviour.h"
#include <stdlib.h>
#include <time.h>

// Constructeur
Behaviour::Behaviour(int l_rate)
{
    srand(time(NULL));
    m_rate = l_rate;
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
    // Retourne l'indice d'une ability aleatoire
    int i = getRandomAbility(l_abilities);
    // Si on a recuperer -1 alors on stoppe la methode
    if (i == -1)
        return; // On stoppe l'execution de la methode

    // On enregistre l'ability recuperee
    EnemyAbility *m_e = l_abilities[i];
    if (m_e->getClassName() == "EnemyAbilityOffensive"){
        m_e->activateEffect(l_player); // On utilise une ability offensive
    }else{
        m_e->activateEffect(l_enemy); // On utilise une ability defensive
    }
}

// Permet de recuperer une ability de maniere aleatoire
// On depend ici de m_rate qui correspond au % de chance de recuperer une ability defensive
int Behaviour::getRandomAbility(std::vector<EnemyAbility *> l_abilities)
{
    int rate = rand() % 100 + 1; // On genere un nombre aleatoire entre 1 et 100

    // Si notre liste d'ability est vide, on return -1
    if ((int)l_abilities.size() == 0){
        return -1;
    }
    // Test si on recupere une ability defensive ou offensive a partir du nombre aleatoires
    if (rate > m_rate)// Si le nombre aleatoire generer est superieur a m_rate alors on cherche une ability offensive
    {
        return searchAbilityType(l_abilities, "EnemyAbilityOffensive"); // On return une ability offensive
    }
    else    // Sinon on recherche une ability defensive
    {
        return searchAbilityType(l_abilities, "EnemyAbilityDefensive"); // On return une ability defensive
    }

}
// Recherche une ability d'un type precis dans la liste et retourne son indice
int Behaviour::searchAbilityType(std::vector<EnemyAbility *> l_abilities, std::string lookingForClassAbility)
{
    bool ok = true;
    bool offensive = false;
    bool defensive = false;
    int ind;


    // On check si l'on a bien au moins une ability offensive et une defensive dans la liste
    for(int i = 0; i < l_abilities.size(); i++){ // boucle de 0 a la taille de
        if(l_abilities[i]->getClassName() == "EnemyAbilityOffensive")// On regarde si l'ability a l'indice i
        {                                                            //     est une ability offensive
            offensive = true; // Si oui alors on passe offensive a true
        }else
        {
            defensive = true; // Sinon c'est que l'ability est defensive donc on passe defensive a true
        }
        if(offensive == true && defensive == true){ // Si on a trouve une ability offensive et defensive
            i = l_abilities.size(); // Alors on set i au max afin de stopper la boucle et eviter des operations inutile
        }
    }
    // Boucle jusqu'a trouver une ability correspondant au type demande
    // L'attribut ok va permet d'avoir une boucle "infini" jusqu'a trouver les attributs
    // offensive et defensive sont la pour confirmer que la liste contient au moins un attribut de chaque type.
    //      Cela empeche de boucler infini si l'un des types est manquant
    while (ok && offensive && defensive)
    {
        ind = rand() % ((int)l_abilities.size()); // Genere un nombre aleatoire entre 0 et la taille de notre liste
        if (l_abilities[ind]->getClassName() == lookingForClassAbility) // Si l'ability a notre emplacement aleatoire correspond au type rechercher alors
        {
            ok = false;
            return ind; // On return nombre nombre aleatoire qui correspondra a l'indice de l'ability trouvee
        }
    }
    return -1;
}



