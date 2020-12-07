#ifndef STATE_OPTION_H
#define STATE_OPTION_H

#include <SFML/Graphics.hpp>

#include "State/BaseState.h"
#include "StateManager.h"
/*
    Cette classe va definir ce que l'on va retrouve sur la fenetre lorsque l'on sera dans les options du jeu.
    Elle herite de la classe BaseState.
    Parmi ses attributs, on retrouve une police de caracteres, un element Texte nous permettant d'afficher du texte a l'ecran, le temps passe sur le dit state,
    trois vecteurs correspondant a la taille des boutons,    la position des boutons et le padding entre les differents boutons,deux rectangles servant de boutons
    avec leur label respectif
*/
class State_Option: public BaseState
{
    public:
        State_Option(StateManager *l_stateManager); //Constructeur
        virtual ~State_Option(); //Destructeur

        void OnCreate(); //Permet de creer les differents elements graphiques que l'on va retrouver dans la fenetre
        void OnDestroy(); //Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet

        void Activate(); //Methode qui d'activer certaines modifications si la state a deja ete utilisee
        void Deactivate(); //Permet de supprimer les modifications si la state n'est plus utilisee

        void Update(const sf::Time &l_time); //Met a jour ce qui est a l'ecran
        void Draw(); //Permet de dessiner les differents elements graphiques

        void MouseClick(EventDetails *l_details); //Permet de gerer les clicks de la souris
        void Game(EventDetails* l_details); //Permet d'acceder a la phase de jeu

    protected:

    private:
        sf::RectangleShape m_rectTitle; //Rectangle servant de bordure au titre
        sf::Text m_title; //Titre du state
        sf::Text m_egg;
        sf::Font m_font; //Police du texte

        sf::Vector2f m_buttonSize; //Definit la taille des boutons
        sf::Vector2f m_buttonPos; //Definit la position des boutons
        unsigned int m_buttonPadding; //Definit le padding entre les boutons

        sf::RectangleShape m_rects[2]; //On va creer trois "boutons"
        sf::Text m_labels[2]; //Label des boutons


        float m_timePassed; //Temps passe sur le state
};

#endif // STATE_OPTION_H
