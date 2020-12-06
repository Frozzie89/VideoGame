#include "Cards/DefensiveCard.h"

// Constructeur
DefensiveCard::DefensiveCard(std::string label, std::string path, int costAction, int value, SharedContext *l_context, bool isHealth) : Card(label, path, costAction, value, l_context), isHealth(isHealth) {}

// Destructeur
DefensiveCard::~DefensiveCard() {}

// Constructeur de copie
DefensiveCard::DefensiveCard(const DefensiveCard &other) : Card(other)
{
    isHealth = other.isHealth;
}

// Operateur d'affectation
DefensiveCard &DefensiveCard::operator=(const DefensiveCard &rhs)
{
    if (this != &rhs)
    {
        Card::operator=(rhs);
        isHealth = rhs.isHealth;
    }
    return *this;
}

// GET & SET
bool DefensiveCard::getIsHealth() const
{
    return isHealth;
}

void DefensiveCard::setIsHealth(const bool isHealth)
{
    this->isHealth = isHealth;
}
// Fin GET & SET

// Augmente la caractéristique Health ou Shield de l'entité à l'activation de la carte
int DefensiveCard::activateEffect(Entity &entity)
{
    // si carte soin
    if (getIsHealth())
    {
        Health playerHealth;
        Health *playerHealthPtr = (Health *)entity.getCharacteristic(playerHealth);

        // si on tente de soigner plus que l'entité a
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

// Permet d'afficher les informations de l'objet
std::string DefensiveCard::str() const
{
    return Card::str() + " IsHealth : " + std::to_string(isHealth);
}

// Return le nom de la classe
std::string DefensiveCard::getClassName() const
{
    return "DefensiveCard";
}
