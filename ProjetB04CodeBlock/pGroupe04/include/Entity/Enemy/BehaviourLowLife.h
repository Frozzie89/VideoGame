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

        //void useAbility(Entity &entity, std::vector<EnemyAbility *> m_abilities);
        //int getRandomAbility(std::vector<EnemyAbility *> m_abilities);
        //int searchAbilityType(std::vector<EnemyAbility*>m_abilities, std::string lookingForClassAbility);
    protected:

    private:
        //Défini le taux de carte défensive
        int m_rate;
};

#endif // BEHAVIOURLOWLIFE_H
