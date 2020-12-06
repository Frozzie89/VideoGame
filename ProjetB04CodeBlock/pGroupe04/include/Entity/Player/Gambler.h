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
    Gambler(int actionPoints = 10, int health = 20, int shield = 0, int luck = 50);
    virtual ~Gambler();
    Gambler(const Gambler &other);
    Gambler &operator=(const Gambler &rhs);

    void useCard(Card &card);                // Utilise une carte de type défensive
    void useCard(Card &card, Entity &enemy); // Utilise une carte de type offensive
    // S'assure que la carte ajoutée est bien de type Gambler
    void addCard(Card *card, const int cardVector);
    // lance un dé 100 pour savoir si le joueur pourra utiliser sa carte ou non
    bool tryUseCard() const;
    // récupère les cartes depuis les fichiers de données
    void loadCardsAssets(SharedContext *sharedContext, bool isOffensive);
    std::string getClassName() const;
    std::string str();
};

#endif // GAMBLER_PGROUPE04_H
