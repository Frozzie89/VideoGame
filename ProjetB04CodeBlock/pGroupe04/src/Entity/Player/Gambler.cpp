#include <time.h>
#include <sstream>
#include "Entity/Player/Gambler.h"
#include "Cards/OffensiveCardGambler.h"
#include "Cards/DefensiveCardGambler.h"

Gambler::Gambler(int actionPoints, int health, int shield, int luck) : Player(actionPoints, health, shield), luck(luck)
{
    srand((unsigned)time(0));
    loadCardsAssets(nullptr, true);
    loadCardsAssets(nullptr, false);
}

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

void Gambler::useCard(DefensiveCard &card)
{
    // si le lancé de dé fonctionne, activer la méthode useCard()
    if (tryUseCard())
        Player::useCard(card);
    else
        removeCard(&card, Player::hand);
}

void Gambler::useCard(OffensiveCard &card, Entity &enemy)
{
    // si le lancé de dé fonctionne, activer la méthode useCard()
    if (tryUseCard())
        Player::useCard(card, enemy);
    else
        removeCard(&card, Player::hand);
}

// s'assure que la carte à ajouter est bien une carte pour Gambler
void Gambler::addCard(Card *card, const int cardVector)
{
    if (card->getClassName() == "OffensiveCardGambler" || card->getClassName() == "DefensiveCardGambler")
        Player::addCard(card, cardVector);
}

// Lance un dé 100, renvoie true si le résultat est plus grand que l'attribut "luck"
bool Gambler::tryUseCard() const
{
    return rand() % 100 + 1 > luck;
}

std::string Gambler::getClassName() const
{
    return "Gambler";
}

void Gambler::loadCardsAssets(SharedContext *sharedContext, bool isOffensive)
{
    std::string filecardInitializer;
    if (isOffensive)
        filecardInitializer = "playerConfigurations/GamblerOffensiveCards.csv";
    else
        filecardInitializer = "playerConfigurations/GamblerDefensiveCards.csv";

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
            int poolSize = getCardPile(Gambler::pool).size();

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
                OffensiveCardGambler *gamblerCard = new OffensiveCardGambler(cardName, cardPath, cost, value, sharedContext);

                addCard(gamblerCard, Gambler::pool);

                if (getCardPile(Gambler::pool).size() != poolSize + 1)
                {
                    delete gamblerCard;
                }
                gamblerCard = nullptr;
            }
            else
            {
                int isHealthRaw = stoi(cardInitializer.substr(cardInitializer.size() - 1, cardInitializer.size()));
                bool isHealth = (isHealthRaw != 0);

                DefensiveCardGambler *gamblerCard = new DefensiveCardGambler(cardName, cardPath, cost, value, sharedContext, isHealth);

                addCard(gamblerCard, Gambler::pool);

                if (getCardPile(Gambler::pool).size() != poolSize + 1)
                {
                    delete gamblerCard;
                }
                gamblerCard = nullptr;
            }
        }
    }
    cardAssets.close();
}

std::string Gambler::str()
{
    return to_string(getActionPoints()) + " " + to_string(luck);
}