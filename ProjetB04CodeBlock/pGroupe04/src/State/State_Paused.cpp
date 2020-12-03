#include "State/State_Paused.h"
//Constructeur
State_Paused::State_Paused(StateManager* l_stateManager) : BaseState(l_stateManager)
{

}
//Destructeur
State_Paused::~State_Paused()
{

}
//Permet de creer les differents elements graphiques que l'on va retrouver dans la fenetre
void State_Paused::OnCreate()
{
    SetTransparent(true);
    m_font.loadFromFile("assets/font/superboom.ttf");
    m_text.setFont(m_font);
    m_text.setString(sf::String("PAUSED"));
    m_text.setCharacterSize(14);
    m_text.setStyle(sf::Text::Bold);

    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();

    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width /2.0f, textRect.top+textRect.height/2.0f);
    m_text.setPosition(windowSize.x/2.0f,windowSize.y/2.0f);

    m_rect.setSize(sf::Vector2f(windowSize));
    m_rect.setPosition(0,0);
    m_rect.setFillColor(sf::Color(0,0,0,150));

    EventManager* evMgr =m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Paused,"Key_P",&State_Paused::Unpause,this);
}
//Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet
void State_Paused::OnDestroy()
{
    EventManager* evMgr =m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Paused,"Key_P");
}
//Methode qui d'activer certaines modifications si la state a deja ete utilisee
void State_Paused::Activate()
{

}
//Permet de supprimer les modifications si la state n'est plus utilisee
void State_Paused::Deactivate()
{

}
//Met a jour ce qui est a l'ecran
void State_Paused::Update(const sf::Time& l_time)
{

}
//Permet de dessiner les differents elements graphiques
void State_Paused::Draw()
{
    sf::RenderWindow* window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_rect);
    window->draw(m_text);
}
//Permet de reprendre le jeu et switcher de state pour le state Game
void State_Paused::Unpause(EventDetails* l_details)
{
    m_stateMgr->SwitchTo(StateType::Game);
}
