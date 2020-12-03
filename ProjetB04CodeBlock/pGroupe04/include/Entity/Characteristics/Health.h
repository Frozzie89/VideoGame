#ifndef HEALTH_H
#define HEALTH_H

#include "Entity/Characteristics/Characteristic.h"

/*
    Cette classe va definir le nombre de points.
    Elle herite de la classe characteristic.
*/
class Health : public Characteristic
{
public:
    Health(int l_health = 100); //Constructeur
    virtual ~Health(); //Destructeur
    Health(const Health &other); //Constructeur de copie
    Health &operator=(const Health &rhs); //Operateur d'affectation

    //Methodes heritees
    std::string str() const; //Retourne une chaine de caractere contenant le nom de la classe ainsi que sa valeur
    std::string getClassName() const; //Retourne le nom de la classe

    Health *clone() const { return new Health(*this); } //Permet de creer un clone de l'objet

private:
};

#endif // HEALTH_H
