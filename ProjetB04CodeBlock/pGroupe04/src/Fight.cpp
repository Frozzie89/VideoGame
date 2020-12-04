#include <iostream>
#include "Fight.h"

Fight::Fight()
{
    m_counter = 0;
}

Fight::Fight(Player *l_player) : m_player(l_player)
{
    m_counter = 0;
    m_player->drawCards();
    createEnemies();
}

Fight::~Fight()
{
    for (auto &&enemy : m_enemyList)
    {
        delete enemy;
    }
    m_enemyList.clear();

    delete m_player;
}

Fight::Fight(const Fight &other) : m_player(other.m_player), m_counter(other.m_counter) {}

Fight &Fight::operator=(const Fight &rhs)
{
    if (this != &rhs)
    {
        m_counter = rhs.m_counter;
        m_player = rhs.m_player;

        for (auto &&enemy : m_enemyList)
        {
            delete enemy;
        }
        m_enemyList.clear();

        for (auto &&enemy : rhs.m_enemyList)
        {
            m_enemyList.push_back(enemy);
        }
    }

    return *this;
}

std::string Fight::getClassName()
{
    return "Fight";
}

std::vector<Card *> Fight::getPlayerHand()
{
    return m_player->getCardPile(Player::hand);
}

Enemy &Fight::getEnemy()
{
    return *m_enemyList[m_counter];
}

Player &Fight::getPlayer()
{
    return *m_player;
}

void Fight::endTurn()
{
    getEnemy().useAbility(*m_player);
    if (checkEntityAlive(m_player))
        gameOver();

    m_player->drawCards();
}

void Fight::useCard(Card &l_selectedCard)
{
    if (l_selectedCard.getClassName().find("DefensiveCard") != std::string::npos)
        m_player->useCard(l_selectedCard);

    else
    {
        m_player->useCard(l_selectedCard, getEnemy());
        if (checkEntityAlive(&getEnemy()))
            nextFight();
    }
}

bool Fight::checkEntityAlive(Entity *l_entity)
{
    Health h;
    Health *entityHealth = (Health *)l_entity->getCharacteristic(h);
    return entityHealth->GetValue() > 0;
}

void Fight::nextFight()
{
    m_counter++;
    m_player->purgeCardPile(Player::hand);
    m_player->initDeck();
    m_player->drawCards();
}

void Fight::gameOver()
{
    std::cout << "EndFight" << std::endl;
}

void Fight::createEnemies()
{
    /**** 1st enemy ****/
    Enemy *e1 = new Enemy(25, "assets/enemies/fox.png");
    EnemyAbilityDefensive *ead1_1 = new EnemyAbilityDefensive("Sleep", 5, true);
    EnemyAbilityDefensive *ead1_2 = new EnemyAbilityDefensive("Hide", 3, false);
    EnemyAbilityOffensive *eao1_1 = new EnemyAbilityOffensive("Bite", 5);
    EnemyAbilityOffensive *eao1_2 = new EnemyAbilityOffensive("Scratch", 3);

    e1->addAbilities(ead1_1);
    e1->addAbilities(ead1_2);
    e1->addAbilities(eao1_1);
    e1->addAbilities(eao1_2);

    /**** 2nd enemy ****/
    Enemy *e2 = new Enemy(32, "assets/enemies/hunter.png");
    EnemyAbilityDefensive *ead2_1 = new EnemyAbilityDefensive("Heal_wounds", 6, true);
    EnemyAbilityDefensive *ead2_2 = new EnemyAbilityDefensive("Block", 4, false);
    EnemyAbilityOffensive *eao2_1 = new EnemyAbilityOffensive("Shoot", 7);
    EnemyAbilityOffensive *eao2_2 = new EnemyAbilityOffensive("Throw_pebble", 2);

    e2->addAbilities(ead2_1);
    e2->addAbilities(ead2_2);
    e2->addAbilities(eao2_1);
    e2->addAbilities(eao2_2);

    /**** 3rd enemy ****/
    Enemy *e3 = new Enemy(43, "assets/enemies/wolf.png");
    EnemyAbilityDefensive *ead3_1 = new EnemyAbilityDefensive("Eat", 2, true);
    EnemyAbilityDefensive *ead3_2 = new EnemyAbilityDefensive("Howl", 4, false);
    EnemyAbilityOffensive *eao3_1 = new EnemyAbilityOffensive("Bite", 6);
    EnemyAbilityOffensive *eao3_2 = new EnemyAbilityOffensive("Scratch", 3);

    e3->addAbilities(ead3_1);
    e3->addAbilities(ead3_1);
    e3->addAbilities(ead3_1);
    e3->addAbilities(ead3_2);
    e3->addAbilities(eao3_1);
    e3->addAbilities(eao3_2);

    /**** 4th enemy ****/
    Enemy *e4 = new Enemy(50, "assets/enemies/pepito.png");
    EnemyAbilityDefensive *ead4_1 = new EnemyAbilityDefensive("Tequila", 5, true);
    EnemyAbilityDefensive *ead4_2 = new EnemyAbilityDefensive("Fly off", 3, false);
    EnemyAbilityOffensive *eao4_1 = new EnemyAbilityOffensive("Shoot rainbow", 8);
    EnemyAbilityOffensive *eao4_2 = new EnemyAbilityOffensive("Tacos attack", 3);

    e4->addAbilities(ead4_1);
    e4->addAbilities(ead4_2);
    e4->addAbilities(eao4_2);
    e4->addAbilities(eao4_1);
    e4->addAbilities(eao4_2);
    e4->addAbilities(eao4_2);

    /**** 5th enemy ****/
    Enemy *e5 = new Enemy(50, "assets/enemies/ghostCat.png");
    EnemyAbilityDefensive *ead5_1 = new EnemyAbilityDefensive("Disappear", 3, false);
    EnemyAbilityDefensive *ead5_2 = new EnemyAbilityDefensive("Blush", 3, false);
    EnemyAbilityOffensive *eao5_1 = new EnemyAbilityOffensive("OOOoooOOOooooOoohh", 9);
    EnemyAbilityOffensive *eao5_2 = new EnemyAbilityOffensive("Mweow", 4);

    e5->addAbilities(ead5_1);
    e5->addAbilities(ead5_2);
    e5->addAbilities(ead5_2);
    e5->addAbilities(eao5_1);
    e5->addAbilities(eao5_1);
    e5->addAbilities(eao5_2);
    e5->addAbilities(eao5_2);
    e5->addAbilities(eao5_2);

    m_enemyList.push_back(e1);
    m_enemyList.push_back(e2);
    m_enemyList.push_back(e3);
    m_enemyList.push_back(e4);
    m_enemyList.push_back(e5);
}


