#include "Entity/Characteristics/Characteristic.h"
#include <iostream>
//Constructeur
Characteristic::Characteristic(int l_value) : m_value(l_value)
{
    //ctor
}
//Destructeur
Characteristic::~Characteristic()
{
    //dtor
}
//Constructeur de copie
Characteristic::Characteristic(const Characteristic &other)
{
    m_value = other.m_value;
}
//Operateur d'affection
Characteristic &Characteristic::operator=(const Characteristic &rhs)
{
    if (this != &rhs)
    {
        m_value = rhs.m_value;
    }

    return *this;
}
//Augmente de la valeur interne d'une valeur passée en argument
void Characteristic::RaiseValue(int l_value)
{
    std::cout << "m_value before : " << m_value << std::endl;
    std::cout << "l_value : " << l_value << std::endl;
    m_value += l_value;
    std::cout << "m_value after : " << m_value << std::endl;
}
//Diminue la valeur interne d'une valeur passée en argument
void Characteristic::LowerValue(int l_value)
{
    m_value -= l_value;
}
//Retourne la valeur interne
int Characteristic::GetValue() const
{
    return m_value;
}
