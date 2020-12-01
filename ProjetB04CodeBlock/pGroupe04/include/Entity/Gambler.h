#ifndef GAMBLER_PGROUPE04_H
#define GAMBLER_PGROUPE04_H
#include <string>
#include "Player.h"

// Classe jouable Gambler, ses cartes ont un effet plus puissant mais à une chance d'échouer
class Gambler : public Player
{
private:
    int luck;

public:
    Gambler();
    Gambler(int actionPoints, int luck = 50);
    virtual ~Gambler();
    Gambler(const Gambler &other);
    Gambler &operator=(const Gambler &rhs);

    virtual std::string useCard(DefensiveCard &card);
    virtual std::string useCard(OffensiveCard &card, Entity &enemy);
    bool tryUseCard() const;
    std::string getClassName() const;
};

#endif // GAMBLER_PGROUPE04_H