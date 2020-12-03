#ifndef GAMBLER_PGROUPE04_H
#define GAMBLER_PGROUPE04_H
#include <string>
#include "Entity/Player/Player.h"

// Classe jouable Gambler, ses cartes ont un effet plus puissant mais à une chance d'échouer
class Gambler : public Player
{
private:
    int luck;

public:
    Gambler();
    Gambler(int actionPoints = 10, int luck = 50);
    virtual ~Gambler();
    Gambler(const Gambler &other);
    Gambler &operator=(const Gambler &rhs);

    std::string useCard(DefensiveCard &card);
    std::string useCard(OffensiveCard &card, Entity &enemy);
    void addCard(Card *card, const int cardVector);
    bool tryUseCard() const;
    std::string getClassName() const;
};

#endif // GAMBLER_PGROUPE04_H