#ifndef BEHAVIOURHIGHLIFE_H
#define BEHAVIOURHIGHLIFE_H

#include "Entity/Enemy/Behaviour.h"

class BehaviourHighLife: public Behaviour
{
    public:
        BehaviourHighLife();
        virtual ~BehaviourHighLife();
        BehaviourHighLife(const BehaviourHighLife& other);
        BehaviourHighLife& operator=(const BehaviourHighLife& other);

        void useAbility();
    protected:

    private:
};

#endif // BEHAVIOURHIGHLIFE_H
