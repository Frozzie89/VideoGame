#include "State/State_Game.h"
//Constructeur
State_Game::State_Game(StateManager *l_stateManager) : BaseState(l_stateManager)
{
    //ctor
    Fight fight((Player *)m_stateMgr->GetContext()->m_entity);
    m_fight = fight;

    std::cout << m_fight.getPlayer().getClassName() << std::endl;
    LoadHand();
    m_fight.createEnemies();
    srand((unsigned)time(0));
    m_egg = rand() %100 +1;
}
//Destructeur
State_Game::~State_Game()
{
    //dtor
}
//Permet de creer les differents elements graphiques que l'on va retrouver dans la fenetre
void State_Game::OnCreate()
{
    //Initialisation du background
    m_bgTexture.loadFromFile("assets/background.png");
    m_bgSprite.setTexture(m_bgTexture);
    m_bgSprite.setScale(1.08, 1.16);

    //Initialisation des textes a l'ecran
    m_font.loadFromFile("assets/font/superboom.ttf");
    m_text.setFont(m_font);
    //m_text.setString("Ceci est un jeu je vous l'assure");
    m_text.setString("Je pensais qu'on etait frere DONALD !\n C'est l'heure pour toi de gouter a mon foi !");
    m_text.setCharacterSize(15);

    //Permet de recuperer la taille de la fenetre par rapport au contexte
    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();

    //Permet de centrer et de positionner le texte
    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    m_text.setPosition(windowSize.x / 2.0f -200, windowSize.y / 2.0f - 200);

    //Permet de creer les callbacks servant a gerer les events
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Game, "Key_Escape", &State_Game::Option, this);
    evMgr->AddCallback(StateType::Game, "Key_P", &State_Game::Pause, this);
    evMgr->AddCallback(StateType::Game, "Mouse_Left", &State_Game::CardClick, this);
    evMgr->AddCallback(StateType::Game, "Mouse_Left", &State_Game::CardClick, this);
}
//Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet
void State_Game::OnDestroy()
{
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Game, "Key_Escape");
    evMgr->RemoveCallback(StateType::Game, "Key_P");
    evMgr->RemoveCallback(StateType::Game, "Mouse_Left");
}
//Methode qui d'activer certaines modifications si la state a deja ete utilisee
void State_Game::Activate()
{
}
//Permet de supprimer les modifications si la state n'est plus utilisee
void State_Game::Deactivate()
{
}
//Met a jour ce qui est a l'ecran
void State_Game::Update(const sf::Time &l_time)
{
    MouseHover();
    //    Player* player = m_stateMgr->GetContext()->m_player;
    //LoadHand();
}
//Permet de dessiner les differents elements graphiques
void State_Game::Draw()
{
    //std::cout<<"Debut Draw"<<std::endl;
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_bgSprite);
    window->draw(m_text);
    DisplayPlayer();
    DisplayHand();
    DisplayEnemy();

}
//Permet de switcher vers le State option, et donc la "fenetre" d'option
void State_Game::Option(EventDetails *l_details)
{
    m_stateMgr->SwitchTo(StateType::Option);
}
//Permet de switcher vers le State Pause, et donc la "fenetre" de pause
void State_Game::Pause(EventDetails *l_details)
{
    m_stateMgr->SwitchTo(StateType::Paused);
}
//Permet de cliquer sur les cartes et effectuer l'action qui en decoule
void State_Game::CardClick(EventDetails *l_details)
{
    if (!m_fight.isPlayerTurn())
        return;

    //Recupere la position de souris par rapport a l'eventDetail
    sf::Vector2i mousePos = l_details->m_mouse;

    //Si la position vaut 0 dans les deux axes, on va reprendre la fenetre a partir du statemanager et recuperer la position de la souris a partir de la
    if (mousePos.x == 0 && mousePos.y == 0)
    {
        sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
        mousePos = sf::Mouse::getPosition(*window);
    }

    int halfX = 122;
    int halfY = 180;
    std::cout << std::to_string(mousePos.x) << std::endl;
    for (int i = 0; i < m_hand.size(); ++i)
    {
        if (mousePos.x >= m_hand[i]->GetPosition().x - halfX && mousePos.x <= m_hand[i]->GetPosition().x + halfX && mousePos.y >= m_hand[i]->GetPosition().y - halfY && mousePos.y <= m_hand[i]->GetPosition().y + halfY)
        {
            m_fight.useCard(*m_hand[i]);
            m_hand[i]->SetDraw(false);
            m_hand[i]->SetPosition(1500, 1500);
        }
    }
}

