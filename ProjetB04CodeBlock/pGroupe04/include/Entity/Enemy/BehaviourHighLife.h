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

        //void useAbility(Entity &entity, std::vector<EnemyAbility *> m_abilities);
        //int getRandomAbility(std::vector<EnemyAbility *> m_abilities);
        //int searchAbilityType(std::vector<EnemyAbility*>m_abilities, std::string lookingForClassAbility);
    protected:

    private:


};

#endif // BEHAVIOURHIGHLIFE_H
