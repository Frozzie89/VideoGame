#ifndef ENTITY_H
#define ENTITY_H

#include "Entity/Characteristics.h"
#include "Entity/Health.h"
#include "Entity/Shield.h"

class Entity
{
public:
    Entity();
    virtual ~Entity();
    Entity(const Entity &other);
    Entity &operator=(const Entity &other);

private:
    Characteristics m_entityCaracteristics; //Liste de caracteristiques de l'entite
    bool m_turn;                            //Permet de savoir s'il s'agit du tour de l'entite

    //Methode a redefinir dans les sous-classes
    virtual void action() = 0; //Permet d'executer une action

    //Methodes generals
    //Get/Setter
    bool isTurn() const; //Permet de savoir s'il s'agit du tour de l'entite
    void setTurn();      //Permet de switcher la valeur de m_turn;
    virtual std::string getClassName() const;

    void AddHealth(Health l_health); //Permet d'ajouter de la vie aux caracteristiques de l'entite
    void AddShield(Shield l_shield); //permet d'ajouter de l'armure aux caracteristiques de l'entite
    void endTurn();                  //met fin au tour de l'entite
};

#endif // ENTITY_H
