#include "Entity/Enemy/EnemyAbilityDefensive.h"

EnemyAbilityDefensive::EnemyAbilityDefensive(std::string l_name, int l_value, bool l_isHealth) : EnemyAbility(l_name, l_value), m_isHealth(l_isHealth)
{
    std::cout << "m_health\t" << m_isHealth << std::endl;
}

EnemyAbilityDefensive::~EnemyAbilityDefensive() {}

EnemyAbilityDefensive::EnemyAbilityDefensive(const EnemyAbilityDefensive &other) : EnemyAbility(other), m_isHealth(other.m_isHealth) {}

EnemyAbilityDefensive &EnemyAbilityDefensive::operator=(const EnemyAbilityDefensive &rhs)
{
    if (this != &rhs)
    {
        EnemyAbility::operator=(rhs);
        m_isHealth = rhs.m_isHealth;
    }

    return *this;
}

// activateEffect va augmenter les characteristics d�finie sur la carte (Health, Shield)
int EnemyAbilityDefensive::activateEffect(Entity &entity)
{
    Health enemyHealth;
    Shield enemyShield;

    if (getIsHealth())
        entity.RaiseCharacteristic(enemyHealth, getValue());
    else
        entity.RaiseCharacteristic(enemyShield, getValue());

    return getValue();
}

// GET & SET
bool EnemyAbilityDefensive::getIsHealth() const
{
    return m_isHealth;
}

void EnemyAbilityDefensive::setIsHealth(const bool l_isHealth)
{
    m_isHealth = l_isHealth;
}
// End GET & SET

std::string EnemyAbilityDefensive::toString() const
{
    return "Name:" + getName() + "     \tValue:" + std::to_string(getValue()) + " isHealth:" + std::to_string(m_isHealth);
}

std::string EnemyAbilityDefensive::getClassName() const
{
    return "EnemyAbilityDefensive";
}
