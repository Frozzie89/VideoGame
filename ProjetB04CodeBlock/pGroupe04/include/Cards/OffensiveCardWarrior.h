#ifndef OFFENSIVECARDWARRIOR_PGROUPE04_H
#define OFFENSIVECARDWARRIOR_PGROUPE04_H

#include <string>
#include "Cards/OffensiveCard.h"

// cette classe n'existe que pour empêcher le Warrior d'utiliser d'autre cartes que les siennes
class OffensiveCardWarrior : public OffensiveCard
{
private:
public:
    OffensiveCardWarrior(std::string label = "No_Label", std::string path = "No_path", int costAction = 0, int value = 0, SharedContext *m_context = nullptr);
    virtual ~OffensiveCardWarrior();
    OffensiveCardWarrior(const OffensiveCardWarrior &other);
    OffensiveCardWarrior &operator=(const OffensiveCardWarrior &rhs);

    int activateEffect(Entity &entity); // active l'effet de la carte
    OffensiveCardWarrior *clone() const;
    std::string getClassName() const;
};

#endif // OFFENSIVECARDWARRIOR_PGROUPE04_H
