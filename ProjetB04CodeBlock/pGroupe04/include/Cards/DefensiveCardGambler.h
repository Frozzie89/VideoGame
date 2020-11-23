#ifndef DEFENSIVECARDGAMBLER_PGROUPE04_H
#define DEFENSIVECARDGAMBLER_PGROUPE04_H
#include <string>
#include "DefensiveCard.h"

class DefensiveCardGambler : public DefensiveCard
{
private:
public:
    DefensiveCardGambler(std::string label = "No_Label", std::string path = "No_path", int costAction = 0, int value = 0, bool isHealth = true);
    virtual ~DefensiveCardGambler();
    DefensiveCardGambler(const DefensiveCardGambler &other);
    DefensiveCardGambler &operator=(const DefensiveCardGambler &rhs);

    virtual DefensiveCardGambler *clone() const;
    virtual void activateEffect();
};

#endif // DEFENSIVECARDGAMBLER_PGROUPE04_H