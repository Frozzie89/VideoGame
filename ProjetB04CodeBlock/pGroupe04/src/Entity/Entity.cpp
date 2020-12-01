#include "Entity/Entity.h"
#include <iostream>

//Constructeur
Entity::Entity()
{
    m_turn = false;
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

std::string Entity::getClassName() const
{
    return "Entity";
}

void Entity::AddHealth(Health l_health)
{
    m_entityCaracteristics.AddCharacteristic(&l_health);
}

void Entity::AddShield(Shield l_shield)
{
    m_entityCaracteristics.AddCharacteristic(&l_shield);
}

void Entity::RaiseCharacteristic(int l_index, int l_value)
{
    m_entityCaracteristics.RaiseCharacteristic(l_index, l_value);
}

void Entity::LowerCharacteristic(int l_index, int l_value)
{
    m_entityCaracteristics.LowerCharacteristic(l_index, l_value);
}

void Entity::RaiseCharacteristic(Characteristic &l_characteristic, int l_value)
{
    m_entityCaracteristics.RaiseCharacteristic(l_characteristic, l_value);
}

void Entity::LowerCharacteristic(Characteristic &l_characteristic, int l_value)
{
    m_entityCaracteristics.LowerCharacteristic(l_characteristic, l_value);
}
void Entity::getCharacteristicsValue(){
    std::cout<< m_entityCaracteristics.getCharacteristics()<<std::endl;
}

