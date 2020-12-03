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
    // si le lancé de dé fonctionne, activer la méthode useCard()
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
    // si le lancé de dé fonctionne, activer la méthode useCard()
    if (tryUseCard())
        return Player::useCard(card, enemy);

    // le lancé de dé à échoué
    std::stringstream res;

    res << "Oh non ! la malchance du " << getClassName() << "empêche l'attaque de fonctionner [" << card.getLabel() << "]"
        << std::endl;

    return res.str();
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
            keystream >> cardInitializer;

            int start = 0;
            int fin = cardInitializer.find(delimiter);
            int poolSize = getCardPile(Gambler::pool).size();

            std::string cardPath = cardInitializer.substr(start - 1 + delimiter.length(), cardInitializer.find(delimiter, start - 1 + delimiter.length()));

            //Pour la suite, on aura besoin du delimiter qu'on a defini un peu plus haut afin de bien faire la separation
            int cost = stoi(cardInitializer.substr(fin + delimiter.length(), cardInitializer.find(delimiter, fin + delimiter.length())));

            int value = stoi(cardInitializer.substr(fin + delimiter.length(), cardInitializer.find(delimiter, fin + delimiter.length())));

            // si c'est une carte offensive, créer et ajouter une carte Gambler offensive au pool de cartes du joueur
            if (isOffensive)
            {
                OffensiveCardGambler *gamblerCard = new OffensiveCardGambler(cardName, cardPath, cost, value, sharedContext);

                addCard(gamblerCard, Gambler::pool);

                // On vérifie si la carte y est bien, sinon, supprimer
                if (getCardPile(Gambler::pool).size() != poolSize + 1)
                {
                    delete gamblerCard;
                }
                gamblerCard = nullptr;
            }
            // si c'est une carte défensive, créer et ajouter une carte Gambler défensive au pool de cartes du joueur

            else
            {
                int isHealthRaw = stoi(cardInitializer.substr(fin + delimiter.length(), cardInitializer.find(delimiter, fin + delimiter.length())));
                bool isHealth = (isHealthRaw != 0);
                DefensiveCardGambler *gamblerCard = new DefensiveCardGambler(cardName, cardPath, cost, value, sharedContext, isHealth);

                addCard(gamblerCard, Gambler::pool);

                // On vérifie si la carte y est bien, sinon, supprimer
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