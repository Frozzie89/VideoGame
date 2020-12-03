#ifndef STATE_MAINMENU_H
#define STATE_MAINMENU_H

#include <SFML/Graphics.hpp>

#include "State/BaseState.h"
#include "StateManager.h"
#include <iostream>

using namespace std;

/*
    Cette classe va definir ce que l'on va retrouve sur la fenetre lorsque l'on serra sur le menu principal du jeu.
    Elle herite de la classe BaseState.
    Parmi ses attributs, on retrouve une police de caracteres, deux elements Texte nous permettant d'afficher du texte a l'ecran, trois vecteurs correspondant a la taille des boutons,
    la position des boutons et le padding entre les differents boutons, trois rectangles nous servant de boutons ainsi que leur label correspondant et le temps passee sur le state
*/

class State_MainMenu : public BaseState
{
public:
    State_MainMenu(StateManager *l_stateManager); // Constructeur
    virtual ~State_MainMenu(); // Destructeur

    void OnCreate(); //Permet de creer les differents elements graphiques que l'on va retrouver dans la fenetre
    void OnDestroy(); //Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet

    void Activate(); //Methode qui d'activer certaines modifications si la state a deja ete utilisee
    void Deactivate(); //Permet de supprimer les modifications si la state n'est plus utilisee

    void Update(const sf::Time &l_time); //Met a jour ce qui est a l'ecran
    void Draw(); //Permet de dessiner les differents elements graphiques

    void MouseClick(EventDetails *l_details); //Permet de gerer les events lies au click de la souris
    void MouseHover(); //Permet de gerer les events lies au survols des elements par la souris

protected:
private:
    sf::Text m_text; //Texte a afficher
    sf::Text m_hint; //Texte servant d'indications sur les differents classes du jeu
    sf::Font m_font; //Police de caracteres des textes

    sf::Vector2f m_buttonSize; //Taille des boutons
    sf::Vector2f m_buttonPos; // Position des boutons
    unsigned int m_buttonPadding; //Padding entre les boutons

    sf::RectangleShape m_rects[3]; //On va creer trois "boutons"
    sf::Text m_labels[3]; //Vu qu'on a trois "boutons", il nous faut trois labels

    // sf::Text m_Easter;
    float m_timePassed; //Temps passe sur le state
};

#endif // STATE_MAINMENU_H
