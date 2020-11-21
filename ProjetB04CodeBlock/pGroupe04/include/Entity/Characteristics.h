#ifndef CHARACTERISTICS_H
#define CHARACTERISTICS_H

#include "Entity/Characteristic.h"
#include <vector>

class Characteristics
{

    private:
        std::vector <Characteristic*> m_characteristics;

    public:
        //CRUD
        Characteristics();
        virtual ~Characteristics();
        Characteristics(const Characteristics& other);
        Characteristics& operator=(const Characteristics& other);

        void AddCharacteristic(Characteristic* l_characteristic); //Permet d'ajouter une caractéristique au vecteur
        void DeleteCharacteristic(Characteristic& l_characteristic); //Permet de supprimer une caractéristique au vecteur
        int SearchCharacteristic(Characteristic& l_characteristic); //Permet de retrouver une caracteristique du vecteur.

        std::string getCharacteristics() const; //Permet de sortir les caracteristiques

};

#endif // CHARACTERISTICS_H
