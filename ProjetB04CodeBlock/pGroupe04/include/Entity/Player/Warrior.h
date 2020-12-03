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

    // utilise une carte de type défensive
    std::string useCard(DefensiveCard &card);
    // utilise une carte de type offensive
    std::string useCard(OffensiveCard &card, Entity &enemy);
    // s'assure que la carte ajoutée est bien une carte the type Warrior
    void addCard(Card *card, const int cardVector);
    // charge les données des cartes situées dans les fichiers de données
    void loadCardsAssets(SharedContext *sharedContext, bool isOffensive);
    std::string getClassName() const;
    std::string str();
};

#endif // WARRIOR_PGROUPE04_H