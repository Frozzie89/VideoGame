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