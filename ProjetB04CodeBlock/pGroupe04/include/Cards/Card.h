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

    virtual std::string str() const;
    virtual Card *clone() const = 0;
    bool checkCollision();

    void HandleInput();
    void Update();
    void Render();
};

#endif // CARD_PGROUPE04_H