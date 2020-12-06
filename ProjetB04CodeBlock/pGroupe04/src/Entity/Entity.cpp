#include "Entity/Entity.h"
#include <iostream>

//Constructeur
Entity::Entity(std::string l_path) : m_path(l_path)
{
    m_turn = true;
}
//Destructeur
Entity::~Entity()
{
}
//Constructeur de copie
Entity::Entity(const Entity &other)
{
    m_turn = other.m_turn;
}
//operateur d'affectation
Entity &Entity::operator=(const Entity &rhs)
{
    if (this != &rhs)
    {
        m_turn = rhs.m_turn;
    }
    return *this;
}
//Permet de savoir si c'est le tour de l'entite
bool Entity::isTurn() const
{
    return m_turn;
}
//Permet de switcher la valeur de m_turn
void Entity::setTurn()
{
    m_turn = !m_turn;
}

void Entity::setMaxLife(int maxLife)
{
    this->maxLife = maxLife;
}

std::string Entity::getClassName() const
{
    return "Entity";
}

// ajoute une caractéristique Health à l'entité
void Entity::AddHealth(Health l_health)
{
    m_entityCaracteristics.AddCharacteristic(&l_health);
}

// ajoute une caractéristique Shield à l'entité
void Entity::AddShield(Shield l_shield)
{
    m_entityCaracteristics.AddCharacteristic(&l_shield);
}

// Augmente une Characteristic, par index
void Entity::RaiseCharacteristic(int l_index, int l_value)
{
    m_entityCaracteristics.RaiseCharacteristic(l_index, l_value);
}

// Diminue une Characteristic, par index
void Entity::LowerCharacteristic(int l_index, int l_value)
{
    m_entityCaracteristics.LowerCharacteristic(l_index, l_value);
}

// Renvoie une Characteristic, par Characteristic
void Entity::RaiseCharacteristic(Characteristic &l_characteristic, int l_value)
{
    m_entityCaracteristics.RaiseCharacteristic(l_characteristic, l_value);
}

// Diminue une Characteristic, par Characteristic
void Entity::LowerCharacteristic(Characteristic &l_characteristic, int l_value)
{
    m_entityCaracteristics.LowerCharacteristic(l_characteristic, l_value);
}

// Renvoie une Characteristic
Characteristic *Entity::getCharacteristic(Characteristic &c)
{
    return m_entityCaracteristics.getCharacteristic(c);
}

// SFML
sf::Vector2f Entity::getPosition()
{
    return m_position;
}

void Entity::setPosition(sf::Vector2f l_position)
{
    m_sprite.setPosition(l_position);
}

void Entity::setPosition(float l_width, float l_height)
{
    m_position.x = l_width;
    m_position.y = l_height;
    m_sprite.setPosition(m_position);
}

// renvoie le max de vie que l'Entity peut avoir
int Entity::getMaxLife()
{
    return maxLife;
}

void Entity::endTurn()
{
}

void Entity::setSprite(const std::string l_path)
{
    m_path = l_path;
    m_texture.loadFromFile(m_path);
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.2, 0.2);
}

void Entity::Draw()
{
    sf::RenderWindow *window = m_context->m_wind->GetRenderWindow();
    window->draw(m_sprite);
}

void Entity::setContext(SharedContext *l_context)
{
    m_context = l_context;
}

void Entity::setSpriteScale(float l_x, float l_y)
{
    m_sprite.setScale(l_x, l_y);
}

// renvoie la characteristic Health de l'Entity
int Entity::getHealth()
{
    return m_entityCaracteristics.getCharacteristic("Health")->GetValue();
}

// renvoie la characteristic Shield de l'Entity
int Entity::getShield()
{
    return m_entityCaracteristics.getCharacteristic("Shield")->GetValue();
}
//Remet a zero les donnees du player
void Entity::Restart()
{
    m_entityCaracteristics.getCharacteristic("Health")->SetValue(20);
    m_entityCaracteristics.getCharacteristic("Shield")->SetValue(0);
}
