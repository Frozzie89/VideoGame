#ifndef WINDOWS_H
#define WINDOWS_H

#include <string>
#include <SFML/Graphics.hpp>
#include "EventManager.h"
/*
    Cette classe va permettre de definir la fenetre de notre jeu
    Parmi ses arguments, on va retrouver un objet fenetre, un vecteur qui renverra la taille de la fenetre, une chaine de caractere qui nous
    servira comme titre de la fenetre ainsi que differents parametres booleans tel que le fait de savoir si on a encore besoin de la fenetre,
    si nous sommes en fullscreen ou si on focus ainsi qu'un event manager
*/
class Window
{
private:
    void SetUp(const std::string &l_title, const sf::Vector2u &l_size); //Sert à initialiser le constructeur
    void Destroy(); // Sert a fermer la fenetre
    void Create(); //Sert a creer la fenetre et ajuster son affichage

    sf::RenderWindow m_window; //L'objet fenetre generique de sfml
    sf::Vector2u m_windowSize; //La taille de la fenetre
    std::string m_windowTitle; //Le titre de la fenetre

    bool m_isDone; //Permet de savoir si on a encore besoin de la fenetre
    bool m_isFullscreen; //Permet de savoir si on est en fullscreen ou non

    //Addition lie a EventManager
    EventManager m_eventManager; //Manager d'event
    bool m_isFocused; // Permet de savoir si on focus ou non

public:
    Window(); //Constructeur par defaut
    Window(const std::string &l_title, const sf::Vector2u &l_size); //Constructeur avec parametres
    virtual ~Window(); //Destructeur

    void BeginDraw(); // Nettoie la fenetre
    void EndDraw();   // Affiche les changements

    void Update(); //Permet de definir les differents types de changements en fonction des evenements

    bool isDone(); // Retourne la valeur isDone, valeur qui permet de savoir si on en a fini avec la fenetre. Si oui, on la detruit
    bool isFullscreen();
    sf::Vector2u GetWindowSize(); //Permet de savoir si nous sommes en fullscreen ou non
    sf::RenderWindow *GetRenderWindow(); //Permet de recuperer l'objet fenetre

    void ToggleFullscreen(); // Permet de switcher entre le fullscreen ou le mode normal

    void Draw(sf::Drawable &l_drawable); //Permet de dessiner sur la fenetre un element qui peut l'etre

    //Addition lie a EventManager
    bool isFocused(); //Permet de savoir si on focus ou non
    EventManager *GetEventManager(); //retourne le manager d'event
    void ToggleFullscreen(EventDetails *l_details);
    void Close(EventDetails *l_details = nullptr); //Permet d'indiquer que l'on n'a plus besoin de la fenetre
};

#endif // WINDOWS_H
