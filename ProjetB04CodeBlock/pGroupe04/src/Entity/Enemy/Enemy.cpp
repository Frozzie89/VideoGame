#include "Enemy.h"

Enemy::Enemy()
{
    //ctor
}

Enemy::~Enemy()
{
    //dtor
}

Enemy::Enemy(const Enemy& other)
{
    //copy ctor
}

Enemy& Enemy::operator=(const Enemy& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
