#ifndef DEFENSIVECARDWARRIOR_PGROUPE04_H
#define DEFENSIVECARDWARRIOR_PGROUPE04_H
#include <string>
#include "DefensiveCard.h"

using namespace std;

class DefensiveCardWarrior : public DefensiveCard
{
private:
public:
    DefensiveCardWarrior(string label = "No_Label", string description = "No_Description", int costAction = 0, int value = 0, bool isHealth = true);
    virtual ~DefensiveCardWarrior();
    DefensiveCardWarrior(const DefensiveCardWarrior &other);
    DefensiveCardWarrior &operator=(const DefensiveCardWarrior &rhs);

    virtual DefensiveCardWarrior *clone() const;
    virtual void activateEffect();
};

#endif // DEFENSIVECARDWARRIOR_PGROUPE04_H