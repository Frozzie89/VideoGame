#ifndef BEHAVIOURHIGHLIFE_H
#define BEHAVIOURHIGHLIFE_H

#include "Entity/Enemy/Behaviour.h"

// Lorsque l'ennemi a ce type de comportement, il préfèrera utiliser des cartes offensives
class BehaviourHighLife : public Behaviour
{
public:
    BehaviourHighLife();
    virtual ~BehaviourHighLife();
    BehaviourHighLife(const BehaviourHighLife &other);
    BehaviourHighLife &operator=(const BehaviourHighLife &other);

protected:
private:
};

#endif // BEHAVIOURHIGHLIFE_H
