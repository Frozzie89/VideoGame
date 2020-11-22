#ifndef DEFENSIVECARDWARRIOR_PGROUPE04_H
#define DEFENSIVECARDWARRIOR_PGROUPE04_H
#include <string>
#include "DefensiveCard.h"

class DefensiveCardWarrior : public DefensiveCard
{
private:
public:
    DefensiveCardWarrior(std::string label = "No_Label", std::string description = "No_Description", int costAction = 0, int value = 0, bool isHealth = true);
    virtual ~DefensiveCardWarrior();
    DefensiveCardWarrior(const DefensiveCardWarrior &other);
    DefensiveCardWarrior &operator=(const DefensiveCardWarrior &rhs);

    virtual DefensiveCardWarrior *clone() const;
    virtual void activateEffect();
};

#endif // DEFENSIVECARDWARRIOR_PGROUPE04_H