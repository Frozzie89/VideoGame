#ifndef ENEMYABILITY_H
#define ENEMYABILITY_H
#include <string>


class EnemyAbility
{
    public:
        EnemyAbility();
        EnemyAbility(std::string l_name, int l_value);
        virtual ~EnemyAbility();
        EnemyAbility(const EnemyAbility& other);
        EnemyAbility& operator=(const EnemyAbility& other);

        // GET & SET
        int getValue() const;
        void setValue(const int l_value);

        std::string getName() const;
        void setName(const std::string l_name);
        // End GET & SET

        virtual int activateEffect() = 0;

    protected:

    private:
        std::string m_name;
        int m_value;
};

#endif // ENEMYABILITY_H
