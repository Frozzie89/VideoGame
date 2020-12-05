#ifndef STATE_GAME_H
#define STATE_GAME_H

#include <SFML/Graphics.hpp>

#include <stdlib.h>
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
private:
    sf::Font m_font; //Police du texte affiche
    sf::Text m_text; //Texte que l'on va afficher
    float m_timePassed; //Temps passe sur le state
    sf::Texture m_bgTexture; // Texture du background
    sf::Sprite m_bgSprite; // Sprite du background

    sf::RectangleShape m_health; //Rectangle defissant le total de vie de l'ennemie
    sf::RectangleShape m_lostHealth; //Rectangle defissant la vie restante de l'ennemie
    sf::ConvexShape m_btnEndTurn; //Bouton servant a mettre fin au tour du joueur
    sf::Text m_btnText; // Texte du bouton
    sf::Texture m_shieldTexture; //Permet de charger la texture de l'indicateur d'armure du joueur
    sf::Sprite m_shieldDisplay; // Permet de créer un element pour contenir le nombre de points d'armure du joueur
    sf::Text m_shieldValue; //Affiche le nombre de points d'armure du joueur
    sf::Texture m_healthTexture; //Permet de charger la texture de l'indicateur de vie du joueur
    sf::Sprite m_healthDisplay; // Permet de créer un element pour contenir le nombre de points de vie du joueur
    sf::Text m_healthValue; //Affiche le nombre de points d'armure du joueur

    Fight m_fight; //
    std::vector<Card*> m_hand; // Main du joueur

    void LoadHand(); //Permet de recuperer les cartes en mains et de configurer leur affichage
    void DisplayPlayer(); //Permet de configurer et d'afficher le joueur
    void DisplayHand(); //Permet d'afficher les cartes que l'on a en main
    void DisplayEnemy(); //Permet d'afficher l'ennemie

    int m_egg;

    void MouseClick(EventDetails* l_details); //Permet de cliquer sur les cartes et effectuer l'action qui en decoule
    void MouseHover(); //Permet de gerer les events lies au survols des elements par la souris

public:
    State_Game(StateManager *l_stateManager); //Constructeur
    virtual ~State_Game();                    //Destructeur

    void OnCreate();  //Permet de creer les differents elements graphiques que l'on va retrouver dans la fenetre
    void OnDestroy(); //Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet

    void Activate();   //Methode qui d'activer certaines modifications si la state a deja ete utilisee
    void Deactivate(); //Permet de supprimer les modifications si la state n'est plus utilisee

    void Update(const sf::Time &l_time); //Met a jour ce qui est a l'ecran
    void Draw();                         //Permet de dessiner les differents elements graphiques

    void Option(EventDetails *l_details); //Permet de switcher vers le State option, et donc la "fenetre" d'option
    void Pause(EventDetails *l_details);  //Permet de switcher vers le State Pause, et donc la "fenetre" de pause


};

#endif // STATE_GAME_H
