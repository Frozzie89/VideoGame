#ifndef ENEMY_H
#define ENEMY_H
#include "Entity/Entity.h"
#include "Entity/Enemy/EnemyAbility.h"
#include "Entity/Enemy/EnemyAbilityDefensive.h"
#include "Entity/Enemy/EnemyAbilityOffensive.h"
#include <vector>

class Enemy: public Entity
{

    private:
        std::vector<EnemyAbility *> m_abilities;

    public:
        Enemy();
        Enemy(int l_healthPt);
        virtual ~Enemy();
        Enemy(const Enemy& other);
        Enemy& operator=(const Enemy& other);
        std::string useAbility(EnemyAbilityDefensive &ability);
        std::string useAbility(EnemyAbilityOffensive &ability, Entity &player);
        virtual std::string getClassName() const;

        // Méthodes concerant le vector
        void addAbilities(EnemyAbility *l_enemyAbility);
        void removeAbilities(EnemyAbility *l_enemyAbility);
        int SearchAbility(EnemyAbility &l_enemyAbility);

        // Fin vector
    protected:

};

#endif // ENEMY_H
