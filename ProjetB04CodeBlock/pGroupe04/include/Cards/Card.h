#ifndef CARD_PGROUPE04_H
#define CARD_PGROUPE04_H
#include <string>

using namespace std;

class Card
{
private:
    string label, description;
    int costAction, value;

public:
    Card(string label = "No_Label", string description = "No_Description", int costAction = 0, int value = 0);
    virtual ~Card() = 0;
    Card(const Card &other);
    Card &operator=(const Card &rhs);

    string getLabel() const;
    void setLabel(const string label);
    string getDescription() const;
    void setDescription(const string description);
    int getCostAction() const;
    void setCostAction(const int costAction);
    int getValue() const;
    void setValue(const int value);

    virtual Card *clone() const = 0;
};

#endif // CARD_PGROUPE04_H