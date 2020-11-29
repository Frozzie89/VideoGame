#include "Entity/Warrior.h"

Warrior::Warrior() {}
Warrior::Warrior(int actionPoints) : Player(actionPoints) {}

Warrior::~Warrior() {}

Warrior::Warrior(const Warrior &other) : Player(other) {}

Warrior &Warrior::operator=(const Warrior &rhs)
{
    if (this != &rhs)
    {
        Player::operator=(rhs);
    }

    return *this;
}

std::string Warrior::getClassName() const
{
    return "Warrior";
}

std::string Warrior::useCard(DefensiveCard &card)
{
    return Player::useCard(card);
}

std::string Warrior::useCard(OffensiveCard &card, Entity &enemy)
{
    return Player::useCard(card, enemy);
}

void Warrior::action()
{
    // Todo
    // Lucien dit : cette méthode ne me semble pas utile
}
