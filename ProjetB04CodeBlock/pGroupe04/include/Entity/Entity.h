#ifndef ENTITY_H
#define ENTITY_H

#include "Entity/Characteristics/Characteristics.h"
#include "Entity/Characteristics/Health.h"
#include "Entity/Characteristics/Shield.h"

// Une Entity représente une entité pouvant combattre dans un combat de carte, donc le joueur et l'enemi
class Entity
{
private:
    Characteristics m_entityCaracteristics; // Liste de caracteristiques de l'entite
    bool m_turn;                            // Permet de savoir s'il s'agit du tour de l'entite

public:
    Entity();
    virtual ~Entity() = 0;
    Entity(const Entity &other);
    Entity &operator=(const Entity &rhs);

    // Methode a redefinir dans les sous-classes

    // Methodes generals
    // Get/Setter
    bool isTurn() const; // Permet de savoir s'il s'agit du tour de l'entite
    void setTurn();      // Permet de switcher la valeur de m_turn;
    virtual std::string getClassName() const;

    void AddHealth(Health l_health);                                         // Permet d'ajouter de la vie aux caracteristiques de l'entite
    void AddShield(Shield l_shield);                                         // Permet d'ajouter de l'armure aux caracteristiques de l'entite
    void RaiseCharacteristic(int l_index, int l_value);                      // Fait appel à la méthode de Characteristics
    void LowerCharacteristic(int l_index, int l_value);                      // Fait appel à la méthode de Characteristics
    void RaiseCharacteristic(Characteristic &l_characteristic, int l_value); // Fait appel à la méthode de Characteristics
    void LowerCharacteristic(Characteristic &l_characteristic, int l_value); // Fait appel à la méthode de Characteristics
    void endTurn();
    void getCharacteristicsValue(); // Met fin au tour de l'entite
};

#endif // ENTITY_H
