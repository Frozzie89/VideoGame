#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Entity/Characteristics/Characteristics.h"
#include "Entity/Characteristics/Health.h"
#include "Entity/Characteristics/Shield.h"

#include "SharedContext.h"
struct SharedContext;
// Une Entity represente une entite pouvant combattre dans un combat de carte, donc le joueur et l'enemi
class Entity
{
private:
    Characteristics m_entityCaracteristics; // Liste de caracteristiques de l'entite
    bool m_turn;                            // Permet de savoir s'il s'agit du tour de l'entite
    int maxLife;
    std::string m_path;

protected:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;
    SharedContext *m_context;

public:
    Entity(std::string l_path = "noPath");
    virtual ~Entity() = 0;
    Entity(const Entity &other);
    Entity &operator=(const Entity &rhs);

    // Methode a redefinir dans les sous-classes

    // Methodes generals
    // Get/Setter
    bool isTurn() const; // Permet de savoir s'il s'agit du tour de l'entite
    void setTurn();      // Permet de switcher la valeur de m_turn;
    virtual std::string getClassName() const; //Retourne le nom de la classe
    int getMaxLife(); //retourne le nombre de points de vie maximal

    int getHealth(); //Renvoie le nombre de points de vie
    int getShield(); //Renvoie le nombre de points d'armure

    void AddHealth(Health l_health);                                         // Permet d'ajouter de la vie aux caracteristiques de l'entite
    void AddShield(Shield l_shield);                                         // Permet d'ajouter de l'armure aux caracteristiques de l'entite
    void RaiseCharacteristic(Characteristic &l_characteristic, int l_value); // Fait appel a la methode de Characteristics
    void LowerCharacteristic(Characteristic &l_characteristic, int l_value); // Fait appel a la methode de Characteristics
    void setMaxLife(int maxLife); //Modifie le nombre de points de vie max
    Characteristic *getCharacteristic(Characteristic &l_characteristic); // Renvoie une caractéristique de l'entité

    sf::Vector2f getPosition(); //Permet de recuperer la position de l'entite
    void setPosition(sf::Vector2f l_position); //Permet de modifier la position de l'entite par un vecteur compose de deux float
    void setPosition(float l_width, float l_height); //Permet de modifier la position de l'entite par de deux float

    void setSprite(const std::string l_path);  //Modifie le sprite
    void Draw();                               //Permet de dessiner le sprite
    void setContext(SharedContext *l_context); //Modifie le contexte
    void setSpriteScale(float l_x, float l_y); //Permet de modifier l'echelle du sprite

    void Restart();
};

#endif // ENTITY_H
