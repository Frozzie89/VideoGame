#include <sstream>
#include "Entity/Player.h"

Player::Player() {}
Player::Player(int actionPoints) : actionPoints(actionPoints)
{
    Shield shieldPlayer;
    Health healthPlayer;

    Entity::AddShield(shieldPlayer);
    Entity::AddHealth(healthPlayer);
}

Player::Player(int actionPoints, int healthPt, int shieldPt)
{
    Shield shieldPlayer(shieldPt);
    Health healthPlayer(healthPt);

    Entity::AddShield(shieldPlayer);
    Entity::AddHealth(healthPlayer);
}

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
std::string Player::useCard(DefensiveCard &card)
{
    int ptEffect = card.activateEffect();
    std::stringstream res;

    if (card.getIsHealth())
        res << "Le joueur se soigne de "
            << ptEffect << " PV ";
    else
        res << "Le joueur se donne "
            << ptEffect << " d'armure ";

    res << "[" << card.getLabel() << "]"
        << std::endl;

    return res.str();
}

// For Offensive Cards
std::string Player::useCard(OffensiveCard &card, Entity &enemy)
{
    int ptEffect = card.activateEffect(enemy);
    std::stringstream res;

    res << "Le " << getClassName() << " inflige " << ptEffect << " dégats à l'enemi ["
        << card.getLabel() << "]"
        << std::endl;

    return res.str();
}

void Player::action()
{
    // Todo
    // Lucien dit : me semble pas utile
}

std::string Player::getClassName() const
{
    return "Player";
}
