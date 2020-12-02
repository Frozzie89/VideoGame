#include "Fight.h"

Fight::Fight()
{
    m_counter = 0;
}

Fight::Fight(Player l_player) : m_player(l_player)
{
    m_counter = 0;
}

Fight::~Fight()
{
    delete m_enemy;
}

Fight::Fight(const Fight &other) : m_player(other.m_player), m_counter(other.m_counter) {}

Fight &Fight::operator=(const Fight &rhs)
{
    if (this != &rhs)
    {
        m_counter = rhs.m_counter;
        m_player = rhs.m_player;

        delete m_enemy;
        m_enemy = rhs.m_enemy;
    }

    return *this;
}

std::string Fight::getClassName()
{
    return "Fight";
}

std::vector<Card *> Fight::getPlayerHand()
{
    return m_player.getCardPile(Player::hand);
}

Enemy Fight::getEnemy()
{
    return *m_enemy;
}

Player Fight::getPlayer()
{
    return m_player;
}

void Fight::setEnemy()
{
    delete m_enemy;

    std::string tmp = "enemy" + std::to_string(m_counter) + ".jpeg";
}

void Fight::setEnemy(Enemy l_enemy)
{
}