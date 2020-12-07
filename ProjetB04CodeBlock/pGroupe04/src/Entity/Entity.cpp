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
//Modifie le nombre de points de vie max
void Entity::setMaxLife(int maxLife)
{
    this->maxLife = maxLife;
}
//Retourne le nom de la classe
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

// ces 4 prochaines méthodes utilisent les méthodes de Charateristic pour augmenter et diminuer
// la valeur d'une caratéristique de l'entité
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
//retourne une caracteristique
Characteristic *Entity::getCharacteristic(Characteristic &c)
{
    return m_entityCaracteristics.getCharacteristic(c);
}

//Permet de recuperer la position de l'entite
sf::Vector2f Entity::getPosition()
{
    return m_position;
}
//Permet de modifier la position de l'entite par un vecteur compose de deux float
void Entity::setPosition(sf::Vector2f l_position)
{
    m_sprite.setPosition(l_position);
}
//Permet de modifier la position de l'entite par de deux float
void Entity::setPosition(float l_width, float l_height)
{
    m_position.x = l_width;
    m_position.y = l_height;
    m_sprite.setPosition(m_position);
}
//retourne le nombre de points de vie maximal
int Entity::getMaxLife()
{
    return maxLife;
}
//Permet de modifier le sprite de l'entite
void Entity::setSprite(const std::string l_path)
{
    m_path = l_path;
    m_texture.loadFromFile(m_path);
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.2, 0.2);
}
//Permet de dessiner le sprite de l'entite
void Entity::Draw()
{
    sf::RenderWindow *window = m_context->m_wind->GetRenderWindow();
    window->draw(m_sprite);
}
//Permet de modifier le contexte de l'entite
void Entity::setContext(SharedContext *l_context)
{
    m_context = l_context;
}
//Permet de modifier l'echelle du sprite de l'entite
void Entity::setSpriteScale(float l_x, float l_y)
{
    m_sprite.setScale(l_x, l_y);
}
//Retourne le nombre de points de vie de l'entite
int Entity::getHealth()
{
    return m_entityCaracteristics.getCharacteristic("Health")->GetValue();
}
//Retourne le nombre de points d'armure de l'entite
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
