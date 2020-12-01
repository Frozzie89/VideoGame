#ifndef WARRIOR_PGROUPE04_H
#define WARRIOR_PGROUPE04_H
#include <string>
#include "Player.h"

// Classe jouable Warrior, ses cartes sont basiques
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
    std::string getClassName() const;
};

#endif // WARRIOR_PGROUPE04_H