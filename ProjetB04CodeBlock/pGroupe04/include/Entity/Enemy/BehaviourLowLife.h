#ifndef BEHAVIOURLOWLIFE_H
#define BEHAVIOURLOWLIFE_H
#include "Entity/Enemy/Behaviour.h"

class BehaviourLowLife : public Behaviour
{
private:
protected:
public:
    BehaviourLowLife();
    virtual ~BehaviourLowLife();
    BehaviourLowLife(const BehaviourLowLife &other);
    BehaviourLowLife &operator=(const BehaviourLowLife &other);
};

#endif // BEHAVIOURLOWLIFE_H
