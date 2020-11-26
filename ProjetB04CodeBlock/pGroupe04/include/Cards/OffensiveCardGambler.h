#ifndef OFFENSIVECARDGAMBLER_PGROUPE04_H
#define OFFENSIVECARDGAMBLER_PGROUPE04_H
#include <string>
#include "OffensiveCard.h"

class OffensiveCardGambler : public OffensiveCard
{
private:
public:
    OffensiveCardGambler(std::string label = "No_Label", std::string path = "No_path", int costAction = 0, int value = 0);
    virtual ~OffensiveCardGambler();
    OffensiveCardGambler(const OffensiveCardGambler &other);
    OffensiveCardGambler &operator=(const OffensiveCardGambler &rhs);

    void activateEffect(Entity &entity);
    OffensiveCardGambler *clone() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states);
};

#endif // OFFENSIVECARDGAMBLER_PGROUPE04_H
