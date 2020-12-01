#include "Entity/Enemy/Enemy.h"
#include <iostream>
Enemy::Enemy(): Entity()
{
    Health healthEnemy;
    Shield shieldEnemy(0);
    Entity::AddHealth(healthEnemy);
    Entity::AddShield(shieldEnemy);
}
Enemy::Enemy(int l_healthPt): Entity()
{
    Health m_healthEnemy(l_healthPt);
    Shield shieldEnemy(0);
    Entity::AddHealth(m_healthEnemy);
    Entity::AddShield(shieldEnemy);
}

Enemy::~Enemy(){    }

Enemy::Enemy(const Enemy& other): Entity(other){    }

Enemy& Enemy::operator=(const Enemy& rhs)
{
    if (this == &rhs) return *this;
    Entity::operator=(rhs);
    return *this;
}


std::string Enemy::useAbility(EnemyAbilityDefensive& ability)
{
    //Todo
}

std::string Enemy::useAbility(EnemyAbilityOffensive& ability, Entity& player)
{
    //Todo
}

// Méthodes concernant le vector
    //Ajout d'une ability au vector d'abilities
void Enemy::addAbilities(EnemyAbility *l_enemyAbility){
    if(SearchAbility(*l_enemyAbility) == -1){
        m_abilities.push_back(l_enemyAbility->clone());
    }

    std::cout << m_abilities[0]->toString() << std::endl;
    std::cout << "Add: Size: " <<m_abilities.size() << std::endl;
}
void Enemy::removeAbilities(EnemyAbility* l_enemyAbility){
    int indiceEnemy = SearchAbility(*l_enemyAbility);
    if(indiceEnemy == -1)
        return;
    EnemyAbility *tmp = *(m_abilities.begin() + indiceEnemy);
    m_abilities.erase(m_abilities.begin() + indiceEnemy);
    delete tmp;
    std::cout << "Delete: Size: " <<m_abilities.size() << std::endl;
}


//Permet de retrouver une ability dans notre liste
int Enemy::SearchAbility(EnemyAbility& l_enemyAbility){
    for(int i=0; i < (int)m_abilities.size(); i++){
        if(m_abilities[i]->getClassName() == l_enemyAbility.getClassName())
            return i;
    }
    return -1;
}




// Fin vector

std::string Enemy::getClassName() const
{
    return "Enemy";
}
