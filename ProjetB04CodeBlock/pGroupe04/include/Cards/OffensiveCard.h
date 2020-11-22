#ifndef OFFENSIVECARD_PGROUPE04_H
#define OFFENSIVECARD_PGROUPE04_H
#include <string>
#include "Card.h"
#include "../Entity/Entity.h"

using namespace std;

class OffensiveCard : public Card
{
private:
public:
    OffensiveCard(string label = "No_Label", string description = "No_Description", int costAction = 0, int value = 0);
    virtual ~OffensiveCard();
    OffensiveCard(const OffensiveCard &other);
    OffensiveCard &operator=(const OffensiveCard &rhs);

    virtual void activateEffect(Entity &entity) = 0;
    virtual OffensiveCard *clone() const = 0;
};

#endif // OFFENSIVECARD_PGROUPE04_H