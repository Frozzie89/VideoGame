#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        Enemy(const Enemy& other);
        Enemy& operator=(const Enemy& other);

    protected:

    private:
};

#endif // ENEMY_H
