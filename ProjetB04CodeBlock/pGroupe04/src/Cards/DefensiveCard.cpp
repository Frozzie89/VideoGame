#include "Cards/DefensiveCard.h"

DefensiveCard::DefensiveCard(std::string label, std::string path, int costAction, int value, SharedContext *l_context, bool isHealth) : Card(label, path, costAction, value, l_context), isHealth(isHealth) {}

DefensiveCard::~DefensiveCard() {}

DefensiveCard::DefensiveCard(const DefensiveCard &other) : Card(other)
{
    isHealth = other.isHealth;
}

DefensiveCard &DefensiveCard::operator=(const DefensiveCard &rhs)
{
    if (this != &rhs)
    {
        Card::operator=(rhs);
        isHealth = rhs.isHealth;
    }
    return *this;
}

std::string DefensiveCard::str() const
{
    return Card::str() + " IsHealth : " + std::to_string(isHealth);
}

bool DefensiveCard::getIsHealth() const
{
    return isHealth;
}

void DefensiveCard::setIsHealth(const bool isHealth)
{
    this->isHealth = isHealth;
}

// Augmente la caractéristique Health ou Shield de l'entité à l'activation de la carte
int DefensiveCard::activateEffect(Entity &entity)
{
    if (getIsHealth())
    {
        Health playerHealth;
        Health *playerHealthPtr = (Health *)entity.getCharacteristic(playerHealth);

        if (playerHealthPtr->GetValue() + getValue() > entity.getMaxLife())
        {
            int remainingHealth = entity.getMaxLife() - playerHealthPtr->GetValue();
            entity.RaiseCharacteristic(playerHealth, remainingHealth);
        }
        else
        {
            entity.RaiseCharacteristic(playerHealth, getValue());
        }
    }
    else
    {
        Shield playerShield;
        entity.RaiseCharacteristic(playerShield, getValue());
    }

    return getValue();
}

std::string DefensiveCard::getClassName() const
{
    return "DefensiveCard";
}
