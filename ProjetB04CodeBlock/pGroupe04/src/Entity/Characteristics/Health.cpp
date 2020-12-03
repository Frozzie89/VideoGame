#include "Entity/Characteristics/Health.h"
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
//Retourne une chaine de caractere contenant le nom de la classe ainsi que sa valeur
std::string Health::str() const
{
    return "Health : " + std::to_string(Characteristic::GetValue());
}
//Retourne le nom de la classe
std::string Health::getClassName() const
{
    return "Health";
}
