#include "Cards/Card.h"
#include <sstream>

Card::Card(std::string label, std::string path, int costAction, int value, SharedContext* l_context) : label(label), path(path), costAction(costAction), value(value),m_context(l_context)
{

    m_texture.loadFromFile(path);
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.5,0.5);
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

bool Card::operator==(const Card &card) const
{
    return label == card.getLabel() && value == card.getValue() && costAction == card.getCostAction();
}

void Card::HandleInput()
{
}

sf::Vector2f Card::GetPosition()
{
    return m_position;
}

void Card::SetPosition(sf::Vector2f l_position)
{
    m_position = l_position;
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
//Permet de dessiner le sprite dans la fenetre de jeu
void Card::Draw()
{
    sf::RenderWindow* window = m_context->m_wind->GetRenderWindow();
    window->draw(m_sprite);
}
//Permet de modifier l'origine du sprite en passant deux float
void Card::SetSpriteOrigin(float l_width, float l_height)
{
    m_sprite.setOrigin(l_width,l_height);
}
//Permet de modifier la position du sprite en passant deux float
void Card::SetSpritePosition(float l_width, float l_height)
{
    m_position.x = l_width;
    m_position.y = l_height;
    m_sprite.setPosition(l_width,l_height);
}
//Permet de modifier l'origine du sprite en passant un vector de float
void Card::SetSpriteOrigin(sf::Vector2f l_position)
{
    m_sprite.setOrigin(l_position);
}
//Permet de modifier la position du sprite en passant un vector de flaot
void Card::SetSpritePositon(sf::Vector2f l_position)
{
    m_position = l_position;
    m_sprite.setPosition(m_position);
}

