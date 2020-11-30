#ifndef PLAYER_PGROUPE04_H
#define PLAYER_PGROUPE04_H
#include <string>
#include "Cards/OffensiveCard.h"
#include "Cards/DefensiveCard.h"
#include "Entity/Entity.h"

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
