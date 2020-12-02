#include "State/State_Game.h"

State_Game::State_Game(StateManager *l_stateManager) : BaseState(l_stateManager)
{
    //ctor
}

State_Game::~State_Game()
{
    //dtor
}

void State_Game::OnCreate()
{
    m_font.loadFromFile("assets/font/superboom.ttf");
    m_text.setFont(m_font);
    m_text.setString("Ceci est un jeu je vous l'assure");
    m_text.setCharacterSize(15);

    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();

    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    m_text.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Game,"Key_Escape",&State_Game::MainMenu,this);
    evMgr->AddCallback(StateType::Game,"Key_P",&State_Game::Pause,this);
}

void State_Game::OnDestroy()
{
   EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Game,"Key_Escape");
    evMgr->RemoveCallback(StateType::Game,"Key_P");
}

void State_Game::Activate()
{
}

void State_Game::Deactivate()
{
}

void State_Game::Update(const sf::Time &l_time)
{

}

void State_Game::Draw()
{
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();

    window->draw(m_text);

}

void State_Game::MainMenu(EventDetails* l_details)
{
    m_stateMgr->SwitchTo(StateType::MainMenu);
}

void State_Game::Pause(EventDetails* l_details)
{
    m_stateMgr->SwitchTo(StateType::Paused);
}
