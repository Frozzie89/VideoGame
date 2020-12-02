#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H
#include "Entity/Entity.h"
#include "Entity/Enemy/EnemyAbility.h"
#include "Entity/Enemy/EnemyAbilityDefensive.h"
#include "Entity/Enemy/EnemyAbilityOffensive.h"


class Behaviour
{
    public:
        Behaviour();
        virtual ~Behaviour();
        Behaviour(const Behaviour& other);
        Behaviour& operator=(const Behaviour& other);

        void useAbility(Entity &l_player, Entity &l_enemy, std::vector<EnemyAbility *> m_abilities);
        int getRandomAbility(std::vector<EnemyAbility *> m_abilities);
        int searchAbilityType(std::vector<EnemyAbility*>m_abilities, std::string lookingForClassAbility);
    protected:

        //D�fini le taux de carte d�fensive
        int m_rate;
    private:
};

#endif // BEHAVIOUR_H
