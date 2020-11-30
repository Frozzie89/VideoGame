#include "Entity/Enemy/Enemy.h"

Enemy::Enemy(): Entity()
{
    Health healthEnemy;
    Entity::AddHealth(healthEnemy);
}
Enemy::Enemy(int l_healthPt): Entity()
{
    Health m_healthEnemy(l_healthPt);
    Entity::AddHealth(m_healthEnemy);
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

std::string Enemy::getClassName() const
{
    return "Enemy";
}
