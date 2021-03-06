#include "State/State_Game.h"
//Constructeur
State_Game::State_Game(StateManager *l_stateManager) : BaseState(l_stateManager)
{
    //ctor
    Fight fight((Player *)m_stateMgr->GetContext()->m_entity);
    m_fight = fight;

    LoadHand();
    m_fight.createEnemies();
    srand((unsigned)time(0));
    m_egg = rand() % 100 + 1;
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
    m_text.setString("It's time for you to taste my foie gras !");
    m_text.setCharacterSize(15);

    //Permet de recuperer la taille de la fenetre par rapport au contexte
    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();

    //Permet de centrer et de positionner le texte
    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    m_text.setPosition(windowSize.x / 2.0f - 200, windowSize.y / 2.0f - 200);

    //Parametrage du bouton de fin de tour
    m_btnEndTurn.setPointCount(4); //Definition du nombre de points
    m_btnEndTurn.setPoint(0, sf::Vector2f(0, 0));
    m_btnEndTurn.setPoint(1, sf::Vector2f(150, 0));
    m_btnEndTurn.setPoint(2, sf::Vector2f(120, 50));
    m_btnEndTurn.setPoint(3, sf::Vector2f(30, 50));
    float btnX = 600;
    float btnY = 50;
    m_btnEndTurn.setPosition(btnX, btnY);
    //m_btnEndTurn.setOrigin(btnX/2.0f,btnY/2.0f);
    m_btnEndTurn.setFillColor(sf::Color(46, 132, 110));

    m_btnText.setFont(m_font);
    m_btnText.setString("End turn");
    m_btnText.setCharacterSize(12);
    sf::FloatRect btnRect = m_btnText.getLocalBounds();
    m_btnText.setOrigin(btnRect.left + btnRect.width / 2.0f, btnRect.top + btnRect.height / 2.0f);
    m_btnText.setPosition(btnX + 75, btnY + 25);

    //Permet d'afficher les indications liees aux points de vie
    m_healthTexture.loadFromFile("assets/indicator/heart.png");
    m_healthDisplay.setTexture(m_healthTexture);
    m_healthDisplay.setPosition(175, 75);
    m_healthDisplay.setScale(0.1, 0.1);

    m_healthValue.setFont(m_font);
    m_healthValue.setString(std::to_string(m_stateMgr->GetContext()->m_entity->getHealth()));
    m_healthValue.setCharacterSize(14);
    m_healthValue.setPosition(197.5, 95); //22.5 et 20

    //Permet d'afficher les indications liees aux points d'armure
    m_shieldTexture.loadFromFile("assets/indicator/shield.png");
    m_shieldDisplay.setTexture(m_shieldTexture);
    m_shieldDisplay.setPosition(225, 85);
    m_shieldDisplay.setScale(0.1, 0.1);

    m_shieldValue.setFont(m_font);
    m_shieldValue.setString(std::to_string(m_stateMgr->GetContext()->m_entity->getShield()));
    m_shieldValue.setCharacterSize(14);
    m_shieldValue.setPosition(240, 95);

    //Permet d'afficher les points d'action restant
    m_textCostPoints.setFont(m_font);
    Player* p = (Player *)m_stateMgr->GetContext()->m_entity;
    m_textCostPoints.setString(std::to_string(p->getActionPoints()));
    m_textCostPoints.setCharacterSize(18);
    m_textCostPoints.setPosition(175, 45);

    //Permet de creer les callbacks servant a gerer les events
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Game, "Key_Escape", &State_Game::Option, this);
    evMgr->AddCallback(StateType::Game, "Key_P", &State_Game::Pause, this);
    evMgr->AddCallback(StateType::Game, "Mouse_Left", &State_Game::MouseClick, this);
}
//Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet
void State_Game::OnDestroy()
{
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Game, "Key_Escape");
    evMgr->RemoveCallback(StateType::Game, "Key_P");
    evMgr->RemoveCallback(StateType::Game, "Mouse_Left");

    delete m_stateMgr->GetContext()->m_entity;
    m_stateMgr->GetContext()->m_entity = nullptr;
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
}
//Permet de dessiner les differents elements graphiques
void State_Game::Draw()
{
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_bgSprite);
    window->draw(m_text);
    window->draw(m_btnEndTurn);
    window->draw(m_btnText);

    m_healthDisplay.setPosition(175, 75);
    m_healthValue.setPosition(197.5, 95);
    m_healthValue.setString(std::to_string(m_stateMgr->GetContext()->m_entity->getHealth()));

    if (m_stateMgr->GetContext()->m_entity->getShield() > 0)
    {
        m_shieldValue.setString(std::to_string(m_stateMgr->GetContext()->m_entity->getShield()));
        m_healthDisplay.setPosition(150, 75);
        m_healthValue.setPosition(172.5, 95);
        window->draw(m_shieldDisplay);
        window->draw(m_shieldValue);
    }
    window->draw(m_healthDisplay);
    window->draw(m_healthValue);

    Player* p = (Player *)m_stateMgr->GetContext()->m_entity;
    m_textCostPoints.setString(std::to_string(p->getActionPoints()));
    window->draw(m_textCostPoints);

    DisplayPlayer();
    DisplayEnemy();
    DisplayHand();
    // LoadHand();
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
void State_Game::MouseClick(EventDetails *l_details)
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

    m_btnEndTurn.setFillColor(sf::Color(46, 132, 110));

    // Si on clique sur le bouton "End Turn"
    if (mousePos.x >= m_btnEndTurn.getPosition().x && mousePos.x <= m_btnEndTurn.getPosition().x + 150 && mousePos.y >= m_btnEndTurn.getPosition().y && mousePos.y <= m_btnEndTurn.getPosition().y + 50)
    {
        m_fight.endTurn();
        m_btnEndTurn.setFillColor(sf::Color::Red);
        LoadHand();

        if (m_fight.isGameOver())
        {
            m_stateMgr->SwitchTo(StateType::GameOver);
            m_fight.SetGameOver();
        }


    }

    // Si on clique sur une carte
    for (int i = 0; i < (int)m_hand.size(); ++i)
    {
        if (mousePos.x >= m_hand[i]->GetPosition().x - halfX && mousePos.x <= m_hand[i]->GetPosition().x + halfX && mousePos.y >= m_hand[i]->GetPosition().y - halfY && mousePos.y <= m_hand[i]->GetPosition().y + halfY)
        {
            // Si le joueur a assez de points d'actions
            if (m_fight.getPlayer().getActionPoints() >= m_hand[i]->getCostAction())
            {
                m_fight.useCard(*m_hand[i]);
                m_hand[i]->SetDraw(false);
                m_hand[i]->SetPosition(1500, 1500);
                LoadHand();
            }

            if(m_fight.isWon())
            {
                m_stateMgr->SwitchTo(StateType::Credits);
                m_fight.SetWon();
            }
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

    m_btnEndTurn.setFillColor(sf::Color(46, 132, 110));

    for (int i = 0; i < (int)m_hand.size(); ++i)
    {
        m_hand[i]->SetSpritePosition(cartBorder + cartWidth * i, cartHeight);
    }

    if (mousePos.x >= m_btnEndTurn.getPosition().x && mousePos.x <= m_btnEndTurn.getPosition().x + 150 && mousePos.y >= m_btnEndTurn.getPosition().y && mousePos.y <= m_btnEndTurn.getPosition().y + 50)
    {
        m_btnEndTurn.setFillColor(sf::Color(184, 213, 205));
    }

    for (int i = 0; i < (int)m_hand.size(); ++i)
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
    m_hand.clear();

    for (auto &&card : m_fight.getPlayerHand())
    {
        m_hand.push_back(card->clone());
    }

    //m_hand = m_fight.getPlayerHand();

    int cartHeight = 540;
    int cartWidth = 244;
    int cartBorder = 150;

    for (int i = 0; i < (int)m_hand.size(); ++i)
    {
        m_hand[i]->SetSpritePosition(cartBorder + cartWidth * i, cartHeight);
        m_hand[i]->SetContext(m_stateMgr->GetContext());
    }
}
//Permet de configurer et d'afficher le joueur
void State_Game::DisplayPlayer()
{

    m_fight.getPlayer().setContext(m_stateMgr->GetContext());

    if (m_egg > 5)
    {
        m_fight.getPlayer().setSprite("assets/player.png");
    }
    else
    {
        m_fight.getPlayer().setSprite("assets/player2.png");
        m_text.setString("I hope you like my facelift");
    }
    m_fight.getPlayer().setPosition(150, 200);
    m_fight.getPlayer().setSpriteScale(0.2, 0.2);
    m_fight.getPlayer().Draw();
}
//Permet d'afficher les cartes que l'on a en main
void State_Game::DisplayHand()
{
    for (int i = 0; i < (int)m_hand.size(); ++i)
    {
        m_hand[i]->Draw();
    }
}

void State_Game::DisplayEnemy()
{
    m_fight.getEnemy().setContext(m_stateMgr->GetContext());
    m_fight.getEnemy().setPosition(850, 125);
    //m_fight.getEnemy().setSprite("assets/enemies/hunter.png");
    m_fight.getEnemy().setSpriteScale(0.4, 0.4);
    m_fight.getEnemy().Draw();

    //Permet de catagoriser les rectangles servant d'indications quant a la vie de l'ennemie
    int lifeMaxEnemy = m_fight.getEnemy().getMaxLife();
    int lifeEnemy = m_fight.getRemainingLifeEnemy();
    m_health.setSize(sf::Vector2f(lifeMaxEnemy, 25));
    m_health.setFillColor(sf::Color::Red);
    m_lostHealth.setSize(sf::Vector2f(lifeEnemy, 25));
    m_lostHealth.setFillColor(sf::Color::Green);

    //Positionnement des rectangles de la vie de l'ennemie
    m_health.setPosition(950, 50);
    m_lostHealth.setPosition(950, 50);

    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_health);
    window->draw(m_lostHealth);
}
