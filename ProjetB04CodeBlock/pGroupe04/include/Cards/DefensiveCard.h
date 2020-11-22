#ifndef DEFENSIVECARD_PGROUPE04_H
#define DEFENSIVECARD_PGROUPE04_H
#include <string>
#include "Card.h"

class DefensiveCard : public Card
{
private:
    // si false, alors c'est une Card qui donne du shield
    bool isHealth;

public:
    DefensiveCard(std::string label = "No_Label", std::string description = "No_Description", int costAction = 0, int value = 0, bool isHealth = true);
    virtual ~DefensiveCard();
    DefensiveCard(const DefensiveCard &other);
    DefensiveCard &operator=(const DefensiveCard &rhs);

    bool getIsHealth() const;
    void setIsHealth(const bool isHealth);

    virtual void activateEffect() = 0;
    virtual DefensiveCard *clone() const = 0;
};

#endif // DEFENSIVECARD_PGROUPE04_H