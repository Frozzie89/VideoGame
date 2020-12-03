#ifndef BEHAVIOURLOWLIFE_H
#define BEHAVIOURLOWLIFE_H
#include "Entity/Enemy/Behaviour.h"

// Lorsque l'ennemi a ce type de comportement, il préfèrera utiliser des cartes défensives
class BehaviourLowLife : public Behaviour
{
public:
    BehaviourLowLife();
    virtual ~BehaviourLowLife();
    BehaviourLowLife(const BehaviourLowLife &other);
    BehaviourLowLife &operator=(const BehaviourLowLife &other);

protected:
private:
};

#endif // BEHAVIOURLOWLIFE_H
