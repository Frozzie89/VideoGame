#ifndef PLAYER_PGROUPE04_H
#define PLAYER_PGROUPE04_H
#include <string>
#include <vector>
#include "Entity.h"
#include "Cards/Card.h"
#include "Cards/OffensiveCard.h"
#include "Cards/DefensiveCard.h"

// Les classes filles de Player sont des classes que l'utilisateur peut jouer
class Player : public Entity
{
private:
    int actionPoints;         // points d'actions
    std::vector<Card *> pool; // toutes les cartes que je joueur pourra utiliser durant sa partie de jeu
    std::vector<Card *> deck; // correspond au paquets de cartes disponibles
    std::vector<Card *> hand; // cartes que le joueur à en main

public:
    Player();
    Player(int actionPoints);
    Player(int actionPoints, int health, int shield);
    virtual ~Player();
    Player(const Player &other);
    Player &operator=(const Player &rhs);

    int getActionPoints() const;
    void setActionPoints(const int actionPoints);
    virtual std::string useCard(DefensiveCard &card);
    virtual std::string useCard(OffensiveCard &card, Entity &enemy);
    virtual std::string getClassName() const;

    // Todo : implémenter les méthodes CRUD pour les vectors
};

#endif // PLAYER_PGROUPE04_H