#ifndef WINDOWS_H
#define WINDOWS_H
#include <string>
#include <SFML/Graphics.hpp>

class Window
{
    private:
        void SetUp(const std::string& l_title,const sf::Vector2u& l_size);
        void Destroy();
        void Create();

        sf::RenderWindow m_window;
        sf::Vector2u m_windowSize;
        std::string m_windowTitle;

        bool m_isDone;
        bool m_isFullscreen;
    public:
        //Constructeur par defaut
        Window();
        //Constructeur avec parametre
        Window(const std::string& l_title,const sf::Vector2u& l_size);
        //Destructeur
        virtual ~Window();

        void BeginDraw(); // Clear the window
        void EndDraw(); // Display the changes

        void Update();

        bool isDone();  //Permet de savoir si on a encore besoin de la fenetre ou non
        bool isFullscreen(); // Permet de savoir si nous sommes en fullscreen ou non
        sf::Vector2u GetWindowSize(); //Permet de retourner la taille de la fenetre

        void ToggleFullscreen();

        void Draw(sf::Drawable& l_drawable);
};

#endif // WINDOWS_H
