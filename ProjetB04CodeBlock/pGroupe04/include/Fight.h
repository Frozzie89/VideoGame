#ifndef FIGHT_PGROUPE04_H
#define FIGHT_PGROUPE04_H
#include <string>
#include <vector>
#include "Cards/Card.h"
#include "Entity/Player/Player.h"
#include "Entity/Enemy/Enemy.h"

class Fight
{
private:
    Player m_player;
    Enemy *m_enemy;
    int m_counter;

public:
    Fight();
    Fight(Player l_player);
    virtual ~Fight();
    Fight(const Fight &other);
    Fight &operator=(const Fight &rhs);
    std::string getClassName();

    std::vector<Card *> getPlayerHand();
    Enemy getEnemy();
    Player getPlayer();
    void setEnemy();
    void setEnemy(Enemy l_enemy);
};

#endif // FIGHT_PGROUPE04_H