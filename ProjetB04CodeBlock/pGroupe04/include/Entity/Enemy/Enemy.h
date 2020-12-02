#ifndef ENEMY_H
#define ENEMY_H
#include "Entity/Entity.h"
#include "Entity/Enemy/EnemyAbility.h"
#include "Entity/Enemy/EnemyAbilityDefensive.h"
#include "Entity/Enemy/EnemyAbilityOffensive.h"
#include "Entity/Enemy/Behaviour.h"
#include <vector>

class Enemy: public Entity
{

    private:
        std::vector<EnemyAbility *> m_abilities;
        Behaviour *behaviour;

    public:
        Enemy();
        Enemy(int l_healthPt);
        virtual ~Enemy();
        Enemy(const Enemy& other);
        Enemy& operator=(const Enemy& other);
        virtual std::string getClassName() const;

        //GET & SET
        void setStrategy(Behaviour *behaviour);
        //Fin GET & SET

        // Méthodes concerant le vector
        void addAbilities(EnemyAbility *l_enemyAbility);
        void removeAbilities(EnemyAbility *l_enemyAbility);
        int SearchAbility(EnemyAbility &l_enemyAbility);
        // Fin vector

        //Strategy
        void useAbility(Entity &entity);
    protected:

};

#endif // ENEMY_H
