#ifndef STATE_INTRO_H
#define STATE_INTRO_H
#include <SFML/Graphics.hpp>

#include "State/BaseState.h"
#include "StateManager.h" //vu que la classe est declaree dans BaseState, nous devons l'implementer
/*
    Cette classe va definir ce que l'on va retrouve sur la fenetre lorsque l'on lancera au jeu.
    Elle herite de la classe BaseState.
    Parmi ses attributs, on retrouve une police de caracteres, deux elements Texte nous permettant d'afficher du texte a l'ecran, le temps passe sur ladite state,
    une texture pour le logo du jeu ainsi qu'un sprite pour celui-ci
*/
class State_Intro : public BaseState
{
public:
    State_Intro(StateManager *l_stateManager); //Constructeur
    virtual ~State_Intro(); //Destructeur

    void OnCreate(); //Permet de creer les differents elements graphiques que l'on va retrouver dans la fenetre
    void OnDestroy(); //Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet

    void Activate(); //Methode qui d'activer certaines modifications si la state a deja ete utilisee
    void Deactivate(); //Permet de supprimer les modifications si la state n'est plus utilisee

    void Update(const sf::Time &l_time); //Met a jour ce qui est a l'ecran
    void Draw(); //Permet de dessiner les differents elements graphiques

    void Continue(EventDetails *l_details); //Sert de transition vers un autre etat

protected:
private:
    sf::Texture m_introTexture; //Texture du logo
    sf::Sprite m_introSprite; //Sprite du logo
    sf::Font m_font; //Police de caractere du texte
    sf::Text m_indication; //Texte servant d'indication
    sf::Text m_title; // Texte servant de titre a l'application
    float m_timePassed; //Sert a compter le temps passe sur cet etat
};

#endif // STATE_INTRO_H
