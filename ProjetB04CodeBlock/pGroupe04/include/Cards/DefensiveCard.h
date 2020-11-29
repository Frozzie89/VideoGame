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
    DefensiveCard(std::string label = "No_Label", std::string path = "No_path", int costAction = 0, int value = 0, bool isHealth = true);
    virtual ~DefensiveCard();
    DefensiveCard(const DefensiveCard &other);
    DefensiveCard &operator=(const DefensiveCard &rhs);

    bool getIsHealth() const;
    void setIsHealth(const bool isHealth);

    std::string str() const;
    virtual int activateEffect();
    virtual DefensiveCard *clone() const = 0;
    virtual std::string getClassName() const;
};

#endif // DEFENSIVECARD_PGROUPE04_H
