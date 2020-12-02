#ifndef DEFENSIVECARDGAMBLER_PGROUPE04_H
#define DEFENSIVECARDGAMBLER_PGROUPE04_H
#include <string>
#include "Cards/DefensiveCard.h"

// cette classe n'existe que pour empêcher le Gambler d'utiliser d'autre cartes que les siennes
class DefensiveCardGambler : public DefensiveCard
{
private:
public:
    DefensiveCardGambler(std::string label = "No_Label", std::string path = "No_path", int costAction = 0, int value = 0,SharedContext* m_context = nullptr, bool isHealth = true);
    virtual ~DefensiveCardGambler();
    DefensiveCardGambler(const DefensiveCardGambler &other);
    DefensiveCardGambler &operator=(const DefensiveCardGambler &rhs);

    DefensiveCardGambler *clone() const;
    int activateEffect(Entity &entity);
    std::string getClassName() const;

};

#endif // DEFENSIVECARDGAMBLER_PGROUPE04_H
