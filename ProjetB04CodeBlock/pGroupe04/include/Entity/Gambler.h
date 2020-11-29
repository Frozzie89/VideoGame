#ifndef GAMBLER_PGROUPE04_H
#define GAMBLER_PGROUPE04_H
#include <string>
#include "Player.h"

class Gambler : public Player
{
private:
    int luck;

public:
    Gambler(int luck = 50);
    Gambler(int actionPoints, int luck = 50);
    virtual ~Gambler();
    Gambler(const Gambler &other);
    Gambler &operator=(const Gambler &rhs);

    virtual std::string useCard(DefensiveCard &card);
    virtual std::string useCard(OffensiveCard &card, Entity &enemy);
    virtual void action();
    bool throwDie() const;
    virtual std::string getClassName() const;
};

#endif // GAMBLER_PGROUPE04_H