#ifndef WARRIOR_PGROUPE04_H
#define WARRIOR_PGROUPE04_H
#include <string>
#include "Player.h"

class Warrior : public Player
{
private:
public:
    Warrior();
    Warrior(int actionPoints);
    virtual ~Warrior();
    Warrior(const Warrior &other);
    Warrior &operator=(const Warrior &rhs);

    virtual std::string useCard(DefensiveCard &card);
    virtual std::string useCard(OffensiveCard &card, Entity &enemy);
    virtual void action();
    virtual std::string getClassName() const;
};

#endif // WARRIOR_PGROUPE04_H