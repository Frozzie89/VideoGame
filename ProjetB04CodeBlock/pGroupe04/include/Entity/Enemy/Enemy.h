#ifndef ENEMY_H
#define ENEMY_H
#include "Entity/Entity.h"
#include "Entity/Enemy/EnemyAbilityDefensive.h"
#include "Entity/Enemy/EnemyAbilityOffensive.h"


class Enemy: public Entity
{
    public:
        Enemy();
        Enemy(int l_healthPt);
        virtual ~Enemy();
        Enemy(const Enemy& other);
        Enemy& operator=(const Enemy& other);
        std::string useAbility(EnemyAbilityDefensive &ability);
        std::string useAbility(EnemyAbilityOffensive &ability, Entity &player);
        virtual std::string getClassName() const;

    protected:

    private:
};

#endif // ENEMY_H
