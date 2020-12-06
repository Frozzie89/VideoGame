#include <sstream>
#include <iostream>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Entity/Player/Player.h"
#include "Entity/Enemy/Enemy.h"

Player::Player(int actionPoints) : Entity(), actionPoints(actionPoints)
{
    srand((unsigned)time(0));
    Shield shieldPlayer;
    Health healthPlayer;

    Entity::AddShield(shieldPlayer);
    Entity::AddHealth(healthPlayer);
}

Player::Player(int actionPoints, int healthPt, int shieldPt) : Entity(), actionPoints(actionPoints)
{
    srand((unsigned)time(0));
    Shield shieldPlayer(shieldPt);
    Health healthPlayer(healthPt);

    Entity::AddShield(shieldPlayer);
    Entity::AddHealth(healthPlayer);

    setMaxLife(healthPt);
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

std::vector<Card *> Player::getCardPile(const int cardVector)
{
    return cardPiles[cardVector];
}

// For Defensive Cards
void Player::useCard(Card &card)
{
    if (findCard(card, Player::hand) == -1)
        return;

    if (actionPoints >= card.getCostAction())
    {
        card.activateEffect(*this);
        removeCard(&card, Player::hand);
        actionPoints -= card.getCostAction();
    }
}

// For Offensive Cards
void Player::useCard(Card &card, Entity &enemy)
{
    if (findCard(card, Player::hand) == -1)
        return;

    Health h;

    if (actionPoints >= card.getCostAction())
    {
        card.activateEffect(enemy);
        removeCard(&card, Player::hand);
        actionPoints -= card.getCostAction();
    }
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
    if ((int)cardPiles.at(cardVector).size() == 0)
        return -1;

    for (int i = (int)cardPiles.at(cardVector).size() - 1; i >= 0; i--)
    {
        if (*cardPiles.at(cardVector)[i] == card)
            return i;
    }
    return -1;
}

void Player::purgeCardPile(const int cardVector)
{
    /*
    for (auto &&card : cardPiles[cardVector])
    {
        delete card;
    }
    */

    for (int i = 0; i < cardPiles[cardVector].size(); i++)
    {
        delete cardPiles.at(cardVector)[i];
    }

    cardPiles[cardVector].clear();
}

void Player::initDeck()
{
    // On s'assure que Deck n'a aucune cartes
    purgeCardPile(Player::deck);

    // On copie le vecteur Pool dans le vecteur Deck
    for (auto &&card : cardPiles[Player::pool])
    {
        cardPiles[Player::deck].push_back(card->clone());
    }

    // On mélange les cartes dans le deck
    std::default_random_engine randomizer = std::default_random_engine(time(0));
    std::shuffle(std::begin(cardPiles[Player::deck]), std::end(cardPiles[Player::deck]), randomizer);
}

void Player::drawCards(int nbCards)
{
    purgeCardPile(Player::hand);

    // s'il n'y plus de cartes dans le deck, on regénère le deck
    if ((int)cardPiles[Player::deck].size() == 0)
        initDeck();

    // on s'assure de ne pas piocher plus que le nombre de cartes restant dans le deck
    nbCards = (nbCards > (int)cardPiles[Player::deck].size() ? (int)cardPiles[Player::deck].size() : nbCards);

    int deckSize = (int)cardPiles[Player::deck].size();

    for (int i = deckSize - 1; i > deckSize - nbCards - 1; i--)
    {
        cardPiles[Player::hand].push_back(cardPiles[Player::deck][i]->clone());
        removeCard(cardPiles[Player::deck][i], Player::deck);
    }
}

std::string Player::printMap()
{
    std::stringstream res;

    res << "POOL : ";
    for (auto &&card : cardPiles[Player::pool])
    {
        res << card->getLabel() << " - ";
    }
    res << std::endl
        << "DECK : ";

    for (auto &&card : cardPiles[Player::deck])
    {
        res << card->getLabel() << " - ";
    }
    res << std::endl
        << "HAND : ";

    for (auto &&card : cardPiles[Player::hand])
    {
        res << card->getLabel() << " - ";
    }

    return res.str();
}

std::string Player::printPathCardPile(const int cardVector)
{
    std::stringstream res;
    for (auto &&card : cardPiles[cardVector])
    {
        res << card->getPath() << std::endl;
        ;
    }
    return res.str();
}

std::string Player::str()
{
    Health h, *playerhealth;
    Shield s, *playerShield;

    playerhealth = (Health *)Entity::getCharacteristic(h);
    playerShield = (Shield *)Entity::getCharacteristic(s);

    return "LIFE : " + to_string(playerhealth->GetValue()) + " - SHIELD : " + to_string(playerShield->GetValue());
}

std::string Player::getClassName() const
{
    return "Player";
}
