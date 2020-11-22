#ifndef CARD_PGROUPE04_H
#define CARD_PGROUPE04_H
#include <string>

class Card
{
private:
    std::string label, description;
    int costAction, value;

public:
    Card(std::string label = "No_Label", std::string description = "No_Description", int costAction = 0, int value = 0);
    virtual ~Card() = 0;
    Card(const Card &other);
    Card &operator=(const Card &rhs);

    std::string getLabel() const;
    void setLabel(const std::string label);
    std::string getDescription() const;
    void setDescription(const std::string description);
    int getCostAction() const;
    void setCostAction(const int costAction);
    int getValue() const;
    void setValue(const int value);

    virtual Card *clone() const = 0;
};

#endif // CARD_PGROUPE04_H