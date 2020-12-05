#include "State/State_GameOver.h"
//Constructeur
State_GameOver::State_GameOver(StateManager* l_stateManager):BaseState(l_stateManager)
{

}
//Destructeur
State_GameOver::~State_GameOver()
{

}
//Permet de creer les differents elements graphiques que l'on va retrouver dans la fenetre
void State_GameOver::OnCreate()
{
     //Initialise la police de caractere et le titre
    m_timePassed = 0.0f;
    m_font.loadFromFile("assets/font/superboom.ttf");
    m_title.setFont(m_font);
    m_title.setString(sf::String("GAME OVER"));
    m_title.setCharacterSize(100);

    //Recuperation de la taille de la fenetre
    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();

    //Definit le positionnement du titre
    sf::FloatRect textRect = m_title.getLocalBounds();
    m_title.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    m_title.setPosition(640, 100);

    //Gestion des parametres des differents boutons
    m_buttonSize = sf::Vector2f(600.0f, 64.0f);
    m_buttonPos = sf::Vector2f(640, 300);
    m_buttonPadding = 20; //4 pour 4px

    //Definit le rectangle lie au titre
    m_rectTitle.setSize(m_buttonSize);
    m_rectTitle.setFillColor(sf::Color(0, 128, 128));
    m_rectTitle.setOrigin(m_buttonSize.x / 2.0f, m_buttonSize.y / 2.0f);
    m_rectTitle.setPosition(640, 100);

    sf::Vector2f buttonPosition(640, 400);

    m_rect.setSize(m_buttonSize);
    m_rect.setFillColor(sf::Color(0, 128, 128)); //Donne du bleu canard, oui on reste dans le theme

    //Caracteristiques du label relatif au "bouton"
    m_label.setFont(m_font);
    m_label.setString("BACK TO INTRO");
    m_label.setCharacterSize(25);

    //Placement du label
    sf::FloatRect rect = m_label.getLocalBounds();

    //Position et origine du "bouton"
    m_rect.setOrigin(m_buttonSize.x / 2.0f, m_buttonSize.y / 2.0f);
    m_rect.setPosition(buttonPosition.x, buttonPosition.y);
    m_label.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
    m_label.setPosition(buttonPosition.x, buttonPosition.y);

    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::GameOver, "Mouse_Left", &State_GameOver::MouseClick, this);
}
//Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet
void State_GameOver::OnDestroy()
{
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::GameOver,"Mouse_Left");
}
//Methode qui d'activer certaines modifications si la state a deja ete utilisee
void State_GameOver::Activate()
{

}
//Permet de supprimer les modifications si la state n'est plus utilisee
void State_GameOver::Deactivate()
{

}
//Met a jour ce qui est a l'ecran
void State_GameOver::Update(const sf::Time& l_time)
{
    void MouseClick();
}
//Permet de dessiner les differents elements graphiques
void State_GameOver::Draw()
{
    //Recuperation de la fenetre grace au contexte de stateManager
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    //On dessine le titre ainsi que sa bordure
    window->draw(m_rectTitle);
    window->draw(m_title);

    window->draw(m_rect);
    window->draw(m_label);
}
//Permet de gerer les clicks de la souris
void State_GameOver::MouseClick(EventDetails* l_details)
{

    //On recupere la valeur de la position de la souris grace a l'argument
    sf::Vector2i mousePos = l_details->m_mouse;
    //Si les positions en abscisse et en ordonnee sont egales a zero, on va reprendre la position de la souris par rapport a la fenetre
    if (mousePos.x == 0 && mousePos.y == 0)
    {
        sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
        mousePos = sf::Mouse::getPosition(*window);
    }
    //Definit le milieu du bouton,ici pour l'abscisse
    float halfX = m_buttonSize.x / 2.0f;
    //Ici, pour l'ordonnee
    float halfY = m_buttonSize.y / 2.0f;
    if (mousePos.x >= m_rect.getPosition().x - halfX && mousePos.x <= m_rect.getPosition().x + halfX && mousePos.y >= m_rect.getPosition().y - halfY && mousePos.y <= m_rect.getPosition().y + halfY)
    {
        m_stateMgr->GetContext()->m_entity = nullptr;
        m_stateMgr->CreateIntro();
        m_stateMgr->SwitchTo(StateType::Intro);
    }
}
