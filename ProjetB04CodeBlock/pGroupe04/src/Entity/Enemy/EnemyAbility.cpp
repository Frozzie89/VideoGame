#include "Entity/Enemy/EnemyAbility.h"

// Constructeur
EnemyAbility::EnemyAbility(std::string l_name, int l_value) : m_name(l_name), m_value(l_value) {}

// Destructeur
EnemyAbility::~EnemyAbility() {}

// Constructeur de copie
EnemyAbility::EnemyAbility(const EnemyAbility &other) : m_name(other.m_name), m_value(other.m_value) {}

// Operateur d'affectation
EnemyAbility &EnemyAbility::operator=(const EnemyAbility &rhs)
{
    if (this != &rhs)
    {
        m_name = rhs.m_name;
        m_value = rhs.m_value;
    }
    return *this;
}

// GET & SET
    // Retourne la valeur de l'ability
int EnemyAbility::getValue() const
{
    return m_value;
}
    // Retourne le nom de l'ability
std::string EnemyAbility::getName() const
{
    return m_name;
}
// End GET & SET

// Retourne le nom de la classe
std::string EnemyAbility::getClassName() const
{
    return "EnemyAbility";
}
