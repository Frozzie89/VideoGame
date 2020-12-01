#ifndef SHIELD_H
#define SHIELD_H

#include "Entity/Characteristics/Characteristic.h"

// Caractéristique gérant les points d'armure
class Shield : public Characteristic
{
public:
    Shield(int l_shield = 100);
    virtual ~Shield();
    Shield(const Shield &other);
    Shield &operator=(const Shield &rhs);

    //Methodes heritees
    std::string str() const;          //Permet de connaitre les elements de la classe et leur valeur
    std::string getClassName() const; // Permet de connaitre le nom de la classe

    Shield *clone() const { return new Shield(*this); }

private:
};

#endif // SHIELD_H