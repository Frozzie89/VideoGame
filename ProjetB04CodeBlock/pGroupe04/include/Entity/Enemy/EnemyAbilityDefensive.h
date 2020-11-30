#ifndef ENEMYABILITYDEFENSIVE_H
#define ENEMYABILITYDEFENSIVE_H
#include "Entity/Enemy/EnemyAbility.h"

class EnemyAbilityDefensive: public EnemyAbility
{
    public:
        EnemyAbilityDefensive();
        virtual ~EnemyAbilityDefensive();
        EnemyAbilityDefensive(const EnemyAbilityDefensive& other);
        EnemyAbilityDefensive& operator=(const EnemyAbilityDefensive& other);

        int activateEffect();

    protected:

    private:
};

#endif // ENEMYABILITYDEFENSIVE_H
