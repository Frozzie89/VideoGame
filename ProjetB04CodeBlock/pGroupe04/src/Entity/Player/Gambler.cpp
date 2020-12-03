#include <time.h>
#include <sstream>
#include "Entity/Player/Gambler.h"
#include "Cards/OffensiveCardGambler.h"
#include "Cards/DefensiveCardGambler.h"

Gambler::Gambler(int actionPoints, int luck) : Player(actionPoints), luck(luck)
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

void Gambler::loadCardsAssets(SharedContext *sharedContext, bool isOffensive)
{
    std::string filecardInitializer;
    if (isOffensive)
        filecardInitializer = "playerConfigurations/GamblerOffensiveCards.csv";
    else
        filecardInitializer = "playerConfigurations/GamblerDefensiveCards.csv";

    std::string delimiter = ";";

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
            int poolSize = getCardPile(Gambler::pool).size();

            std::string cardPath = cardInitializer.substr(start - 1 + delimiter.length(), cardInitializer.find(delimiter, start - 1 + delimiter.length()));

            //Pour la suite, on aura besoin du delimiter qu'on a defini un peu plus haut afin de bien faire la separation
            int cost = stoi(cardInitializer.substr(fin + delimiter.length(), cardInitializer.find(delimiter, fin + delimiter.length())));

            int value = stoi(cardInitializer.substr(fin + delimiter.length(), cardInitializer.find(delimiter, fin + delimiter.length())));

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
                int isHealthRaw = stoi(cardInitializer.substr(fin + delimiter.length(), cardInitializer.find(delimiter, fin + delimiter.length())));
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