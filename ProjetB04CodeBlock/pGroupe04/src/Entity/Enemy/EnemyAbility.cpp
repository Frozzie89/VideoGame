#include "Entity/Enemy/EnemyAbility.h"

EnemyAbility::EnemyAbility()
{
    //ctor
}

EnemyAbility::~EnemyAbility()
{
    //dtor
}

EnemyAbility::EnemyAbility(const EnemyAbility& other)
{
    //copy ctor
}

EnemyAbility& EnemyAbility::operator=(const EnemyAbility& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
