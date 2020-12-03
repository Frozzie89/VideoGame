#ifndef STATE_PAUSED_H
#define STATE_PAUSED_H


#include "State/BaseState.h"
#include "StateManager.h"
/*
    Cette classe va definir ce que l'on va retrouve sur la fenetre lorsque l'on jouera au jeu.
    Elle herite de la classe BaseState.
    Parmi ses attributs, on retrouve une police de caracteres, un element Texte nous permettant d'afficher que le jeu est en pause
*/
class State_Paused:public BaseState
{
    public:
        State_Paused(StateManager* l_stateManager); //Constructeur
        virtual ~State_Paused(); //Destructeur

        void OnCreate(); //Permet de creer les differents elements graphiques que l'on va retrouver dans la fenetre
        void OnDestroy(); //Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet

        void Activate(); //Methode qui d'activer certaines modifications si la state a deja ete utilisee
        void Deactivate(); //Permet de supprimer les modifications si la state n'est plus utilisee

        void Update(const sf::Time& l_time); //Met a jour ce qui est a l'ecran
        void Draw(); //Permet de dessiner les differents elements graphiques

        void Unpause(EventDetails* l_details); //Permet de reprendre le jeu

    protected:

    private:
        sf::Text m_text; //Texte a afficher
        sf::RectangleShape m_rect; //
        sf::Font m_font; //Police du texte affiche
};

#endif // STATE_PAUSED_H
