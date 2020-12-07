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
//      Reduit la vie de l'entity recuperee en argument
//      Si l'entity a du shield, il sera reduit en priorite
int EnemyAbilityOffensive::activateEffect(Entity &entity)
{
    Shield s;
    Shield *entityShield;
    // On recupere les points de defenses du joueur
    entityShield = (Shield *)entity.getCharacteristic(s);

    // points de degats restant a infliguer dans le cas où le joueur a de l'armure mais moindre que
    // les points de degats à infliger, le restant attaquera ses points de vies
    int remainingDmg = getValue();

    if (entityShield->GetValue() > 0)   // Si le joueur a des points d'armure ...
    {

        if (entityShield->GetValue() < getValue())  // mais qu'il a moins d'armure que les points de degats qu'il s'apprete a reçevoir ..
        {
            // rectifier les points de degats restant à infliger et mettre les points de defense à 0
            remainingDmg -= entityShield->GetValue();
            entity.LowerCharacteristic(*entityShield, entityShield->GetValue());
        }
        else    // et qu'il a suffisamment d'armure pour encaisser de coup -> prendre l'entierete des degats dans l'armure
        {
            entity.LowerCharacteristic(*entityShield, getValue());
            remainingDmg = 0;
        }
    }
    // s'il reste des points de degats à infliger, le reste ira dans les points de vie du joueur
    if (remainingDmg > 0)
    {
        Health playerHealth;
        entity.LowerCharacteristic(playerHealth, remainingDmg);
        remainingDmg = 0;
    }

    return getValue();
}

// Return les informations de l'objet
std::string EnemyAbilityOffensive::str() const
{
    return "Name:" + getName() + "     \tValue:" + std::to_string(getValue());
}

// Return le nom de la classe
std::string EnemyAbilityOffensive::getClassName() const
{
    return "EnemyAbilityOffensive";
}
