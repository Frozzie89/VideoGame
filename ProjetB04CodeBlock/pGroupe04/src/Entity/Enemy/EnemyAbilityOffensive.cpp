#include "Entity/Enemy/EnemyAbilityOffensive.h"

// Constructeur
EnemyAbilityOffensive::EnemyAbilityOffensive(std::string l_name, int l_value) : EnemyAbility(l_name, l_value) {}

// Destructeur
EnemyAbilityOffensive::~EnemyAbilityOffensive() {}

// Constructeur de copie
EnemyAbilityOffensive::EnemyAbilityOffensive(const EnemyAbilityOffensive &other) : EnemyAbility(other) {}

// Operateur d'affectation
EnemyAbilityOffensive &EnemyAbilityOffensive::operator=(const EnemyAbilityOffensive &rhs)
{
    if (this != &rhs)
    {
        EnemyAbility::operator=(rhs);
    }
    return *this;
}

// Active l'effet d'une ability offensive
//      R�duit la vie de l'entity recuperee en argument
//      Si l'entity a du shield, il sera reduit en priorite
int EnemyAbilityOffensive::activateEffect(Entity &entity)
{
    Shield s;
    Shield *playerShield;
    // On récupère les points de défenses du joueur
    playerShield = (Shield *)entity.getCharacteristic(s);

    // points de dégats restant à infliguer dans le cas où le joueur à de l'armure mais moindre que
    // les points de dégats à infliguer, le restant attaquera ses points de vies
    int remainingDmg = getValue();

    // Si le joueur à des points d'armure ...
    if (playerShield->GetValue() > 0)
    {
        // mais qu'il à moins d'armure que les points de dégats qu'il s'apprête à reçevoir ..
        if (playerShield->GetValue() < getValue())
        {
            // rectifier les points de dégats restant à influger et mettre les points de défense à 0
            remainingDmg -= playerShield->GetValue();
            entity.LowerCharacteristic(*playerShield, playerShield->GetValue());
        }

        // et qu'il à suffisamment d'amure pour encaisser de coup -> prendre l'entièreté des dégats dans l'armure
        else
        {
            entity.LowerCharacteristic(*playerShield, getValue());
        }
    }

    // s'il reste des points de dégats à infliger, le resite ira dans les points de vie du joueur
    if (remainingDmg > 0)
    {
        Health playerHealth;
        entity.LowerCharacteristic(playerHealth, remainingDmg);
    }

    return getValue();
}

// Return les informations de l'objet
std::string EnemyAbilityOffensive::toString() const
{
    return "Name:" + getName() + "     \tValue:" + std::to_string(getValue());
}

// Return le nom de la classe
std::string EnemyAbilityOffensive::getClassName() const
{
    return "EnemyAbilityOffensive";
}
