#ifndef BEHAVIOURHIGHLIFE_H
#define BEHAVIOURHIGHLIFE_H

#include "Entity/Enemy/Behaviour.h"

class BehaviourHighLife : public Behaviour
{
private:
protected:
public:
    BehaviourHighLife();
    virtual ~BehaviourHighLife();
    BehaviourHighLife(const BehaviourHighLife &other);
    BehaviourHighLife &operator=(const BehaviourHighLife &other);
};

#endif // BEHAVIOURHIGHLIFE_H
