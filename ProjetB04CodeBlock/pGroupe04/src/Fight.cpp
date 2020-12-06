#include <iostream>
#include "Fight.h"

// Constructeur
Fight::Fight()
{
    m_counter = 0;
    createEnemies();
    m_isGameOver = false;
    m_isWon = false;
}

// Constructeur
Fight::Fight(Player *l_player) : m_player(l_player)
{
    m_counter = 0;
    m_player->drawCards();
    m_isGameOver = false;
    m_isWon = false;

    // createEnemies();
}

// Destructeur
Fight::~Fight()
{
    DeleteEnemy();

    //delete m_player;
}

// Constructeur de copie
Fight::Fight(const Fight &other) : m_player(other.m_player), m_counter(other.m_counter) {}

// Operateur d'affectation
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
// Le joueur met fin a son tour.
// On fait attaquer l'enemy
// On fait appel a drawCards qui va supprimer notre main actuelle et en piocher une nouvelle
// On remet nos points d'actions a leur maximum (10)

void Fight::endTurn()
{
    enemyAttack();

    m_player->drawCards();
    m_player->setActionPoints(m_player->getMaxActionPoints());
}

// Le comportement de l'enemy va etre set en fonction de ses points de vie.
// Si il a plus de 50% de ses pv il sera set en HighLife sinon en LowLife
// Puis on fera appel a useAbility
void Fight::enemyAttack()
{
    if (getEnemy().getHealth() > (int)getEnemy().getMaxLife() / 2)
    {
        getEnemy().setStrategy(&bhl);
    }
    else
    {
        getEnemy().setStrategy(&bll);
    }
    getEnemy().useAbility(*m_player);
    if (!checkEntityAlive(m_player))
    {
        gameOver();
    }
}

// utilise une carte
void Fight::useCard(Card &l_selectedCard)
{
    if (l_selectedCard.getClassName().find("DefensiveCard") != std::string::npos)
    {
        m_player->useCard(l_selectedCard);
    }
    else if (l_selectedCard.getClassName().find("OffensiveCard") != std::string::npos)
    {
        m_player->useCard(l_selectedCard, getEnemy());

        // si l'enemi n'est plus en vie, on passe au suivant
        if (!checkEntityAlive(&getEnemy()))
        {
            nextFight();
        }
    }
}

// On incremente le compteur d'enemy (m_counter) de 1
// On remet le deck du joueur a 0
// On fait piocher une nouvelle main au joueur
void Fight::nextFight()
{
    m_counter++;
    if (m_counter == 5)
    {
        SetWon();
        m_player->Restart();
        m_counter = 0;
        DeleteEnemy();
        createEnemies();
        return;
    }
    m_player->setActionPoints(m_player->getMaxActionPoints());
    m_player->initDeck();
    m_player->drawCards();
}

// On verifie si l'entity est en vie (si sa vie est superieure a 0). Si c'est le cas on return true
bool Fight::checkEntityAlive(Entity *l_entity)
{
    Health h;
    Health *entityHealth = (Health *)l_entity->getCharacteristic(h);
    return entityHealth->GetValue() > 0;
}

// retourne l'enemi en cours
Enemy &Fight::getEnemy()
{
    return *m_enemyList[m_counter];
}

// retourne le joueur
Player &Fight::getPlayer()
{
    return *m_player;
}

std::string Fight::getClassName()
{
    return "Fight";
}

// retourne la main du joueur
std::vector<Card *> Fight::getPlayerHand()
{
    return m_player->getCardPile(Player::hand);
}

// indique si c'est le tour du joueur ou non
bool Fight::isPlayerTurn()
{
    return m_player->isTurn();
}

// renvoie les points de vie de l'enemi
int Fight::getRemainingLifeEnemy()
{
    Health h;
    Health *enemyHealth = (Health *)getEnemy().getCharacteristic(h);
    return enemyHealth->GetValue();
}

// renvoie les points de défenses de l'enemi
int Fight::getRemainingShieldEnemy()
{
    Shield s;
    Shield *enemyShield = (Shield *)getEnemy().getCharacteristic(s);
    return enemyShield->GetValue();
}

// Creation de nos enemies avec leurs abilities respective
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
    Enemy *e2 = new Enemy(32, "assets/enemies/wolf.png");
    EnemyAbilityDefensive *ead2_1 = new EnemyAbilityDefensive("Heal_wounds", 6, true);
    EnemyAbilityDefensive *ead2_2 = new EnemyAbilityDefensive("Block", 4, false);
    EnemyAbilityOffensive *eao2_1 = new EnemyAbilityOffensive("Shoot", 7);
    EnemyAbilityOffensive *eao2_2 = new EnemyAbilityOffensive("Throw_pebble", 2);

    e2->addAbilities(ead2_1);
    e2->addAbilities(ead2_2);
    e2->addAbilities(eao2_1);
    e2->addAbilities(eao2_2);

    /**** 3rd enemy ****/
    Enemy *e3 = new Enemy(43, "assets/enemies/pepito.png");
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

void Fight::DeletePlayer()
{
    delete m_player;
}
//Indique qu'on a perdu la partie
void Fight::gameOver()
{
    m_isGameOver = true;
    m_player->Restart();
    m_counter = 0;
    DeleteEnemy();
    createEnemies();
}
//Permet de savoir si on a perdu ou non
bool Fight::isGameOver()
{
    return m_isGameOver;
}
//Permet de savoir si on a gagne ou non
bool Fight::isWon()
{
    return m_isWon;
}
//Permet de supprimer la liste des ennemies
void Fight::DeleteEnemy()
{
    for (auto &&enemy : m_enemyList)
    {
        delete enemy;
    }
    m_enemyList.clear();
}
//Permet de modifier la valeur permettant de savoir si on a gagne
void Fight::SetWon()
{
    m_isWon = !m_isWon;
}
//Permet de modifier la valeur permettant de savoir si on a perdu
void Fight::SetGameOver()
{
    m_isGameOver = !m_isGameOver;
}
