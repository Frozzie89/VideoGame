#include "Entity/Characteristics/Characteristics.h"
#include <iostream>
//Constructeur
Characteristics::Characteristics()
{
    //ctor
}
//Destructeur
//Composition -> Donc suppression des caracteristiques lors de la destruction de l'objet
Characteristics::~Characteristics()
{
    //dtor
    for (int i = 0; i < (int)m_characteristics.size(); i++)
    {
        delete m_characteristics[i];
    }
}
//Constructeur de copie
Characteristics::Characteristics(const Characteristics &other)
{
    //copy ctor
    for (int i = 0; i < (int)other.m_characteristics.size(); i++)
    {
        m_characteristics.push_back(other.m_characteristics[i]->clone());
    }
}
//Operateur d'affectation
Characteristics &Characteristics::operator=(const Characteristics &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < (int)m_characteristics.size(); i++)
        {
            delete m_characteristics[i];
        }
        m_characteristics.clear();

        for (int i = 0; i < (int)rhs.m_characteristics.size(); i++)
        {
            m_characteristics.push_back(rhs.m_characteristics[i]->clone());
        }
    }
    //assignment operator
    return *this;
}
//Permet d'ajouter une caracteristique a la liste
void Characteristics::AddCharacteristic(Characteristic *l_characteristic)
{
    if (SearchCharacteristic(*l_characteristic) == -1)
        m_characteristics.push_back(l_characteristic->clone());
}
//Permet de supprimer une caracteristique de la liste
void Characteristics::DeleteCharacteristic(Characteristic &l_characteristic)
{
    int ind = SearchCharacteristic(l_characteristic);
    if (ind != -1)
    {
        Characteristic *tmp = *(m_characteristics.begin() + ind);
        m_characteristics.erase(m_characteristics.begin() + ind);
        delete tmp;
    }
}
//Permet de sortir les informations contenus dans la liste
Characteristic *Characteristics::getCharacteristic(Characteristic &l_characteristic)
{
    int indexCharacteristic = SearchCharacteristic(l_characteristic);
    if (indexCharacteristic == -1)
        return &l_characteristic;

    return m_characteristics[indexCharacteristic];
}
//Permet de chercher une caracteristique dans la liste. Si elle est la, renvoie son indice, sinon, -1
int Characteristics::SearchCharacteristic(Characteristic &l_characteristic)
{
    for (int i = 0; i < (int)m_characteristics.size(); i++)
    {
        std::cout << i << std::endl;

        if (m_characteristics[i]->getClassName() == l_characteristic.getClassName())
            return i;
    }
    return -1;
}
//Augmente la caracteristique choisi par la valeur passee en argument, via index
void Characteristics::RaiseCharacteristic(int l_index, int l_value)
{
    std::cout << l_value << std::endl;
    m_characteristics[l_index]->RaiseValue(l_value);
}

//Augmente la caracteristique choisi par la valeur passee en argument, via objet
void Characteristics::RaiseCharacteristic(Characteristic &l_characteristic, int l_value)
{
    // std::cout << l_value << std::endl;

    int indexCharacteristic = SearchCharacteristic(l_characteristic);

    if (indexCharacteristic != -1)
        m_characteristics[indexCharacteristic]->RaiseValue(l_value);
}

//Diminue la caracteristique choisi par la valeur passe en argument, via index
void Characteristics::LowerCharacteristic(int l_index, int l_value)
{
    // std::cout << l_value << std::endl;

    m_characteristics[l_index]->LowerValue(l_value);
}

//Diminue la caracteristique choisi par la valeur passe en argument, via objet
void Characteristics::LowerCharacteristic(Characteristic &l_characteristic, int l_value)
{
    int indexCharacteristic = SearchCharacteristic(l_characteristic);

    if (indexCharacteristic != -1)
        m_characteristics[indexCharacteristic]->LowerValue(l_value);
}
