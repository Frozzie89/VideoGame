#include "Cards/Card.h"
#include <sstream>

Card::Card(std::string label, std::string path, int costAction, int value) : label(label), path(path), costAction(costAction), value(value)
{

    //m_sprite.setScale(0.5,0.5);
}

Card::~Card() {}

Card::Card(const Card &other)
{
    this->label = other.label;
    this->path = other.path;
    this->costAction = other.costAction;
    this->value = other.value;
}

Card &Card::operator=(const Card &rhs)
{
    if (this != &rhs)
    {
        this->label = rhs.label;
        this->path = rhs.path;
        this->costAction = rhs.costAction;
        this->value = rhs.value;
    }
    return *this;
}

std::string Card::getLabel() const
{
    return label;
}

void Card::setLabel(const std::string label)
{
    this->label = label;
}

std::string Card::getPath() const
{
    return path;
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

std::string Card::str() const
{
    std::stringstream res;
    res << "Label : " << label << " - Path : " << path
        << " - CA : " << costAction << " - Value :  " << value << std::endl;

    return res.str();
}

void Card::HandleInput()
{
}

sf::Vector2f Card::GetPosition()
{
    return positions;
}

void Card::SetPosition(sf::Vector2f l_position)
{
    positions = l_position;
}

bool Card::checkCollision()
{
    return false;
}

std::string Card::getClassName() const
{
    return "Card";
}

void Card::Move(sf::RenderWindow &l_window)
{
}