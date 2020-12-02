#ifndef WARRIOR_PGROUPE04_H
#define WARRIOR_PGROUPE04_H
#include <string>
#include "Entity/Player/Player.h"

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

    std::string useCard(DefensiveCard &card);
    std::string useCard(OffensiveCard &card, Entity &enemy);
    void addCard(Card *card, const int cardVector);
    std::string getClassName() const;
};

#endif // WARRIOR_PGROUPE04_H