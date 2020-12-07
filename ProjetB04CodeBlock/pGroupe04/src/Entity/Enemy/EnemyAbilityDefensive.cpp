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

// activateEffect va augmenter les characteristics definie sur la carte (Health, Shield)
int EnemyAbilityDefensive::activateEffect(Entity &entity)
{
    if (getIsHealth())  // Si l'ability est de type Health
    {
        Health enemyHealth;
        Health *enemyHealthPtr = (Health *)entity.getCharacteristic(enemyHealth);

        if (enemyHealthPtr->GetValue() + getValue() > entity.getMaxLife()) // Si le soin devrai faire depasser le nombre de pv max alors on soigne uniquement de la difference
        {
            int remainingHealth = entity.getMaxLife() - enemyHealthPtr->GetValue();
            entity.RaiseCharacteristic(enemyHealth, remainingHealth);
        }
        else // Sinon on soigne de la value de l'ability
        {
            entity.RaiseCharacteristic(enemyHealth, getValue());
        }
    }
    else // Sinon, si elle n'est pas de type Health
    {
        Shield enemyShield;
        entity.RaiseCharacteristic(enemyShield, getValue()); // On augmente shield de la value de l'ability
    }

    return getValue(); // Return la value de l'ability
}

// GET & SET
    // Retourne la valeur de isHealth
bool EnemyAbilityDefensive::getIsHealth() const
{
    return m_isHealth;
}
// End GET & SET

// Return les informations de l'objet
std::string EnemyAbilityDefensive::str() const
{
    return "Name:" + getName() + "     \tValue:" + std::to_string(getValue()) + " isHealth:" + std::to_string(m_isHealth);
}

// Return le nom de la classe
std::string EnemyAbilityDefensive::getClassName() const
{
    return "EnemyAbilityDefensive";
}
