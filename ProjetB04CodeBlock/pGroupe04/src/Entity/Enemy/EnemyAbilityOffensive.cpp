#include "Entity/Enemy/EnemyAbilityOffensive.h"

EnemyAbilityOffensive::EnemyAbilityOffensive(std::string l_name, int l_value) : EnemyAbility(l_name, l_value) {}

EnemyAbilityOffensive::~EnemyAbilityOffensive() {}

EnemyAbilityOffensive::EnemyAbilityOffensive(const EnemyAbilityOffensive &other) : EnemyAbility(other) {}

EnemyAbilityOffensive &EnemyAbilityOffensive::operator=(const EnemyAbilityOffensive &rhs)
{
    if (this != &rhs)
    {
        EnemyAbility::operator=(rhs);
    }
    return *this;
}

int EnemyAbilityOffensive::activateEffect(Entity &entity)
{
    Health playerHealth;

    entity.LowerCharacteristic(playerHealth, getValue());
    return getValue();
}

std::string EnemyAbilityOffensive::toString() const
{
    return "Name:" + getName() + "     \tValue:" + std::to_string(getValue());
}

std::string EnemyAbilityOffensive::getClassName() const
{
    return "EnemyAbilityOffensive";
}
