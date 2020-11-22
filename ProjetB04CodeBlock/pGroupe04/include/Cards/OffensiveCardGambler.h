#ifndef OFFENSIVECARDGAMBLER_PGROUPE04_H
#define OFFENSIVECARDGAMBLER_PGROUPE04_H
#include <string>
#include "OffensiveCard.h"

using namespace std;

class OffensiveCardGambler : public OffensiveCard
{
private:
public:
    OffensiveCardGambler(string label = "No_Label", string description = "No_Description", int costAction = 0, int value = 0);
    virtual ~OffensiveCardGambler();
    OffensiveCardGambler(const OffensiveCardGambler &other);
    OffensiveCardGambler &operator=(const OffensiveCardGambler &rhs);

    virtual void activateEffect(Entity &entity);
    virtual OffensiveCardGambler *clone() const;
};

#endif // OFFENSIVECARDGAMBLER_PGROUPE04_H