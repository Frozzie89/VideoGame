#include "State/State_Game.h"

State_Game::State_Game(StateManager* l_stateManager):BaseState(l_stateManager)
{
    //ctor
}

State_Game::~State_Game()
{
    //dtor
}

void State_Game::OnCreate()
{
    //Initialisation du temps a zero
    m_timePassed = 0.0f;
    //Recupere la valeur de la fenetre grace a l'heritage de BaseState et m_stateMgr
    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();
    //Chargement du sprite + parametrage
    m_introTexture.loadFromFile("Chapitre5.jpg");
    m_introSprite.setTexture(m_introTexture);

    m_introSprite.setOrigin(m_introTexture.getSize().x/2.0f,m_introTexture.getSize().y/2.0f);

    m_introSprite.setPosition(windowSize.x/2.0f,0);

    //
    m_font.loadFromFile("superboom.ttf");
    m_text.setFont(m_font);
    m_text.setString(" Press SPACE to continue");
    m_text.setCharacterSize(15);
    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    m_text.setPosition(windowSize.x/2.0f,windowSize.y/2.0f);
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    //evMgr->AddCallback(StateType::Game,"Intro_Continue",&State_Intro::Continue,this);

}

void State_Game::OnDestroy()
{
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Intro,"Intro_Continue");
}

void State_Game::Activate()
{

}

void State_Game::Deactivate()
{

}

void State_Game::Update(const sf::Time& l_time)
{
    if(m_timePassed < 5.0f)
    {
        m_timePassed +=l_time.asSeconds();
        m_introSprite.setPosition(m_introSprite.getPosition().x,m_introSprite.getPosition().y +(48*l_time.asSeconds()));
    }
}

void State_Game::Draw()
{
    sf::RenderWindow* window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_introSprite);
    if(m_timePassed>=5.0f)
    {
        window->draw(m_text);
    }
}
