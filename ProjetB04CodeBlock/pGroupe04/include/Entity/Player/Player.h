#ifndef PLAYER_PGROUPE04_H
#define PLAYER_PGROUPE04_H
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
#include "Entity/Entity.h"
#include "Cards/Card.h"
#include "Cards/OffensiveCard.h"
#include "Cards/DefensiveCard.h"

// Les classes filles de Player sont des classes que l'utilisateur peut jouer
class Player : public Entity
{
private:
    int actionPoints; // le joueur paye le coût des cartes qu'il souhaite utiliser avec cette "monnaie"
    std::unordered_map<int, std::vector<Card *>> cardPiles;

public:
    Player(int actionPoints = 10);
    Player(int actionPoints, int health, int shield);
    virtual ~Player();
    Player(const Player &other);
    Player &operator=(const Player &rhs);

    int getActionPoints() const;
    void setActionPoints(const int actionPoints);
    std::vector<Card *> getCardPile(const int cardVector);
    virtual std::string getClassName() const;

    // méthodes pour jouer une carte depuis Player
    virtual void useCard(Card &card);
    virtual void useCard(Card &card, Entity &enemy);

    // méthodes CRUD pour cardPiles
    void removeCard(Card *card, const int cardVector);
    virtual void addCard(Card *card, const int cardVector);
    int findCard(const Card &card, const int cardVector) const;

    //virtual std::string str() = 0;

    // méthodes pour mélanger le deck et piocher
    void purgeCardPile(const int cardVector); // Vide un paquet de cartes
    void initDeck();                          // Mélange le deck
    void drawCards(int nbCards = 5);          // tire des cartes du deck pour les mettres dans la main

    // affiche l'état de cardPiles
    std::string printMap();

    // Enumeration
    enum cardPilesNames
    {
        pool = 0, // vector à la clé 0 => correspont à toutes les cartes que le joueur pourra utiliser durant la partie
        deck = 1, // vector à la clé 1 => correspond au paquet de cartes disponnibles
        hand = 2  // vector à la clé 2 => correspond aux cartes que le joueur à en main
    };
};

#endif // PLAYER_PGROUPE04_H