void State_Game::MouseHover()
{
    if (!m_fight.isPlayerTurn())
        return;

    //Recupere la fenetre de stateManager ainsi que la position de la souris sur la fenetre
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    int cartHeight = 540;
    int cartWidth = 244;
    int cartBorder = 150;

    float halfX = 122;
    float halfY = 180;

    for (int i = 0; i < m_hand.size(); ++i)
    {
        m_hand[i]->SetSpritePosition(cartBorder + cartWidth * i, cartHeight);
    }

    for (int i = 0; i < m_hand.size(); ++i)
    {
        if (mousePos.x >= m_hand[i]->GetPosition().x - halfX && mousePos.x <= m_hand[i]->GetPosition().x + halfX && mousePos.y >= m_hand[i]->GetPosition().y - halfY && mousePos.y <= m_hand[i]->GetPosition().y + halfY)
        {
            m_hand[i]->SetSpritePosition(cartBorder + cartWidth * i, cartHeight - 50);
        }
    }
}
//Permet de recuperer les cartes en mains et de configurer leur affichage
void State_Game::LoadHand()
{
    m_hand = m_fight.getPlayerHand();

    int cartHeight = 540;
    int cartWidth = 244;
    int cartBorder = 150;

    for (int i = 0; i < m_hand.size(); ++i)
    {
        m_hand[i]->SetSpritePosition(cartBorder + cartWidth * i, cartHeight);
        m_hand[i]->SetContext(m_stateMgr->GetContext());
    }
}
//Permet de configurer et d'afficher le joueur
void State_Game::DisplayPlayer()
{
    m_fight.getPlayer().setContext(m_stateMgr->GetContext());

    if(m_egg > 5)
    {
        m_fight.getPlayer().setSprite("assets/player.png");
    }
    else{
        m_fight.getPlayer().setSprite("assets/player2.png");
        m_text.setString("J'espere que tu aimes mon lifting !");
    }
    m_fight.getPlayer().setPosition(150,200);
    m_fight.getPlayer().setSpriteScale(0.2,0.2);
    m_fight.getPlayer().Draw();
}
//Permet d'afficher les cartes que l'on a en main
void State_Game::DisplayHand()
{
    for (int i = 0; i < m_hand.size(); ++i)
    {
        m_hand[i]->Draw();
    }
}

void State_Game::DisplayEnemy()
{
    m_fight.getEnemy().setContext(m_stateMgr->GetContext());
    m_fight.getEnemy().setPosition(850,125);
    //m_fight.getEnemy().setSprite("assets/enemies/hunter.png");
    m_fight.getEnemy().setSpriteScale(0.4,0.4);
    m_fight.getEnemy().Draw();

    //Permet de catagoriser les rectangles servant d'indications quant a la vie de l'ennemie
    m_health.setSize(sf::Vector2f(100,25));
    m_health.setFillColor(sf::Color::Red);
    m_lostHealth.setSize(sf::Vector2f(75,25));
    m_lostHealth.setFillColor(sf::Color::Green);

    //Positionnement des rectangles de la vie de l'ennemie
    m_health.setPosition(950,50);
    m_lostHealth.setPosition(950,50);

    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_health);
    window->draw(m_lostHealth);

}
