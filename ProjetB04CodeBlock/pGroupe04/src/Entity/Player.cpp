#include <sstream>
#include "Entity/Player.h"

Player::Player() : Entity() {}
Player::Player(int actionPoints) : Entity(), actionPoints(actionPoints)
{
    Shield shieldPlayer;
    Health healthPlayer;

    Entity::AddShield(shieldPlayer);
    Entity::AddHealth(healthPlayer);
}

Player::Player(int actionPoints, int healthPt, int shieldPt) : Entity()
{
    Shield shieldPlayer(shieldPt);
    Health healthPlayer(healthPt);

    Entity::AddShield(shieldPlayer);
    Entity::AddHealth(healthPlayer);
}

Player::~Player()
{
    for (int i = 0; i < (int)cardPiles.size(); i++)
    {
        for (int j = 0; j < (int)cardPiles[i].size(); j++)
        {
            delete cardPiles[i][j];
        }
        cardPiles[i].clear();
    }
}

Player::Player(const Player &other) : Entity(other), actionPoints(other.actionPoints)
{
    for (int i = 0; i < (int)other.cardPiles.size(); i++)
    {
        for (int j = 0; j < (int)other.cardPiles.at(i).size(); j++)
        {
            cardPiles.at(i).push_back(other.cardPiles.at(i)[j]->clone());
        }
    }
}

Player &Player::operator=(const Player &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < (int)cardPiles.size(); i++)
        {
            for (int j = 0; j < (int)cardPiles[i].size(); j++)
            {
                delete cardPiles[i][j];
            }
            cardPiles[i].clear();
        }

        for (int i = 0; i < (int)rhs.cardPiles.size(); i++)
        {
            for (int j = 0; j < (int)rhs.cardPiles.at(i).size(); j++)
            {
                cardPiles.at(i).push_back(rhs.cardPiles.at(i)[j]->clone());
            }
        }
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
    int ptEffect = card.activateEffect(*this);
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

void Player::removeCard(Card *card, const int cardVector)
{
    int indexCardToRemove = findCard(*card, cardVector);

    if (indexCardToRemove == -1)
        return;

    Card *cardToDelete = *(cardPiles.at(cardVector).begin() + indexCardToRemove);
    cardPiles.at(cardVector).erase(cardPiles.at(cardVector).begin() + indexCardToRemove);
    delete cardToDelete;
}

void Player::addCard(Card *card, const int cardVector)
{
    // on autorise l'ajout de plusieurs cartes identiques
    cardPiles[cardVector].push_back(card->clone());
}

int Player::findCard(const Card &card, const int cardVector) const
{
    for (int i = 0; i < (int)cardPiles.at(cardVector).size(); i++)
    {
        if (*cardPiles.at(cardVector)[i] == card)
            return i;
    }

    return -1;
}

std::string Player::getClassName() const
{
    return "Player";
}
