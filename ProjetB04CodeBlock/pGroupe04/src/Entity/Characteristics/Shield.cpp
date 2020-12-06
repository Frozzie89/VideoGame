#include "Entity/Characteristics/Shield.h"
//Constructeur
Shield::Shield(int l_shield) : Characteristic(l_shield)
{
    //ctor
}
//Destructeur
Shield::~Shield()
{
    //dtor
}
//Constructeur de copie
Shield::Shield(const Shield &other) : Characteristic(other)
{
    //copy ctor
}
//Operateur d'affectation
Shield &Shield::operator=(const Shield &rhs)
{
    if (this != &rhs)
    {
        Characteristic::operator=(rhs);
    }
    //assignment operator
    return *this;
}
//Permet de sortir une chaine de caracteres reprenant le nom et la valeur de la classe
std::string Shield::str() const
{
    return "Shield : " + std::to_string(Characteristic::GetValue());
}
//Permet de recuperer le nom de la classe
std::string Shield::getClassName() const
{
    return "Shield";
}
