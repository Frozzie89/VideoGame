#include "Entity/Enemy/Enemy.h"
#include <iostream>
Enemy::Enemy() : Entity()
{
    Health healthEnemy;
    Shield shieldEnemy(0);
    Entity::AddHealth(healthEnemy);
    Entity::AddShield(shieldEnemy);
}
Enemy::Enemy(int l_healthPt, std::string assetPath) : assetPath(assetPath), Entity()
{
    Health m_healthEnemy(l_healthPt);
    Shield shieldEnemy(0);
    Entity::AddHealth(m_healthEnemy);
    Entity::AddShield(shieldEnemy);
    Entity::setSprite(assetPath);
}

Enemy::~Enemy()
{
    for (auto &&ability : m_abilities)
    {
        delete ability;
    }
    m_abilities.clear();
}

Enemy::Enemy(const Enemy &other) : Entity(other)
{
    for (auto &&ability : other.m_abilities)
    {
        m_abilities.push_back(ability);
    }
}

Enemy &Enemy::operator=(const Enemy &rhs)
{
    if (this != &rhs)
    {
        for (auto &&ability : m_abilities)
        {
            delete ability;
        }
        m_abilities.clear();

        for (auto &&ability : rhs.m_abilities)
        {
            m_abilities.push_back(ability);
        }

        assetPath = rhs.assetPath;
        Entity::operator=(rhs);
    }
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
void Enemy::addAbilities(EnemyAbility *l_enemyAbility)
{
    if (SearchAbility(*l_enemyAbility) == -1)
    {
        m_abilities.push_back(l_enemyAbility->clone());
    }
}

//Retirer une ability du vector d'abilities
void Enemy::removeAbilities(EnemyAbility *l_enemyAbility)
{
    int indiceEnemy = SearchAbility(*l_enemyAbility);
    if (indiceEnemy == -1)
        return;
    EnemyAbility *tmp = *(m_abilities.begin() + indiceEnemy);
    m_abilities.erase(m_abilities.begin() + indiceEnemy);
    delete tmp;
}

//Permet de retrouver une ability dans notre liste
int Enemy::SearchAbility(EnemyAbility &l_enemyAbility)
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
//Retourne le nom de la classe
std::string Enemy::getClassName() const
{
    return "Enemy";
}
//Retourne les caracteristiques d'ennemies
std::string Enemy::str() const
{
    return getClassName()+" : Path : "+assetPath+ " || ";
}
//Retourne le chemin d'accès defini ici
string Enemy::GetPath() const
{
    return assetPath;
}

