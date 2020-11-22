#ifndef OFFENSIVECARDWARRIOR_PGROUPE04_H
#define OFFENSIVECARDWARRIOR_PGROUPE04_H
#include <string>
#include "OffensiveCard.h"

using namespace std;

class OffensiveCardWarrior : public OffensiveCard
{
private:
public:
    OffensiveCardWarrior(string label = "No_Label", string description = "No_Description", int costAction = 0, int value = 0);
    virtual ~OffensiveCardWarrior();
    OffensiveCardWarrior(const OffensiveCardWarrior &other);
    OffensiveCardWarrior &operator=(const OffensiveCardWarrior &rhs);

    virtual void activateEffect(Entity &entity);
    virtual OffensiveCardWarrior *clone() const;
};

#endif // OFFENSIVECARDWARRIOR_PGROUPE04_H