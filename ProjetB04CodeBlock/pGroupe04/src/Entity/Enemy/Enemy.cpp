#include "Entity/Enemy/Enemy.h"
#include "Entity/Enemy/BehaviourHighLife.h"
#include <iostream>
// Constructeur
Enemy::Enemy() : Entity()
{
    Health healthEnemy;
    Shield shieldEnemy(0);
    Entity::AddHealth(healthEnemy);
    Entity::AddShield(shieldEnemy);
    setMaxLife(healthEnemy.GetValue());
}

// Constructeur
Enemy::Enemy(int l_healthPt, std::string assetPath) : assetPath(assetPath), Entity()
{
    Health m_healthEnemy(l_healthPt);
    Shield shieldEnemy(0);

    Entity::AddHealth(m_healthEnemy);
    Entity::AddShield(shieldEnemy);
    Entity::setSprite(assetPath);
    setMaxLife(l_healthPt);

    // TEMPORAIRE
    BehaviourHighLife *b = new BehaviourHighLife();
    setStrategy(b);
}

// Destructeur
Enemy::~Enemy()
{
    for (auto &&ability : m_abilities)
    {
        delete ability;
    }
    m_abilities.clear();
}

// Constructeur de copie
Enemy::Enemy(const Enemy &other) : Entity(other)
{
    for (auto &&ability : other.m_abilities)
    {
        m_abilities.push_back(ability);
    }
}

// Operateur d'affectation
Enemy &Enemy::operator=(const Enemy &rhs)
{
    if (this != &rhs)
    {
        for (auto &&ability : m_abilities)
        {
            delete ability;
        }
        m_abilities.clear();

        for (auto &&ability : rhs.m_abilities)
        {
            m_abilities.push_back(ability);
        }

        assetPath = rhs.assetPath;
        Entity::operator=(rhs);
    }
    return *this;
}

//GET & SET
void Enemy::setStrategy(Behaviour *l_behaviour)
{
    behaviour = l_behaviour;
}
//Fin GET & SET

// Methodes concernant le vector
// Ajout d'une ability au vector d'abilities
void Enemy::addAbilities(EnemyAbility *l_enemyAbility)
{
    if (SearchAbility(*l_enemyAbility) == -1)
    {
        m_abilities.push_back(l_enemyAbility->clone());
    }
}

// Retirer une ability precise  du vector d'abilities
void Enemy::removeAbilities(EnemyAbility *l_enemyAbility)
{
    int indiceEnemy = SearchAbility(*l_enemyAbility);
    // Si l'ability n'est pas presente dans le vector, on stoppe la methode
    if (indiceEnemy == -1)
        return;

    EnemyAbility *tmp = *(m_abilities.begin() + indiceEnemy);
    m_abilities.erase(m_abilities.begin() + indiceEnemy);
    delete tmp;
}

//Permet de retrouver une ability dans notre liste grace a un argument de type EnemyAbility
int Enemy::SearchAbility(EnemyAbility &l_enemyAbility)
{
    for (int i = 0; i < (int)m_abilities.size(); i++)
    {
        if (m_abilities[i]->getName() == l_enemyAbility.getName())
            return i;
    }
    return -1;
}
// Fin vector

// Strategy : Permet de definir le comportement de l'enemy en fonction de ses points de vie restant
void Enemy::useAbility(Entity &entity)
{
    behaviour->useAbility(entity, *this, m_abilities);
}

std::vector<EnemyAbility *> Enemy::getAbilitiesList()
{
    return m_abilities;
}

//Retourne le nom de la classe
std::string Enemy::getClassName() const
{
    return "Enemy";
}
//Retourne les caracteristiques d'ennemies
std::string Enemy::str() const
{
    return getClassName() + " : Path : " + assetPath + " || ";
}
//Retourne le chemin d'accès defini ici
string Enemy::GetPath() const
{
    return assetPath;
}
