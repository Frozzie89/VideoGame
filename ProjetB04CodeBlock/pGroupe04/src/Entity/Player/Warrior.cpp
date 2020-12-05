#include "Entity/Player/Warrior.h"
#include "Cards/OffensiveCardWarrior.h"
#include "Cards/DefensiveCardWarrior.h"
#include <iostream>

Warrior::Warrior(int actionPoints, int health, int shield) : Player(actionPoints, health, shield)
{
    loadCardsAssets(nullptr, true);
    loadCardsAssets(nullptr, false);
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

void Warrior::useCard(DefensiveCard &card)
{
    Player::useCard(card);
}

void Warrior::useCard(OffensiveCard &card, Entity &enemy)
{
    Player::useCard(card, enemy);
}

void Warrior::loadCardsAssets(SharedContext *sharedContext, bool isOffensive)
{
    std::string filecardInitializer;
    if (isOffensive)
        filecardInitializer = "playerConfigurations/WarriorOffensiveCards.csv";
    else
        filecardInitializer = "playerConfigurations/WarriorDefensiveCards.csv";

    std::string delimiter = ";";
    std::string delimiter2 = ":";

    std::ifstream cardAssets;
    cardAssets.open(filecardInitializer);
    //On tente d'ouvrir le fichier, si on n'y arrive pas, on ecrit en console
    if (!cardAssets.is_open())
    {
        std::cout << "!Failed loading " << filecardInitializer << std::endl;
        return;
    }
    std::string line;
    //Va servir a lire l'entierete des ligne du fichier
    while (std::getline(cardAssets, line))
    {
        std::stringstream keystream(line); // -> Permet de morceler le string recu
        std::string cardName;
        keystream >> cardName; //Permet de recuperer le nom du callback -> Coupe les chaines de caracteres en utilisant les espaces comme delimiteurs par defaut

        //on va s'assurer qu'on va lire l'ensemble de la ligne
        while (!keystream.eof())
        {
            std::string cardInitializer;
            keystream >> cardInitializer; //On recupere la dernier chaine de caractere correspondant a notre type d'event et son code

            int start = 0;
            int fin = cardInitializer.find(delimiter);
            int fin2 = cardInitializer.find(delimiter2);
            int poolSize = getCardPile(Warrior::pool).size();

            std::string cardPath = cardInitializer.substr(start - 1 + delimiter.length(), cardInitializer.find(delimiter, start - 1 + delimiter.length()));

            std::string costString = cardInitializer.substr(fin + delimiter.length(), cardInitializer.find(delimiter, fin + delimiter.length()));

            int cost = stoi(costString);

            std::string valueString = cardInitializer.substr(cardPath.size() + delimiter.length(), cardPath.size());
            valueString = valueString.substr(valueString.find(delimiter) + 1);

            if (valueString.find(delimiter2) != std::string::npos)
            {
                valueString.erase(valueString.end() - 2, valueString.end());
            }

            int value = stoi(valueString);

            if (isOffensive)
            {

                OffensiveCardWarrior *warriorCard = new OffensiveCardWarrior(cardName, cardPath, cost, value, sharedContext);

                addCard(warriorCard, Warrior::pool);

                if (getCardPile(Warrior::pool).size() != poolSize + 1)
                {
                    delete warriorCard;
                }
                warriorCard = nullptr;
            }
            else
            {
                int isHealthRaw = stoi(cardInitializer.substr(cardInitializer.size() - 1, cardInitializer.size()));
                bool isHealth = (isHealthRaw != 0);
                DefensiveCardWarrior *warriorCard = new DefensiveCardWarrior(cardName, cardPath, cost, value, sharedContext, isHealth);

                addCard(warriorCard, Warrior::pool);

                if (getCardPile(Warrior::pool).size() != poolSize + 1)
                {
                    delete warriorCard;
                }
                warriorCard = nullptr;
            }
        }
    }
    cardAssets.close();
}

void Warrior::addCard(Card *card, const int cardVector)
{
    if (card->getClassName() == "OffensiveCardWarrior" || card->getClassName() == "DefensiveCardWarrior")
        Player::addCard(card, cardVector);
}

std::string Warrior::str()
{
    return to_string(getActionPoints());
}