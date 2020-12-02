#include <time.h>
#include <sstream>
#include "Entity/Player/Gambler.h"

Gambler::Gambler() { srand((unsigned)time(0)); }

Gambler::Gambler(int actionPoints, int luck) : Player(actionPoints), luck(luck) {}

Gambler::~Gambler() {}

Gambler::Gambler(const Gambler &other) : Player(other), luck(other.luck) {}

Gambler &Gambler::operator=(const Gambler &rhs)
{
    if (this != &rhs)
    {
        luck = rhs.luck;
        Player::operator=(rhs);
    }

    return *this;
}

std::string Gambler::useCard(DefensiveCard &card)
{
    if (tryUseCard())
        return Player::useCard(card);

    // le lancé de dé à échoué
    std::stringstream res;

    res << "Oh non ! la malchance du " << getClassName() << "empêche "
        << (card.getIsHealth() ? "le soin " : "l'augmentation d'armure ") << "de fonctionner [" << card.getLabel() << "]"
        << std::endl;

    return res.str();
}

std::string Gambler::useCard(OffensiveCard &card, Entity &enemy)
{
    if (tryUseCard())
        return Player::useCard(card, enemy);

    // le lancé de dé à échoué
    std::stringstream res;

    res << "Oh non ! la malchance du " << getClassName() << "empêche l'attaque de fonctionner [" << card.getLabel() << "]"
        << std::endl;

    return res.str();
}

void Gambler::addCard(Card *card, const int cardVector)
{
    if (card->getClassName() == "OffensiveCardGambler" || card->getClassName() == "DefensiveCardGambler")
        Player::addCard(card, cardVector);
}

bool Gambler::tryUseCard() const
{
    return rand() % 100 + 1 > luck;
}

std::string Gambler::getClassName() const
{
    return "Gambler";
}
