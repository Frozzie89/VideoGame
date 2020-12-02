#include "State/State_Game.h"

State_Game::State_Game(StateManager *l_stateManager) : BaseState(l_stateManager)
{
    //ctor
    m_health.setSize(sf::Vector2f(100,25));
    m_health.setFillColor(sf::Color::Red);
    m_lostHealth.setSize(sf::Vector2f(75,25));
    m_lostHealth.setFillColor(sf::Color::Green);

    m_health.setPosition(900,50);
    m_lostHealth.setPosition(900,50);
}

State_Game::~State_Game()
{
    //dtor
}

void State_Game::OnCreate()
{
    m_bgTexture.loadFromFile("assets/background.png");
    m_bgSprite.setTexture(m_bgTexture);
    m_bgSprite.setScale(1.08,1.16);

    m_font.loadFromFile("assets/font/superboom.ttf");
    m_text.setFont(m_font);
    //m_text.setString("Ceci est un jeu je vous l'assure");
    m_text.setString("Je pensais qu'on etait frere DONALD !\n C'est l'heure pour toi de gouter a mon foi !");
    m_text.setCharacterSize(15);

    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();

    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    m_text.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Game,"Key_Escape",&State_Game::Option,this);
    evMgr->AddCallback(StateType::Game,"Key_P",&State_Game::Pause,this);
    evMgr->AddCallback(StateType::Game,"Click_Left",&State_Game::CardClick,this);
}

void State_Game::OnDestroy()
{
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Game,"Key_Escape");
    evMgr->RemoveCallback(StateType::Game,"Key_P");
    evMgr->RemoveCallback(StateType::Game,"Click_Left");
}

void State_Game::Activate()
{
}

void State_Game::Deactivate()
{
}

void State_Game::Update(const sf::Time &l_time)
{
//    Player* player = m_stateMgr->GetContext()->m_player;

}

void State_Game::Draw()
{
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_bgSprite);

    window->draw(m_text);
    int i=1;
    DefensiveCardWarrior dcw("Coucou", "assets/cards/Warrior/attack/fistOfTheDuck.png", 0, 0,m_stateMgr->GetContext(), true);
    //++i;
    DefensiveCardWarrior dcw1("Coucou", "assets/cards/Warrior/shield/block.png", 0, 0,m_stateMgr->GetContext(), true);
    //++i;
    DefensiveCardWarrior dcw2("Coucou", "assets/cards/Warrior/attack/thorHammer.png" , 0, 0,m_stateMgr->GetContext(), true);
    //++i;
    DefensiveCardWarrior dcw3("Coucou", "assets/cards/Warrior/shield/goldenPlates.png", 0, 0,m_stateMgr->GetContext(), true);
    //++i;
    DefensiveCardWarrior dcw4("Coucou", "assets/cards/Warrior/heal/takeNap.png", 0, 0,m_stateMgr->GetContext(), true);

    Enemy e;
    e.setContext(m_stateMgr->GetContext());
    e.setSprite("enemy.png");
    e.setPosition(850,100);
    e.Draw();

    Warrior w;
    w.setContext(m_stateMgr->GetContext());
    w.setSprite("assets/player.png");
    w.setPosition(150,150);
    w.setSpriteScale(0.3,0.3);
    w.Draw();

    window->draw(m_health);
    window->draw(m_lostHealth);

    int cartHeight = 420;
    int cartWidth = 244;
    int cartBorder = 65;
    dcw.SetSpritePosition(cartBorder,cartHeight);
    dcw1.SetSpritePosition(cartBorder+cartWidth,cartHeight);
    dcw2.SetSpritePosition(cartBorder+cartWidth*2,cartHeight);
    dcw3.SetSpritePosition(cartBorder+cartWidth*3,cartHeight);
    dcw4.SetSpritePosition(cartBorder+cartWidth*4,cartHeight);
    dcw.Draw();
    dcw1.Draw();
    dcw2.Draw();
    dcw3.Draw();
    dcw4.Draw();
    e.Draw();
}

void State_Game::Option(EventDetails* l_details)
{
    m_stateMgr->SwitchTo(StateType::Option);
}

void State_Game::Pause(EventDetails* l_details)
{
    m_stateMgr->SwitchTo(StateType::Paused);
}

void State_Game::CardClick(EventDetails* l_details)
{

}
