#include "Window.h"
//Constructeur par defaut
Window::Window()
{
    //ctor
    SetUp("Window", sf::Vector2u(640, 480));
}
/*Constructeur avec parametres
    l_title -> Le titre de l'écran || l_size -> La taille de l'écran
*/
Window::Window(const std::string &l_title, const sf::Vector2u &l_size)
{
    SetUp(l_title, l_size);
}
/* Destructeur
    Destroy -> sert à fermer la fenetre
*/
Window::~Window()
{
    //dtor
    Destroy();
}
/* Sert à initialiser le constructeur
    m_windowTitle/l_title -> Le titre de la fenetre || m_windowSize/l_size -> La taille de la fenetre
    m_isFullscreen -> Indique si on est en fullscreen ou non || m_isDone -> sert à savoir si on en a fini avec la fenetre
    On fait appel a la methode Create pour creer la fenetre
*/
void Window::SetUp(const std::string &l_title, const sf::Vector2u &l_size)
{
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullscreen = false;
    m_isDone = false;
    Create();
    //Ajout suit à l'implementation de EventManager
    m_isFocused = true;
    m_eventManager.AddCallback(m_eventManager.GetCurrentState(), "Fullscreen_toggle", &Window::ToggleFullscreen, this);
    m_eventManager.AddCallback(m_eventManager.GetCurrentState(), "Window_close", &Window::Close, this);
}
// Sert a fermer la fenetre
void Window::Destroy()
{
    m_window.close();
}
/*Sert a creer la fenetre et ajuster son affichage
    style -> Enum definissant le style de fenetre.
        En fullscreen, la fenetre prend l'ensemble de l'ecran.
        En default, elle possede une barre de titre, des bordures extensibles,un bouton de fermeture et peut aussi se maximiser à la taille de l'écran
    create({int x,int y,int profondeur},string title,auto style) -> Permet de créer la fenetre
        x -> longueur de la fenetre || y -> largeur de la fenetre || profondeur -> profondeur de la fenetre
        title -> titre de la fenetre || style -> style de la fenetre
*/
void Window::Create()
{
    auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default); //----> LE DEMON !!!!
    m_window.create({m_windowSize.x,
                     m_windowSize.y,
                     32},
                    m_windowTitle,
                    style);

}
// Nettoie la fenetre
void Window::BeginDraw()
{
    m_window.clear(sf::Color::Black);
}
// Affiche les changements
void Window::EndDraw()
{
    m_window.display();
}
/*Permet de definir les differents types de changements en fonction des evenements
    Si on appuie sur le bouton close -> Passage à m_isDone a true et donc Fermeture de la fenetre
    Si on appuie sur F5, passage en fullscreen et inversement
*/
void Window::Update()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::LostFocus)
        {
            m_isFocused = false;
            m_eventManager.SetFocus(false);
        }
        else if (event.type == sf::Event::GainedFocus)
        {
            m_isFocused = true;
            m_eventManager.SetFocus(true);
        }
        else if (event.type == sf::Event::Closed)
        {
            Close();
        }
        else if(event.type == event.MouseButtonReleased && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_window.setKeyRepeatEnabled(false);
        }
        m_eventManager.HandleEvent(event);
    }
    m_eventManager.Update();
}
// Retourne la valeur isDone, valeur qui permet de savoir si on en a fini avec la fenetre. Si oui, on la detruit
bool Window::isDone()
{
    return m_isDone;
}
// Retourne la valeur isFullscreen qui permet de savoir si la fenetre est en fullscreeen ou non
bool Window::isFullscreen()
{
    return m_isFullscreen;
}
// Retourne un vector2u comprenant la longueur et la largeur de la fenetre
sf::Vector2u Window::GetWindowSize()
{
    return m_windowSize;
}
// Retourne la fenetre
sf::RenderWindow *Window::GetRenderWindow()
{
    return &m_window;
}
// Permet de switcher entre le fullscreen et un affichage plus classique
void Window::ToggleFullscreen()
{
    m_isFullscreen = !m_isFullscreen;
    Destroy();
    Create();
}
//Permet de dessiner un element drawable dans la fenetre
void Window::Draw(sf::Drawable &l_drawable)
{
    m_window.draw(l_drawable);
}
bool Window::isFocused()
{
    return m_isFocused;
}

EventManager *Window::GetEventManager()
{
    return &m_eventManager;
}

void Window::ToggleFullscreen(EventDetails *l_details)
{
}

void Window::Close(EventDetails *l_details)
{
    m_isDone = true;
}
