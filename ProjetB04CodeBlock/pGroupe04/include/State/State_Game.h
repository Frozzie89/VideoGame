#ifndef STATE_GAME_H
#define STATE_GAME_H

#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

#include "State/BaseState.h"
#include "StateManager.h"
#include "Cards/DefensiveCardWarrior.h"
#include "Entity/Enemy/Enemy.h"
#include "Entity/Player/Warrior.h"

#include "Fight.h"

/*
    Cette classe va definir ce que l'on va retrouve sur la fenetre lorsque l'on jouera au jeu.
    Elle herite de la classe BaseState.
    Parmi ses attributs, on retrouve une police de caracteres, un element Texte nous permettant d'afficher du texte a l'ecran, le temps passe sur le dit state,
    une texture pour le background ainsi qu'un sprite pour celui-ci, deux rectangles permettant de connaitre la vie restante de l'ennemie et un bouton permettant de terminer le tour
*/
class State_Game : public BaseState
{
public:
    State_Game(StateManager *l_stateManager); //Constructeur
    virtual ~State_Game(); //Destructeur

    void OnCreate(); //Permet de creer les differents elements graphiques que l'on va retrouver dans la fenetre
    void OnDestroy(); //Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet

    void Activate(); //Methode qui d'activer certaines modifications si la state a deja ete utilisee
    void Deactivate(); //Permet de supprimer les modifications si la state n'est plus utilisee

    void Update(const sf::Time &l_time); //Met a jour ce qui est a l'ecran
    void Draw(); //Permet de dessiner les differents elements graphiques

    void Option(EventDetails* l_details); //Permet de switcher vers le State option, et donc la "fenetre" d'option
    void Pause(EventDetails* l_details); //Permet de switcher vers le State Pause, et donc la "fenetre" de pause

    void CardClick(EventDetails* l_details); //Permet de cliquer sur les cartes et effectuer l'action qui en decoule

protected:
private:
    sf::Font m_font; //Police du texte affiche
    sf::Text m_text; //Texte que l'on va afficher
    float m_timePassed; //Temps passe sur le state
    sf::Texture m_bgTexture; // Texture du background
    sf::Sprite m_bgSprite; // Sprite du background

    sf::RectangleShape m_health; //Rectangle defissant le total de vie de l'ennemie
    sf::RectangleShape m_lostHealth; //Rectangle defissant la vie restante de l'ennemie
    sf::CircleShape m_btnEndTurn; //Bouton servant a mettre fin au tour du joueur

    Fight m_fight; //
    std::vector<Card*> m_hand; // Main du joueur

    void LoadHand(); // Permet de charger la main
    void DisplayPlayer(); //Affiche le joueur
    void DisplayHand(); //Affiche la main du joueur
};

#endif // STATE_GAME_H
