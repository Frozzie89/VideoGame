#ifndef CHARACTERISTICS_H
#define CHARACTERISTICS_H

#include "Entity/Characteristics/Characteristic.h"
#include <vector>

// Cette classe sert à implementer les différentes caractéristiques
class Characteristics
{

private:
    std::vector<Characteristic *> m_characteristics;

public:
    //CRUD
    Characteristics();
    virtual ~Characteristics();
    Characteristics(const Characteristics &other);
    Characteristics &operator=(const Characteristics &rhs);

    void AddCharacteristic(Characteristic *l_characteristic);    //Permet d'ajouter une caractéristique au vecteur
    void DeleteCharacteristic(Characteristic &l_characteristic); //Permet de supprimer une caractéristique au vecteur
    int SearchCharacteristic(Characteristic &l_characteristic);  //Permet de retrouver une caracteristique du vecteur.

    // Augmente une valeur d'une caractéristique, par index
    void RaiseCharacteristic(int l_index, int l_value);
    // Diminue une valeur d'une caractéristique, par index
    void LowerCharacteristic(int l_index, int l_value);
    // Augmente une valeur d'une caractéristique, par objet
    void RaiseCharacteristic(Characteristic &l_characteristic, int l_value);
    // Diminue une valeur d'une caractéristique, par objet
    void LowerCharacteristic(Characteristic &l_characteristic, int l_value);

    Characteristic *getCharacteristic(Characteristic &l_characteristic);
    Characteristic *getCharacteristic(std::string l_nom);
};

#endif // CHARACTERISTICS_H
