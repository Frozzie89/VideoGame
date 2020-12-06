#ifndef BEHAVIOURLOWLIFE_H
#define BEHAVIOURLOWLIFE_H
#include "Entity/Enemy/Behaviour.h"

// Lorsque l'ennemi a ce type de comportement, il préfèrera utiliser des cartes défensives
class BehaviourLowLife : public Behaviour
{
public:
    BehaviourLowLife(int l_rate = 75);
    virtual ~BehaviourLowLife();
    BehaviourLowLife(const BehaviourLowLife &other);
    BehaviourLowLife &operator=(const BehaviourLowLife &other);

    string getClassName();

protected:
private:
};

#endif // BEHAVIOURLOWLIFE_H
