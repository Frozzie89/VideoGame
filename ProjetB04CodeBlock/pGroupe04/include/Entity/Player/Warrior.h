#ifndef WARRIOR_PGROUPE04_H
#define WARRIOR_PGROUPE04_H
#include <string>
#include "Entity/Player/Player.h"

// Classe jouable Warrior, ses cartes sont basiques
class Warrior : public Player
{
private:
public:
    Warrior(int actionPoints = 10);
    virtual ~Warrior();
    Warrior(const Warrior &other);
    Warrior &operator=(const Warrior &rhs);

    std::string useCard(DefensiveCard &card);
    std::string useCard(OffensiveCard &card, Entity &enemy);
    void addCard(Card *card, const int cardVector);
    void loadCardsAssets(SharedContext *sharedContext, bool isOffensive);
    std::string getClassName() const;
    std::string str();
};

#endif // WARRIOR_PGROUPE04_H