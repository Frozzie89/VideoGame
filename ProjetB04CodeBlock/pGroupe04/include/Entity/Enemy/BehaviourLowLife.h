#ifndef BEHAVIOURLOWLIFE_H
#define BEHAVIOURLOWLIFE_H

#include "Entity/Enemy/Behaviour.h"

// Lorsque l'ennemi a ce type de comportement, il preferera utiliser des cartes defensives
class BehaviourLowLife : public Behaviour
{
public:
    BehaviourLowLife(int l_rate = 75);                          // Constructeur avec une valeur par defaut
    virtual ~BehaviourLowLife();                                // Destructeur
    BehaviourLowLife(const BehaviourLowLife &other);            // Constructeur de copie
    BehaviourLowLife &operator=(const BehaviourLowLife &other); // Operateur d'affectation

    string getClassName(); // Return le nom de la classe

protected:
private:
};

#endif // BEHAVIOURLOWLIFE_H
