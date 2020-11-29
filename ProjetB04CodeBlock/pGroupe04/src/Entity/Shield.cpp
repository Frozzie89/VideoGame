#include "Entity/Shield.h"

Shield::Shield(int l_shield) : Characteristic(l_shield)
{
    //ctor
}

Shield::~Shield()
{
    //dtor
}

Shield::Shield(const Shield &other) : Characteristic(other)
{
    //copy ctor
}

Shield &Shield::operator=(const Shield &rhs)
{
    if (this != &rhs)
    {
        Characteristic::operator=(rhs);
    };
    //assignment operator
    return *this;
}
//Permet de sortir les elements de la classe
std::string Shield::str() const
{
    return "Shield : " + std::to_string(Characteristic::GetValue());
}
//Permet de recuperer le nom de la classe
std::string Shield::getClassName() const
{
    return "Shield";
}
