#include "Entity/Health.h"
//Constructeur
Health::Health(int l_health) : Characteristic(l_health)
{
    //ctor
}
//Destructeur
Health::~Health()
{
    //dtor
}
//Constructeur de copie
Health::Health(const Health &other) : Characteristic(other)
{
    //copy ctor
}
//Operateur d'affectation
Health &Health::operator=(const Health &rhs)
{
    if (this != &rhs)
    {
        Characteristic::operator=(rhs);
    }
    return *this;
}
std::string Health::str() const
{
    return "Health : " + std::to_string(Characteristic::GetValue());
}
std::string Health::getClassName() const
{
    return "Health";
}
