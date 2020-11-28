#include "State/State_MainMenu.h"
//Constructeur
State_MainMenu::State_MainMenu(StateManager *l_stateManager) : BaseState(l_stateManager) {}
//Destructeur
State_MainMenu::~State_MainMenu() {}

void State_MainMenu::OnCreate()
{
    m_timePassed = 0.0f;
    m_font.loadFromFile("assets/font/superboom.ttf");
    m_text.setFont(m_font);
    m_text.setString(sf::String("Play as a ..."));
    m_text.setCharacterSize(25);

    m_hint.setFont(m_font);
    m_hint.setString(sf::String(""));
    m_hint.setCharacterSize(18);

    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();

    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    m_text.setPosition(400, 100);

    sf::FloatRect textRectHint = m_hint.getLocalBounds();
    m_hint.setOrigin(textRectHint.left + textRectHint.width / 2.0f, textRectHint.top + textRectHint.height / 2.0f);
    m_hint.setPosition(100, windowSize.y / 2.0f + 150);

    //Gestion des parametres des differents boutons
    m_buttonSize = sf::Vector2f(600.0f, 64.0f);
    m_buttonPos = sf::Vector2f(400, 200);
    m_buttonPadding = 4; //4 pour 4px

    std::string str[3];
    str[0] = "Warrior";
    str[1] = "Gambler";
    str[2] = "Quit";

    for (int i = 0; i < 3; ++i)
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
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::MainMenu, "Mouse_Left", &State_MainMenu::MouseClick, this);
}
//Quand l'etat sera detruit, il faudra detruire les callbacks
void State_MainMenu::OnDestroy()
{
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::MainMenu, "Mouse_Left");
}
//Methode qui permet de savoir si le jeu a deja ete lance
void State_MainMenu::Activate()
{
    //Si l'etat Game existe, alors on va afficher RESUME, ce qui gache totalement MA PHRASE
    if (m_stateMgr->HasState(StateType::Game) && m_labels[0].getString() == "I")
    {
        m_labels[0].setString(sf::String("RESUME"));
        sf::FloatRect rect = m_labels[0].getLocalBounds();
        m_labels[0].setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
    }
}

void State_MainMenu::Deactivate() {}

void State_MainMenu::Update(const sf::Time &l_time)
{
    MouseHover();

    if (m_timePassed < 100.0f)
        m_timePassed += l_time.asSeconds();
}
//Permet de dessiner l'ecran
void State_MainMenu::Draw()
{
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_text);
    window->draw(m_hint);

    for (int i = 0; i < 3; ++i)
    {
        window->draw(m_rects[i]);
        window->draw(m_labels[i]);
    }
}
//Va permettre de gerer les clicks de souris
void State_MainMenu::MouseClick(EventDetails *l_details)
{
    sf::Vector2i mousePos = l_details->m_mouse;

    if (mousePos.x == 0 && mousePos.y == 0)
    {
        sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
        mousePos = sf::Mouse::getPosition(*window);
    }

    float halfX = m_buttonSize.x / 2.0f;
    float halfY = m_buttonSize.y / 2.0f;
    for (int i = 0; i < 3; ++i)
    {
        if (mousePos.x >= m_rects[i].getPosition().x - halfX && mousePos.x <= m_rects[i].getPosition().x + halfX && mousePos.y >= m_rects[i].getPosition().y - halfY && mousePos.y <= m_rects[i].getPosition().y + halfY)
        {
            if (i == 0)
            {
                cout << "PLAY AS WARRIOR" << endl;
                m_stateMgr->SwitchTo(StateType::Game);
            }
            else if (i == 1)
            {
                cout << "PLAY AS GAMBLER" << endl;
                m_stateMgr->SwitchTo(StateType::Game);
            }
            else if (i == 2)
            {
                cout << "QUIT THE GAME" << endl;
                m_stateMgr->GetContext()->m_wind->Close();
            }
        }
    }
}

void State_MainMenu::MouseHover()
{
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    m_hint.setString(sf::String(""));

    float halfX = m_buttonSize.x / 2.0f;
    float halfY = m_buttonSize.y / 2.0f;
    for (int i = 0; i < 3; ++i)
    {
        if (mousePos.x >= m_rects[i].getPosition().x - halfX && mousePos.x <= m_rects[i].getPosition().x + halfX && mousePos.y >= m_rects[i].getPosition().y - halfY && mousePos.y <= m_rects[i].getPosition().y + halfY)
        {
            if (i == 0)
                m_hint.setString(sf::String("Basic Warrior cards, deals normal damages"));

            else if (i == 1)
                m_hint.setString(sf::String("Gambler's cards deals more damage, but have 50\% of failing"));

            else
                m_hint.setString(sf::String(""));
        }
    }
}
