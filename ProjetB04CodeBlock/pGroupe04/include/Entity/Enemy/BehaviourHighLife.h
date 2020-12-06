#ifndef BEHAVIOURHIGHLIFE_H
#define BEHAVIOURHIGHLIFE_H

#include "Entity/Enemy/Behaviour.h"

// Lorsque l'ennemi a ce type de comportement, il préfèrera utiliser des cartes offensives
class BehaviourHighLife : public Behaviour
{
public:
    BehaviourHighLife(int l_rate = 25);
    virtual ~BehaviourHighLife();
    BehaviourHighLife(const BehaviourHighLife &other);
    BehaviourHighLife &operator=(const BehaviourHighLife &other);

    string getClassName();

protected:
private:
};

#endif // BEHAVIOURHIGHLIFE_H
