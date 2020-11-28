#include "State/State_Intro.h"
State_Intro::State_Intro(StateManager *l_stateManager) : BaseState(l_stateManager)
{
    //ctor
}

State_Intro::~State_Intro()
{
    //dtor
}
void State_Intro::OnCreate()
{
    //Initialisation du temps a zero
    m_timePassed = 0.0f;
    //Recupere la valeur de la fenetre grace a l'heritage de BaseState et m_stateMgr
    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();
    //Chargement du sprite + parametrage
    m_introTexture.loadFromFile("assets/title_icon.png");
    m_introSprite.setTexture(m_introTexture);

    m_introSprite.setOrigin(m_introTexture.getSize().x / 2.0f, m_introTexture.getSize().y / 2.0f);

    m_introSprite.setPosition(windowSize.x / 2.0f, 0);

    //
    m_font.loadFromFile("assets/font/superboom.ttf");
    m_text.setFont(m_font);
    m_text.setString("Press SPACE to continue");
    m_text.setColor(sf::Color(239, 195, 46, 255));
    m_text.setCharacterSize(50);
    m_text.setOutlineColor(sf::Color(239, 200, 27, 255));
    m_text.setOutlineThickness(1.0f);
    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    m_text.setPosition(windowSize.x / 2.0f, windowSize.y - 50.0f);
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Intro, "Intro_Continue", &State_Intro::Continue, this);
}
//Vu qu'elle ne sera plus qu'a contenir de la memoire, nous allons liberer cette dite memoire
void State_Intro::OnDestroy()
{
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Intro, "Intro_Continue");
}

void State_Intro::Activate()
{
}

void State_Intro::Deactivate()
{
}

void State_Intro::Update(const sf::Time &l_time)
{
    m_timePassed += l_time.asSeconds();

    if (m_timePassed < 5.0f)
        m_introSprite.setPosition(m_introSprite.getPosition().x, m_introSprite.getPosition().y + (48 * l_time.asSeconds()));

    if ((int)m_timePassed % 10 != 0)
        m_text.setString("Press SPACE to continue");

    if ((int)m_timePassed % 10 == 0)
        m_text.setString("");
}

void State_Intro::Draw()
{
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_introSprite);
    if (m_timePassed >= 5.0f)
    {
        window->draw(m_text);
    }
}

void State_Intro::Continue(EventDetails *l_details)
{
    if (m_timePassed >= 5.0f)
    {
        m_stateMgr->SwitchTo(StateType::MainMenu);
        m_stateMgr->Remove(StateType::Intro);
    }
}
