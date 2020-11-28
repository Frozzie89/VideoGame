#ifndef PLAYER_PGROUPE04_H
#define PLAYER_PGROUPE04_H
#include <string>
#include "Entity.h"
#include "Cards/OffensiveCard.h"
#include "Cards/DefensiveCard.h"
#include "Entity.h"

class Player : public Entity
{
private:
    int actionPoints;

public:
    Player();
    Player(int actionPoints);
    virtual ~Player();
    Player(const Player &other);
    Player &operator=(const Player &rhs);

    int getActionPoints() const;
    void setActionPoints(const int actionPoints);
    virtual void useCard(DefensiveCard &card);
    virtual void useCard(OffensiveCard &card, Entity &enemy);
    virtual void action();
    virtual std::string getClassName() const;
};

#endif // PLAYER_PGROUPE04_H