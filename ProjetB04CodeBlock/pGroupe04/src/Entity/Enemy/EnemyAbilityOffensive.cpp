#include "Entity/Enemy/EnemyAbilityOffensive.h"

// Constructeur
EnemyAbilityOffensive::EnemyAbilityOffensive(std::string l_name, int l_value): EnemyAbility(l_name, l_value){   }

// Destructeur
EnemyAbilityOffensive::~EnemyAbilityOffensive(){}

// Constructeur de copie
EnemyAbilityOffensive::EnemyAbilityOffensive(const EnemyAbilityOffensive& other)
{
    EnemyAbility::operator=(other);
}

// Operateur d'affectation
EnemyAbilityOffensive& EnemyAbilityOffensive::operator=(const EnemyAbilityOffensive& rhs){
    if (this != &rhs){
        EnemyAbility::operator=(rhs);
    }
    return *this;
}

// Active l'effet d'une ability offensive
//      Réduit la vie de l'entity recuperee en argument
//      Si l'entity a du shield, il sera reduit en priorite
int EnemyAbilityOffensive::activateEffect(Entity& entity)
{
    // Attributs permettant d'avoir le type de characteristic
    Health entityHealth;
    Shield entityShield;

    // On recupere la valeur de shield de l'entity
    int shield = entity.getCharacteristic(entityShield)->GetValue();

    if(shield > 0){     // Si l'ennemy a du shield alors
        if (shield < getValue()){   // Si il a moins de shield que le nombre de degats qui devrai etre subit, on set le shield a 0
            entity.LowerCharacteristic(entityShield, shield);
            entity.LowerCharacteristic(entityHealth, getValue()-shield);

        }else{  // Si il a assez de shield pour encaisser tous les degats, on reduit son shield
            entity.LowerCharacteristic(entityShield, getValue());
        }

    }else{      // Si il n'a pas de shield, on reduit les pv des degats subit
        entity.LowerCharacteristic(entityHealth, getValue());
    }
    return getValue();
}

// Return les informations de l'objet
std::string EnemyAbilityOffensive::toString() const{
    return "Name:" + getName() + "     \tValue:" + std::to_string(getValue());
}

// Return le nom de la classe
std::string EnemyAbilityOffensive::getClassName() const
{
    return "EnemyAbilityOffensive";
}
