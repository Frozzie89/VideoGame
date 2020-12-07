#include "Cards/Card.h"
#include <sstream>
//Constructeur
Card::Card(std::string label, std::string path, int costAction, int value, SharedContext *l_context) : label(label), path(path), costAction(costAction), value(value), m_context(l_context)
{
    m_draw = true;
}
//Destructeur
Card::~Card() {}

// Constructeur de copie
Card::Card(const Card &other)
{
    this->label = other.label;
    this->path = other.path;
    this->costAction = other.costAction;
    this->value = other.value;
    m_draw = true;
}

// Operateur d'affectation
Card &Card::operator=(const Card &rhs)
{
    if (this != &rhs)
    {
        this->label = rhs.label;
        this->path = rhs.path;
        this->costAction = rhs.costAction;
        this->value = rhs.value;
        m_draw = true;
    }
    return *this;
}

// renvoie le label
std::string Card::getLabel() const
{
    return label;
}

// affecte le label
void Card::setLabel(const std::string label)
{
    this->label = label;
}

// renvoie le path
std::string Card::getPath() const
{
    return path;
}

// renvoie costAction
int Card::getCostAction() const
{
    return costAction;
}

// affecte costAction
void Card::setCostAction(const int costAction)
{
    this->costAction = costAction;
}

// renvoie value
int Card::getValue() const
{
    return value;
}

// affecte value
void Card::setValue(const int value)
{
    this->value = value;
}
// Fin GET & SET

// Affiche les informations de l'objet
std::string Card::str() const
{
    std::stringstream res;
    res << "Label : " << label << " - Path : " << path
        << " - CA : " << costAction << " - Value :  " << value << std::endl;

    return res.str();
}

// Deux cartes sont identique s'ils sont de la même classe, s'ils sont le même label et s'ils on le même coût
bool Card::operator==(const Card &card) const
{
    return getClassName() == card.getClassName() && label == card.getLabel() && value == card.getValue() && costAction == card.getCostAction();
}

void Card::HandleInput()
{
    // Todo
}

// renvoie la position
sf::Vector2f Card::GetPosition()
{
    return m_position;
}

// affecte une position
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
    if (m_draw)
    {
        sf::RenderWindow *window = m_context->m_wind->GetRenderWindow();

        m_texture.loadFromFile(path);
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(0.5, 0.5);
        m_sprite.setOrigin(207, 335);
        window->draw(m_sprite);
    }
}
//Permet de modifier l'origine du sprite en passant deux float
void Card::SetSpriteOrigin(float l_width, float l_height)
{
    m_sprite.setOrigin(l_width, l_height);
}
//Permet de modifier la position du sprite en passant deux float
void Card::SetSpritePosition(float l_width, float l_height)
{
    m_position = sf::Vector2f(l_width, l_height);
    m_sprite.setPosition(m_position);
    m_sprite.setOrigin(m_position);
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
    m_sprite.setOrigin(m_position.x / 2, m_position.y / 2);
}
void Card::SetContext(SharedContext *l_context)
{
    m_context = l_context;
}
void Card::SetPosition(float posX, float posY)
{
    m_position = sf::Vector2f(posX, posY);
}
void Card::SetDraw(bool l_bool)
{
    m_draw = l_bool;
}
