#ifndef OFFENSIVECARD_PGROUPE04_H
#define OFFENSIVECARD_PGROUPE04_H
#include <string>
#include "Cards/Card.h"
#include "Entity/Entity.h"

class OffensiveCard : public Card
{
private:
public:
    OffensiveCard(std::string label = "No_Label", std::string path = "No_path", int costAction = 0, int value = 0);
    virtual ~OffensiveCard();
    OffensiveCard(const OffensiveCard &other);
    OffensiveCard &operator=(const OffensiveCard &rhs);

    virtual int activateEffect(Entity &entity); // effet de la carte : diminuer les points de vie de l'enemi
    virtual OffensiveCard *clone() const = 0;
    virtual std::string getClassName() const;
};

#endif // OFFENSIVECARD_PGROUPE04_H
