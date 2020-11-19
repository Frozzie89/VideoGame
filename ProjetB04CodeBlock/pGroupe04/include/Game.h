#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Window.h"

class Game
{
    private:
        Window m_window;    //Fenetre du jeu actuel
        sf::Texture m_texturePicture;   //Texture d'un element
        sf::Sprite m_picture;   // Sprite d'un element
        sf::Clock m_clock;
        sf::Time m_elapsed;

    public:

        Game(); //Constructeur
        virtual ~Game(); //Destructeur

        void HandleInput(); //Gestionnaire des events inputs tel que le clavier ou la souris
        void Update();  //Permet de mettre a jour la classe
        void Render();  // Permet d'afficher les elements
        Window* GetWindow();    //Permet de recuperer la fenetre
        sf::Time GetElapsed();  //Permet de recuperer m_elapsed
        void RestartClock(); //Permet de restart m_eclapsed et d'obtenir 60FPS

    protected:

};

#endif // GAME_H
