#include "State/State_Intro.h"
//Constructeur
State_Intro::State_Intro(StateManager *l_stateManager) : BaseState(l_stateManager)
{
    //ctor
}
//Destructeur
State_Intro::~State_Intro()
{
    //dtor
}
//Permet de creer les differents elements graphiques que l'on va retrouver dans la fenetre
void State_Intro::OnCreate()
{
    //Initialisation du temps a zero
    m_timePassed = 0.0f;
    //Recupere la valeur de la fenetre grace a l'heritage de BaseState et m_stateMgr
    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();
    //Chargement du sprite + parametrage
    m_introTexture.loadFromFile("assets/title_icon.png");
    m_introTexture.setSmooth(true);
    m_introSprite.setTexture(m_introTexture);
    m_introSprite.setOrigin(m_introTexture.getSize().x / 2.0f, m_introTexture.getSize().y / 2.0f);
    m_introSprite.setPosition(windowSize.x / 2.0f, 0);

    //Parametrage de la police d'ecriture et des zones de textes
    m_font.loadFromFile("assets/font/superboom.ttf");

    m_indication.setFont(m_font);
    m_indication.setString(sf::String("Press SPACE to continue"));
    m_indication.setFillColor(sf::Color(239, 195, 46, 255));
    m_indication.setCharacterSize(50);
    m_indication.setOutlineColor(sf::Color(239, 150, 27, 255));
    m_indication.setOutlineThickness(1.0f);

    m_title.setFont(m_font);
    m_title.setString(sf::String("Duck The Issue"));
    m_title.setFillColor(sf::Color(239, 195, 46, 255));
    m_title.setCharacterSize(50);
    m_title.setOutlineColor(sf::Color(239, 150, 27, 255));
    m_title.setOutlineThickness(1.0f);

    sf::FloatRect textRectInfication = m_indication.getLocalBounds();
    m_indication.setOrigin(textRectInfication.left + textRectInfication.width / 2.0f, textRectInfication.top + textRectInfication.height / 2.0f);
    m_indication.setPosition(windowSize.x / 2.0f, windowSize.y - 50.0f);

    sf::FloatRect textRectTitle = m_title.getLocalBounds();
    m_title.setOrigin(textRectTitle.left + textRectTitle.width / 2.0f, textRectTitle.top + textRectTitle.height / 2.0f);
    m_title.setPosition(windowSize.x / 2.0f, 50.0f);

    //Ajoute un callback permettant de changer d'etat
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Intro, "Intro_Continue", &State_Intro::Continue, this);
}
//Vu qu'elle ne sera plus qu'a contenir de la memoire, nous allons liberer cette dite memoire
void State_Intro::OnDestroy()
{
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Intro, "Intro_Continue");
}
//Methode qui d'activer certaines modifications si la state a deja ete utilisee
void State_Intro::Activate() {}
//Permet de supprimer les modifications si la state n'est plus utilisee
void State_Intro::Deactivate() {}
//Met a jour ce qui est a l'ecran
void State_Intro::Update(const sf::Time &l_time)
{
    //Permet de savoir combien de temps on a passe sur la fenetre
    m_timePassed += l_time.asSeconds();

    //On va faire descendre le logo jusqu'a ce que l'on ait passe six secondes sur l'ecran
    if (m_timePassed < 6.0f)
        m_introSprite.setPosition(m_introSprite.getPosition().x, m_introSprite.getPosition().y + (60 * l_time.asSeconds()));
    /*
    if ((int)m_timePassed % 10 != 0)
        m_indication.setString(sf::String("Press SPACE to continue"));

    if ((int)m_timePassed % 10 == 0)
        m_indication.setString(sf::String(""));
    */
}
//Permet de dessiner les differents elements graphiques
void State_Intro::Draw()
{
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_introSprite);
    if (m_timePassed >= 6.0f)
    {
        window->draw(m_indication);
        window->draw(m_title);
    }
}
//Permet d'atteindre le menu principal. Etant donne qu'on ne reviendra pas tel quel sur cet ecran, on va le supprimer des qu'on l'a quitte
void State_Intro::Continue(EventDetails *l_details)
{
    //lorsque qu'on aura passe un certain sur l'ecran, on pourra passer au menu principal
    if (m_timePassed >= 0.0f)
    {
        m_stateMgr->SwitchTo(StateType::MainMenu);
        m_stateMgr->Remove(StateType::Intro);
    }
}
