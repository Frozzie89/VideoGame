#ifndef CARD_PGROUPE04_H
#define CARD_PGROUPE04_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Entity/Entity.h"
#include "SharedContext.h"

// Contient le patron d'une carte et defini les effets qu'une carte peut avoir
class Card
{
protected:
    std::string label, path;
    int costAction, value;
    sf::Vector2f m_position;
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    SharedContext *m_context;

    bool m_draw;

public:
    Card(std::string label = "No_Label", std::string path = "No_path", int costAction = 0, int value = 0, SharedContext *m_context = nullptr);
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

    virtual int activateEffect(Entity &entity) = 0; // Active l'effet de la carte
    virtual std::string str() const;
    virtual Card *clone() const = 0;
    virtual std::string getClassName() const;
    virtual bool operator==(const Card &card) const;

    bool checkCollision();

    void Move(sf::RenderWindow &l_window); // permet de deplacer la carte dans la fenêtre

    void HandleInput();

    void Draw(); //Permet de dessiner le sprite dans la fenetre de jeu

    void SetSpriteOrigin(float l_width, float l_height); //Permet de modifier l'origine du sprite en passant deux float
    void SetSpriteOrigin(sf::Vector2f l_position);       //Permet de modifier l'origine du sprite en passant un vecteur de float

    void SetSpritePosition(float l_width, float l_height); //Permet de modifier la position du sprite, en passant deux float
    void SetSpritePositon(sf::Vector2f l_position);        //Permet de modifier la position du sprite, en passant un vecteur de float

    void SetContext(SharedContext *l_context);

    void SetPosition(float posX, float posY);

    void SetDraw(bool m_bool);
};

#endif // CARD_PGROUPE04_H
