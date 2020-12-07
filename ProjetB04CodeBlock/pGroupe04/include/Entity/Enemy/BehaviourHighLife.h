#ifndef BEHAVIOURHIGHLIFE_H
#define BEHAVIOURHIGHLIFE_H

#include "Entity/Enemy/Behaviour.h"

// Lorsque l'ennemi a ce type de comportement, il preferera utiliser des cartes offensives
class BehaviourHighLife : public Behaviour
{
public:
    BehaviourHighLife(int l_rate = 25);                             // Constructeur avec une valeur par defaut
    virtual ~BehaviourHighLife();                                   // Destructeur
    BehaviourHighLife(const BehaviourHighLife &other);              // Constructeur de copie
    BehaviourHighLife &operator=(const BehaviourHighLife &other);   // Operateur d'affectation

    string getClassName();  // Return le nom de la classe

protected:
private:
};

#endif // BEHAVIOURHIGHLIFE_H
