#include "Entity/Enemy/EnemyAbility.h"

EnemyAbility::EnemyAbility(){}

EnemyAbility::EnemyAbility(std::string l_name, int l_value): m_value(l_value), m_name(l_name){

}

EnemyAbility::~EnemyAbility(){  }

EnemyAbility::EnemyAbility(const EnemyAbility& other): m_name(other.m_name), m_value(other.m_value){       }

EnemyAbility& EnemyAbility::operator=(const EnemyAbility& rhs)
{
    if (this != &rhs){
        m_name = rhs.m_name;
        m_value = rhs.m_value;
    }
    return *this;
}

// GET & SET
int EnemyAbility::getValue() const
{
    return m_value;
}

void EnemyAbility::setValue(const int l_value)
{
    m_value = l_value;
}

std::string EnemyAbility::getName() const
{
    return m_name;
}

void EnemyAbility::setName(const std::string l_name)
{
    m_name = l_name;
}
// End GET & SET
