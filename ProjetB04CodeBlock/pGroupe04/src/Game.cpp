#include "Game.h"
/* Constructeur de Game
    m_window -> creation de la fenetre contenant le jeu (Window(Title,Size)) ----> Title : Titre de la fenetre || Size : Dimension de la fenetre
    On va ensuite instancier notre sprite en passant par le chargement de sa texture
*/
Game::Game() : m_window("Duck the issue !", sf::Vector2u(1280, 720)), m_stateManager(&m_context)
{
    //ctor
    m_context.m_wind = &m_window;
    m_context.m_eventManager = m_window.GetEventManager();
    m_stateManager.SwitchTo(StateType::Intro);
}
//Destructeur
Game::~Game()
{
    //dtor
}
// Sert à gerer les events tel que la gestion du clavier ou de la souris
void Game::HandleInput()
{
}
/* Sert a mettre a jour la position du sprite
    appel a la methode Update de Window
    appel a la methode movePicture
*/
void Game::Update()
{
    m_window.Update();
    m_stateManager.Update(m_elapsed);
}
//Permet d'afficher des elements
void Game::Render()
{
    m_window.BeginDraw();  // Ou clear
    m_stateManager.Draw(); // Dessine le sprite
    m_window.EndDraw();    // Display
}
// Permet de recuperer la fenetre
Window *Game::GetWindow()
{
    return &m_window;
}
//Retourne m_elapsed
sf::Time Game::GetElapsed()
{
    return m_elapsed;
}
//Permet de restart m_eclapsed et d'obtenir 60FPS
void Game::RestartClock()
{
    m_elapsed += m_clock.restart();
    float frametime = 1.0F / 60.0F;
    if (m_elapsed.asSeconds() >= frametime)
    {
        m_elapsed -= sf::seconds(frametime);
    }
}
//Permet d'obtenir 60FPS et de supprimer les etats dont on n'a plus besoin
void Game::LateUpdate()
{
    m_stateManager.ProcessRequests();
    RestartClock();
}
//Retourne le contexte
SharedContext* Game::GetContext()
{
    return &m_context;
}
