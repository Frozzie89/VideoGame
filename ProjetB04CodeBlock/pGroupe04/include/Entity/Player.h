#ifndef PLAYER_PGROUPE04_H
#define PLAYER_PGROUPE04_H
#include <string>
#include "Entity.h"
#include "Cards/OffensiveCard.h"
#include "Cards/DefensiveCard.h"
#include "Entity.h"

// Les classes filles de Player sont des classes que l'utilisateur peut jouer
class Player : public Entity
{
private:
    int actionPoints;

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
};

#endif // PLAYER_PGROUPE04_H