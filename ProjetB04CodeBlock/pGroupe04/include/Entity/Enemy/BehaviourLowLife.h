#ifndef BEHAVIOURLOWLIFE_H
#define BEHAVIOURLOWLIFE_H
#include "Entity/Enemy/Behaviour.h"

class BehaviourLowLife: public Behaviour
{
    public:
        BehaviourLowLife();
        virtual ~BehaviourLowLife();
        BehaviourLowLife(const BehaviourLowLife& other);
        BehaviourLowLife& operator=(const BehaviourLowLife& other);

        void useAbility();
    protected:

    private:
};

#endif // BEHAVIOURLOWLIFE_H
