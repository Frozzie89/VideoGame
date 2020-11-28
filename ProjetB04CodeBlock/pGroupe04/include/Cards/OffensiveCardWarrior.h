#ifndef OFFENSIVECARDWARRIOR_PGROUPE04_H
#define OFFENSIVECARDWARRIOR_PGROUPE04_H
#include <string>
#include "OffensiveCard.h"

class OffensiveCardWarrior : public OffensiveCard
{
private:
public:
    OffensiveCardWarrior(std::string label = "No_Label", std::string path = "No_path", int costAction = 0, int value = 0);
    virtual ~OffensiveCardWarrior();
    OffensiveCardWarrior(const OffensiveCardWarrior &other);
    OffensiveCardWarrior &operator=(const OffensiveCardWarrior &rhs);

    void activateEffect(Entity &entity);
    OffensiveCardWarrior *clone() const;
};

#endif // OFFENSIVECARDWARRIOR_PGROUPE04_H
