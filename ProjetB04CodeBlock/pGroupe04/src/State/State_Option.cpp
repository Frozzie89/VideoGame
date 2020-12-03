#include "State/State_Option.h"
//Constructeur
State_Option::State_Option(StateManager *l_stateManager) : BaseState(l_stateManager)
{
}
//Destructeur
State_Option::~State_Option()
{
}
//Permet de creer les differents elements graphiques que l'on va retrouver dans la fenetre
void State_Option::OnCreate()
{
    //Initialise la police de caractere et le titre
    m_timePassed = 0.0f;
    m_font.loadFromFile("assets/font/superboom.ttf");
    m_title.setFont(m_font);
    m_title.setString(sf::String("OPTION"));
    m_title.setCharacterSize(40);

    m_egg.setFont(m_font);
    m_egg.setString(sf::String("Mister the Duck, it is time to go I think ?"));
    m_egg.setCharacterSize(18);

    //Recuperation de la taille de la fenetre
    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();

    //Definit le positionnement du titre
    sf::FloatRect textRect = m_title.getLocalBounds();
    m_title.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    m_title.setPosition(640, 100);

    sf::FloatRect textRectHint = m_egg.getLocalBounds();
    m_egg.setOrigin(textRectHint.left + textRectHint.width / 2.0f, textRectHint.top + textRectHint.height / 2.0f);
    m_egg.setPosition(400, windowSize.y / 2.0f + 200);

    //Gestion des parametres des differents boutons
    m_buttonSize = sf::Vector2f(600.0f, 64.0f);
    m_buttonPos = sf::Vector2f(640, 300);
    m_buttonPadding = 20; //4 pour 4px

    //Definit le rectangle lie au titre
    m_rectTitle.setSize(m_buttonSize);
    m_rectTitle.setFillColor(sf::Color(0, 128, 128));
    m_rectTitle.setOrigin(m_buttonSize.x / 2.0f, m_buttonSize.y / 2.0f);
    m_rectTitle.setPosition(640, 100);

    //Initialisation des textes des boutons
    std::string str[2];
    str[0] = "Resume";
    str[1] = "Quit";
    for (int i = 0; i < 2; ++i)
    {
        //Va permettre d'avoir des positions automatiques
        sf::Vector2f buttonPosition(m_buttonPos.x, m_buttonPos.y + (i * (m_buttonSize.y + m_buttonPadding)));
        //Caracteristique du "bouton"
        m_rects[i].setSize(m_buttonSize);
        m_rects[i].setFillColor(sf::Color(0, 128, 128)); //Donne du bleu canard, oui on reste dans le theme

        //Caracteristiques du label relatif au "bouton"
        m_labels[i].setFont(m_font);
        m_labels[i].setString(sf::String(str[i]));
        m_labels[i].setCharacterSize(25);

        //Placement du label
        sf::FloatRect rect = m_labels[i].getLocalBounds();

        //Position et origine du "bouton"
        m_rects[i].setOrigin(m_buttonSize.x / 2.0f, m_buttonSize.y / 2.0f);
        m_rects[i].setPosition(buttonPosition.x, buttonPosition.y + (i <= 1 ? 0 : 50));
        m_labels[i].setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
        m_labels[i].setPosition(buttonPosition.x, buttonPosition.y + (i <= 1 ? 0 : 50));
    }
    //Ajout des callbacks
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Option, "Mouse_Left", &State_Option::MouseClick, this);
    evMgr->AddCallback(StateType::Option, "Key_Escape", &State_Option::Game, this);
}
//Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet
void State_Option::OnDestroy()
{
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::MainMenu, "Mouse_Left");
}
//Methode qui d'activer certaines modifications si la state a deja ete utilisee
void State_Option::Activate()
{
}
//Permet de supprimer les modifications si la state n'est plus utilisee
void State_Option::Deactivate()
{
}
//Met a jour ce qui est a l'ecran
void State_Option::Update(const sf::Time &l_time)
{
    void MouseClick();
    m_timePassed += l_time.asSeconds();
}
//Permet de dessiner les differents elements graphiques
void State_Option::Draw()
{
    //Recuperation de la fenetre grace au contexte de stateManager
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    //On dessine le titre ainsi que sa bordure
    window->draw(m_rectTitle);
    window->draw(m_title);

    //on dessine les differents rectangles
    for (int i = 0; i < 2; ++i)
    {
        window->draw(m_rects[i]);
        window->draw(m_labels[i]);
    }

    if (m_timePassed > 200.0f)
    {
        window->draw(m_egg);
    }
}
//Permet de gerer les clicks de la souris
void State_Option::MouseClick(EventDetails *l_details)
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
    //On va voir si on touche les differents boutons en fonction de leur emplacement dans la fenetre
    for (int i = 0; i < 2; ++i)
    {
        if (mousePos.x >= m_rects[i].getPosition().x - halfX && mousePos.x <= m_rects[i].getPosition().x + halfX && mousePos.y >= m_rects[i].getPosition().y - halfY && mousePos.y <= m_rects[i].getPosition().y + halfY)
        {
            //Si le clique touche le premier bouton
            if (i == 0)
            {
                cout << "Return to Game" << endl;
                m_stateMgr->SwitchTo(StateType::Game);
            }
            //Si le clique touche le second bouton
            else if (i == 1)
            {
                cout << "QUIT THE GAME" << endl;
                m_stateMgr->GetContext()->m_wind->Close();
            }
        }
    }
}
//Permet d'acceder a la phase de jeu en changeant le state pour un state Game
void State_Option::Game(EventDetails *l_details)
{
    m_stateMgr->SwitchTo(StateType::Game);
}
