#include <iostream>
#include "Entity/Enemy/Enemy.h"
Enemy::Enemy() : Entity()
{
    Health healthEnemy;
    Shield shieldEnemy(0);
    Entity::AddHealth(healthEnemy);
    Entity::AddShield(shieldEnemy);
}
Enemy::Enemy(int l_healthPt) : Entity()
{
    Health m_healthEnemy(l_healthPt);
    Shield shieldEnemy(0);
    Entity::AddHealth(m_healthEnemy);
    Entity::AddShield(shieldEnemy);
}

Enemy::~Enemy() {}

Enemy::Enemy(const Enemy &other) : Entity(other) {}

Enemy &Enemy::operator=(const Enemy &rhs)
{
    if (this != &rhs)
        Entity::operator=(rhs);

    return *this;
}
//GET & SET
void Enemy::setStrategy(Behaviour *l_behaviour)
{
    behaviour = l_behaviour;
}
//Fin GET & SET

// M�thodes concernant le vector

//Ajout d'une ability au vector d'abilities
void Enemy::addAbility(EnemyAbility *l_enemyAbility)
{
    if (searchAbility(*l_enemyAbility) == -1)
        m_abilities.push_back(l_enemyAbility->clone());

    std::cout << "Push - " << m_abilities[(int)m_abilities.size() - 1]->toString() << std::endl;
}

//Retirer une ability du vector d'abilities
void Enemy::removeAbility(EnemyAbility *l_enemyAbility)
{
    int indiceEnemy = searchAbility(*l_enemyAbility);
    if (indiceEnemy == -1)
        return;

    EnemyAbility *tmp = *(m_abilities.begin() + indiceEnemy);
    m_abilities.erase(m_abilities.begin() + indiceEnemy);
    delete tmp;
}

//Permet de retrouver une ability dans notre liste
int Enemy::searchAbility(EnemyAbility &l_enemyAbility)
{
    for (int i = 0; i < (int)m_abilities.size(); i++)
    {
        if (m_abilities[i]->getName() == l_enemyAbility.getName())
            return i;
    }
    return -1;
}
// Fin vector

// Strategy
void Enemy::useAbility(Entity &entity)
{
    behaviour->useAbility(entity, *this, m_abilities);
}

std::string Enemy::getClassName() const
{
    return "Enemy";
}
