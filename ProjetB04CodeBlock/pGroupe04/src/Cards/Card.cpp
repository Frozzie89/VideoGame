#include "Card.h"

using namespace std;

Card::Card(string label, string description, int costAction, int value) : label(label), description(description), costAction(costAction), value(value) {}

Card::~Card() {}

Card::Card(const Card &other)
{
    this->label = other.label;
    this->description = other.description;
    this->costAction = other.costAction;
    this->value = other.value;
}
Card &Card::operator=(const Card &rhs)
{
    if (this != &rhs)
    {
        this->label = rhs.label;
        this->description = rhs.description;
        this->costAction = rhs.costAction;
        this->value = rhs.value;
    }
    return *this;
}

string Card::getLabel() const
{
    return label;
}

void Card::setLabel(const string label)
{
    this->label = label;
}

string Card::getDescription() const
{
    return description;
}

void Card::setDescription(const string description)
{
    this->description = description;
}

int Card::getCostAction() const
{
    return costAction;
}

void Card::setCostAction(const int costAction)
{
    this->costAction = costAction;
}

int Card::getValue() const
{
    return value;
}

void Card::setValue(const int value)
{
    this->value = value;
}
