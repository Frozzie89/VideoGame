#ifndef DEFENSIVECARDGAMBLER_PGROUPE04_H
#define DEFENSIVECARDGAMBLER_PGROUPE04_H
#include <string>
#include "DefensiveCard.h"

using namespace std;

class DefensiveCardGambler : public DefensiveCard
{
private:
public:
    DefensiveCardGambler(string label = "No_Label", string description = "No_Description", int costAction = 0, int value = 0, bool isHealth = true);
    virtual ~DefensiveCardGambler();
    DefensiveCardGambler(const DefensiveCardGambler &other);
    DefensiveCardGambler &operator=(const DefensiveCardGambler &rhs);

    virtual DefensiveCardGambler *clone() const;
    virtual void activateEffect();
};

#endif // DEFENSIVECARDGAMBLER_PGROUPE04_H