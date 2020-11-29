#ifndef HEALTH_H
#define HEALTH_H

#include "Entity/Characteristic.h"

class Health : public Characteristic
{
public:
    Health(int l_health = 100);
    virtual ~Health();
    Health(const Health &other);
    Health &operator=(const Health &rhs);

    //Methodes heritees
    std::string str() const;
    std::string getClassName() const;

    Health *clone() const { return new Health(*this); }

private:
};

#endif // HEALTH_H
