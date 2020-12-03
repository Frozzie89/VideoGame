#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Window.h"
#include "StateManager.h"
#include "SharedContext.h"
#include "State/StateType.h"

/*
    Cette classe va permettre de definir le comportement de notre jeu
    Elle comprend une fenetre personalisee, des arguments permettant de limiter le nombre de fps du jeu (un objet Clock ainsi qu'un objet Time),
    un type de state, un manager de state ainsi qu'un contexte
*/
class Game
{
private:
    Window m_window; //Fenetre du jeu actuel
    sf::Clock m_clock;
    sf::Time m_elapsed;

    StateType m_state; //Type d'etat
    StateManager m_stateManager; //Manager de state
    SharedContext m_context; // Contexte

public:
    Game();          //Constructeur
    virtual ~Game(); //Destructeur

    void HandleInput();    //Gestionnaire des events inputs tel que le clavier ou la souris
    void Update();         //Permet de mettre a jour la classe
    void Render();         // Permet d'afficher les elements
    Window *GetWindow();   //Permet de recuperer la fenetre
    sf::Time GetElapsed(); //Permet de recuperer m_elapsed
    void RestartClock();   //Permet de restart m_eclapsed et d'obtenir 60FPS

    void LateUpdate(); //Permet d'obtenir 60FPS et de supprimer les etats dont on n'a plus besoin

    SharedContext* GetContext(); //Retourne le contexte

protected:
};

#endif // GAME_H
