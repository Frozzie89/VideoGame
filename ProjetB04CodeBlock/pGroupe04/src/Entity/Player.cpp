#include "Entity/Player.h"

Player::Player() {}
Player::Player(int actionPoints) : actionPoints(actionPoints) {}

Player::~Player() {}

Player::Player(const Player &other) : actionPoints(other.actionPoints) {}

Player &Player::operator=(const Player &rhs)
{
    if (this != &rhs)
    {
        actionPoints = rhs.actionPoints;
    }

    return *this;
}

int Player::getActionPoints() const
{
    return actionPoints;
}

void Player::setActionPoints(const int actionPoints)
{
    this->actionPoints = actionPoints;
}

// For Defensive Cards
void Player::useCard(DefensiveCard &card)
{
    if (card.getIsHealth())
    {
        // Todo -> ajouter de la vie à la caractéristique Health
        // card.activateEffect()
    }
    else
    {
        // Todo -> ajouter de la vie à la caractéristique Shield
        // card.activateEffect()
    }
}

// For Offensive Cards
void Player::useCard(OffensiveCard &card, Entity &enemy)
{
    // Todo -> accéder aux caractéristiques de l'enemi pour lui retirer des points de vies
    // card.activateEffect()
}

void Player::action()
{
    // Todo
}

std::string Player::getClassName() const
{
    return "Player";
}
