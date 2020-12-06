#include "Cards/OffensiveCard.h"

// Constructeur
OffensiveCard::OffensiveCard(std::string label, std::string path, int costAction, int value, SharedContext *l_context) : Card(label, path, costAction, value, l_context) {}

// Destructeur
OffensiveCard::~OffensiveCard() {}

// Constructeur de copie
OffensiveCard::OffensiveCard(const OffensiveCard &other) : Card(other) {}

// Operateur d'affectation
OffensiveCard &OffensiveCard::operator=(const OffensiveCard &rhs)
{
    if (this != &rhs)
    {
        Card::operator=(rhs);
    }
    return *this;
}

// Attaque les points de vies et points de défenses de l'ennemi
int OffensiveCard::activateEffect(Entity &entity)
{
    Shield s;
    Shield *enemyShield;
    // On récupère les points de défenses de l'enemi
    enemyShield = (Shield *)entity.getCharacteristic(s);

    // points de dégats restant à infliguer dans le cas où l'ennemi à de l'armure mais moindre que
    // les points de dégats à infliguer, le restant attaquera ses points de vies
    int remainingDmg = value;

    // Si l'ennemi à des points d'armure ...
    if (enemyShield->GetValue() > 0)
    {
        // mais qu'il à moins d'armure que les points de dégats qu'il s'apprête à reçevoir ..
        if (enemyShield->GetValue() < value)
        {
            // rectifier les points de dégats restant à influger et mettre les points de défense à 0
            remainingDmg -= enemyShield->GetValue();
            entity.LowerCharacteristic(*enemyShield, enemyShield->GetValue());
        }

        // et qu'il à suffisamment d'amure pour encaisser de coup -> prendre l'entièreté des dégats dans l'armure
        else
        {
            entity.LowerCharacteristic(*enemyShield, value);
            remainingDmg = 0;
        }
    }

    // s'il reste des points de dégats à infliger, le resite ira dans les points de vie de l'enemi
    if (remainingDmg > 0)
    {
        Health enemyHealth;
        entity.LowerCharacteristic(enemyHealth, remainingDmg);
        remainingDmg=0;
    }

    return getValue();
}

// Affiche les informations de l'objet
std::string OffensiveCard::str() const
{
    return Card::str();
}

// Return le nom de la classe
std::string OffensiveCard::getClassName() const
{
    return "OffensiveCard";
}
