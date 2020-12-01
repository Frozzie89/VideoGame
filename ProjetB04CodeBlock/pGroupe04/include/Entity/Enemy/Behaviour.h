#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H


class Behaviour
{
    public:
        Behaviour();
        virtual ~Behaviour();
        Behaviour(const Behaviour& other);
        Behaviour& operator=(const Behaviour& other);

        virtual void useAbility() = 0;
    protected:
    private:
};

#endif // BEHAVIOUR_H
