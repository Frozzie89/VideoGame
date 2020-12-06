#include "Entity/Enemy/EnemyAbilityDefensive.h"
// Constructeur
EnemyAbilityDefensive::EnemyAbilityDefensive(std::string l_name, int l_value, bool l_isHealth) : EnemyAbility(l_name, l_value), m_isHealth(l_isHealth) {}

// Destructeur
EnemyAbilityDefensive::~EnemyAbilityDefensive() {}

// Constructeur de copie
EnemyAbilityDefensive::EnemyAbilityDefensive(const EnemyAbilityDefensive &other) : EnemyAbility(other)
{
    m_isHealth = other.m_isHealth;
}

// Operateur de copie
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

    // si ability soin
    if (getIsHealth())
    {
        Health enemyHealth;
        Health *enemyHealthPtr = (Health *)entity.getCharacteristic(enemyHealth);

        // si on tente de soigner plus que l'entité a
        if (enemyHealthPtr->GetValue() + getValue() > entity.getMaxLife())
        {
            int remainingHealth = entity.getMaxLife() - enemyHealthPtr->GetValue();
            entity.RaiseCharacteristic(enemyHealth, remainingHealth);
        }
        else
        {
            entity.RaiseCharacteristic(enemyHealth, getValue());
        }
    }
    else
    {
        Shield enemyShield;
        entity.RaiseCharacteristic(enemyShield, getValue());
    }

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

// Return les informations de l'objet
std::string EnemyAbilityDefensive::toString() const
{
    return "Name:" + getName() + "     \tValue:" + std::to_string(getValue()) + " isHealth:" + std::to_string(m_isHealth);
}

// Return le nom de la classe
std::string EnemyAbilityDefensive::getClassName() const
{
    return "EnemyAbilityDefensive";
}
