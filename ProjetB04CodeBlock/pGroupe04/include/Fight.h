#ifndef FIGHT_PGROUPE04_H
#define FIGHT_PGROUPE04_H
#include <string>
#include <vector>
#include "Cards/Card.h"
#include "Entity/Player/Player.h"
#include "Entity/Enemy/Enemy.h"
#include "Entity/Entity.h"
#include "Entity/Characteristics/Health.h"

// Cette classe est responsable du fonctionnement des combats entre le joueur et les différents ennemis
class Fight
{
private:
    Player *m_player;
    std::vector<Enemy *> m_enemyList;
    int m_counter;

public:
    Fight();
    Fight(Player *l_player);
    virtual ~Fight();
    Fight(const Fight &other);
    Fight &operator=(const Fight &rhs);
    std::string getClassName();

    std::vector<Card *> getPlayerHand(); // récupère les cartes de la main du joueur
    Enemy &getEnemy();                   // récupère l'ennemi en jeu
    Player &getPlayer();
    void createEnemies(); // crée la liste d'enemis que le joueur va combattre
    void useCard(Card &l_selectedCard);
    void endTurn();                        // termine le tour du joueur, c'est à l'enemi de jouer
    bool checkEntityAlive(Entity *entity); // vérifie si l'entity est toujours en vie
    void nextFight();                      // fin du combat, passage au prochain ennemi
    void gameOver();                       // le joueur est mort, fin du combat
    void enemyAttack();
    bool isPlayerTurn();
    int getRemainingLifeEnemy();
    int getRemainingShieldEnemy();

    void DeletePlayer();
};

#endif // FIGHT_PGROUPE04_H
