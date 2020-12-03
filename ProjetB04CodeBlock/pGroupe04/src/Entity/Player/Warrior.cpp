#include "Entity/Player/Warrior.h"

Warrior::Warrior(int actionPoints) : Player(actionPoints)
{
    std::string buffer;
    std::ifstream warriorOffensiveCards("playerConfigurations/WarriorOffensiveCards.csv");

    vector<string> liste;
    int counter = 0;
    while (getline(warriorOffensiveCards, buffer, ';'))
    {
        liste.push_back(buffer);
        counter++;

        if (counter == 5)
        {
            for (auto &&el : liste)
            {
                cout << el << " ";
            }
            cout << endl;
            liste.clear();
            counter = 0;
        }
    }
}

Warrior::~Warrior() {}

Warrior::Warrior(const Warrior &other) : Player(other) {}

Warrior &Warrior::operator=(const Warrior &rhs)
{
    if (this != &rhs)
    {
        Player::operator=(rhs);
    }

    return *this;
}

std::string Warrior::getClassName() const
{
    return "Warrior";
}

std::string Warrior::useCard(DefensiveCard &card)
{
    return Player::useCard(card);
}

std::string Warrior::useCard(OffensiveCard &card, Entity &enemy)
{
    return Player::useCard(card, enemy);
}

void Warrior::addCard(Card *card, const int cardVector)
{
    if (card->getClassName() == "OffensiveCardWarrior" || card->getClassName() == "DefensiveCardWarrior")
        Player::addCard(card, cardVector);
}