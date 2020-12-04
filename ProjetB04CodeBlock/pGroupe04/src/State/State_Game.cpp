#include "State/State_Game.h"
//Constructeur
State_Game::State_Game(StateManager *l_stateManager) : BaseState(l_stateManager)
{
    //ctor
    Fight fight((Player*)m_stateMgr->GetContext()->m_entity);
    m_fight = fight;

    std::cout<<m_fight.getPlayer().getClassName()<<std::endl;
    LoadHand();

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
    m_bgSprite.setScale(1.08,1.16);

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
    m_text.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

    //Permet de catagoriser les rectangles servant d'indications quant a la vie de l'ennemie
    m_health.setSize(sf::Vector2f(100,25));
    m_health.setFillColor(sf::Color::Red);
    m_lostHealth.setSize(sf::Vector2f(75,25));
    m_lostHealth.setFillColor(sf::Color::Green);

    //Positionnement des rectangles de la vie de l'ennemie
    m_health.setPosition(900,50);
    m_lostHealth.setPosition(900,50);

    //Permet de creer les callbacks servant a gerer les events
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Game,"Key_Escape",&State_Game::Option,this);
    evMgr->AddCallback(StateType::Game,"Key_P",&State_Game::Pause,this);
    evMgr->AddCallback(StateType::Game,"Click_Left",&State_Game::CardClick,this);
}
//Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet
void State_Game::OnDestroy()
{
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Game,"Key_Escape");
    evMgr->RemoveCallback(StateType::Game,"Key_P");
    evMgr->RemoveCallback(StateType::Game,"Click_Left");
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
//    Player* player = m_stateMgr->GetContext()->m_player;
    //LoadHand();

}
//Permet de dessiner les differents elements graphiques
void State_Game::Draw()
{
    std::cout<<"Debut Draw"<<std::endl;
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_bgSprite);
    std::cout<<"Bg OK"<<std::endl;
    /*
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
    e.Draw();*/

    int cartHeight = 420;
    int cartWidth = 244;
    int cartBorder = 65;

    for(int i=0; i<m_hand.size();++i)
    {
        std::cout<<"Debut For"<<std::endl;
        //std::cout<<m_hand[i]->str()<<std::endl;

        m_hand[i]->SetSpritePosition(cartBorder+cartWidth*i,cartHeight);

    //m_hand[i]->Draw();
    }

}
//Permet de switcher vers le State option, et donc la "fenetre" d'option
void State_Game::Option(EventDetails* l_details)
{
    m_stateMgr->SwitchTo(StateType::Option);
}
//Permet de switcher vers le State Pause, et donc la "fenetre" de pause
void State_Game::Pause(EventDetails* l_details)
{
    m_stateMgr->SwitchTo(StateType::Paused);
}
//Permet de cliquer sur les cartes et effectuer l'action qui en decoule
void State_Game::CardClick(EventDetails* l_details)
{

}

void State_Game::LoadHand()
{
    /*vector<Card*> tmp = m_fight.getPlayerHand();
    for(int i =0; i<= tmp.size();++i)
    {
        std::cout<<"Auto Hand"<<std::endl;
        std::cout<<tmp[i]->str()<<std::endl;
        m_hand[i].push_back(&tmp[i]);
    }*/
    m_hand = m_fight.getPlayerHand();
    std::cout<<"Load Card OK"<<std::endl;
    for(int i =0; i<m_hand.size();++i)
    {
        std::cout<<"Carte "<<std::to_string(i)<<std::endl;
        std::cout<<"-------"<<std::endl;
        std::cout<<m_hand[i]->str()<<std::endl;
    }
}
