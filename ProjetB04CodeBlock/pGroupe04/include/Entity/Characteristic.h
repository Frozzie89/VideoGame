#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H

#include <string>

// Une Characteristic est une valeur attribuée à l'Entity pouvant être augmentée et diminuée
class Characteristic
{
private:
    int m_value;

public:
    //CRUD
    Characteristic(int l_value = 100);
    virtual ~Characteristic();
    Characteristic(const Characteristic &other);
    Characteristic &operator=(const Characteristic &rhs);

    void RaiseValue(int l_value); //Augmente de la valeur interne d'une valeur passée en argument
    void LowerValue(int l_value); //Diminue la valeur interne d'une valeur passée en argument
    int GetValue() const;         //Recupere la valeur interne

    virtual std::string str() const = 0;
    virtual std::string getClassName() const = 0;
    virtual Characteristic *clone() const = 0;
};

#endif // CHARACTERISTIC_H
