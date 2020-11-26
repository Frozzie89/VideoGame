#ifndef CARD_PGROUPE04_H
#define CARD_PGROUPE04_H
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Card : public sf::Drawable
{
private:
    std::string label, path;
    int costAction, value;
    sf::Vector2f positions;
    sf::Texture m_texture;
    sf::Sprite m_sprite;

public:
    Card(std::string label = "No_Label", std::string path = "No_path", int costAction = 0, int value = 0);
    virtual ~Card() = 0;
    Card(const Card &other);
    Card &operator=(const Card &rhs);

    std::string getLabel() const;
    void setLabel(const std::string label);
    std::string getPath() const;
    int getCostAction() const;
    void setCostAction(const int costAction);
    int getValue() const;
    void setValue(const int value);

    sf::Vector2f GetPosition(); // Retourne la position de la carte
    void SetPosition(sf::Vector2f l_position); // Modifie la position de la carte

    virtual std::string str() const;
    virtual Card *clone() const = 0;

    bool checkCollision();

    void Move(sf::RenderWindow& l_window);

    void HandleInput();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) =0;
};

#endif // CARD_PGROUPE04_H
