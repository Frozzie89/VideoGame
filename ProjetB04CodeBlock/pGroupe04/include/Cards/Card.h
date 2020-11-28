#ifndef CARD_PGROUPE04_H
#define CARD_PGROUPE04_H
#include <string>
#include <SFML/Graphics.hpp>

class Card
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

    sf::Vector2f GetPosition();                // Retourne la position de la carte
    void SetPosition(sf::Vector2f l_position); // Modifie la position de la carte

    virtual std::string str() const;
    virtual Card *clone() const = 0;
    virtual std::string getClassName()const;

    bool checkCollision();

    void Move(sf::RenderWindow &l_window);

    void HandleInput();
};

#endif // CARD_PGROUPE04_H
