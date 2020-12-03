#ifndef SHIELD_H
#define SHIELD_H

#include "Entity/Characteristics/Characteristic.h"
/*
    Cette classe va definir le nombre d'armure.
    Elle herite de la classe characteristic.
*/
class Shield : public Characteristic
{
public:
    Shield(int l_shield = 100); //Constructeur
    virtual ~Shield(); //Destructeur
    Shield(const Shield &other); //Constructeur de copie
    Shield &operator=(const Shield &rhs); //Operateur d'affectation

    //Methodes heritees
    std::string str() const; //Permet de sortir une chaine de caracteres reprenant le nom et la valeur de la classe
    std::string getClassName() const; //Retourne le nom de la classe

    Shield *clone() const { return new Shield(*this); } //Permet de creer une copie de l'objet

private:
};

#endif // SHIELD_H
