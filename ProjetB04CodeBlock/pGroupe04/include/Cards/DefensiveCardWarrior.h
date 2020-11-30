#ifndef DEFENSIVECARDWARRIOR_PGROUPE04_H
#define DEFENSIVECARDWARRIOR_PGROUPE04_H
#include <string>
#include "Cards/DefensiveCard.h"

class DefensiveCardWarrior : public DefensiveCard
{
private:
public:
    DefensiveCardWarrior(std::string label = "No_Label", std::string path = "No_path", int costAction = 0, int value = 0, bool isHealth = true);
    virtual ~DefensiveCardWarrior();
    DefensiveCardWarrior(const DefensiveCardWarrior &other);
    DefensiveCardWarrior &operator=(const DefensiveCardWarrior &rhs);

    DefensiveCardWarrior *clone() const;
    int activateEffect(Entity &entity);
    std::string getClassName() const;
};

#endif // DEFENSIVECARDWARRIOR_PGROUPE04_H
