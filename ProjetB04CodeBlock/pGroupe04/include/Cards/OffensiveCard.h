#ifndef OFFENSIVECARD_PGROUPE04_H
#define OFFENSIVECARD_PGROUPE04_H
#include <string>
#include "Card.h"
#include "../Entity/Entity.h"

class OffensiveCard : public Card
{
private:
public:
    OffensiveCard(std::string label = "No_Label", std::string path = "No_path", int costAction = 0, int value = 0);
    virtual ~OffensiveCard();
    OffensiveCard(const OffensiveCard &other);
    OffensiveCard &operator=(const OffensiveCard &rhs);

    virtual void activateEffect(Entity &entity) = 0;
    virtual OffensiveCard *clone() const = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) =0;
};

#endif // OFFENSIVECARD_PGROUPE04_H
