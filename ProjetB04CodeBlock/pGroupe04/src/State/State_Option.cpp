#include "State/State_Option.h"

State_Option::State_Option(StateManager *l_stateManager) : BaseState(l_stateManager)
{
}

State_Option::~State_Option()
{
}

void State_Option::OnCreate()
{
    m_timePassed = 0.0f;
    m_font.loadFromFile("assets/font/superboom.ttf");
    m_title.setFont(m_font);
    m_title.setString(sf::String("OPTION"));
    m_title.setCharacterSize(40);

    m_egg.setFont(m_font);
    m_egg.setString(sf::String("Mister the Duck, it is time to go I think ?"));
    m_egg.setCharacterSize(18);

    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();

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

    m_rectTitle.setSize(m_buttonSize);
    m_rectTitle.setFillColor(sf::Color(0, 128, 128));
    m_rectTitle.setOrigin(m_buttonSize.x / 2.0f, m_buttonSize.y / 2.0f);
    m_rectTitle.setPosition(640, 100);

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
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Option, "Mouse_Left", &State_Option::MouseClick, this);
    evMgr->AddCallback(StateType::Option, "Key_Escape", &State_Option::Game, this);
}

void State_Option::OnDestroy()
{
    EventManager *evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::MainMenu, "Mouse_Left");
}

void State_Option::Activate()
{
}

void State_Option::Deactivate()
{
}

void State_Option::Update(const sf::Time &l_time)
{
    void MouseClick();
    m_timePassed += l_time.asSeconds();
}

void State_Option::Draw()
{
    sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();

    window->draw(m_rectTitle);
    window->draw(m_title);

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

void State_Option::MouseClick(EventDetails *l_details)
{
    sf::Vector2i mousePos = l_details->m_mouse;

    if (mousePos.x == 0 && mousePos.y == 0)
    {
        sf::RenderWindow *window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
        mousePos = sf::Mouse::getPosition(*window);
    }

    float halfX = m_buttonSize.x / 2.0f;
    float halfY = m_buttonSize.y / 2.0f;
    for (int i = 0; i < 2; ++i)
    {
        if (mousePos.x >= m_rects[i].getPosition().x - halfX && mousePos.x <= m_rects[i].getPosition().x + halfX && mousePos.y >= m_rects[i].getPosition().y - halfY && mousePos.y <= m_rects[i].getPosition().y + halfY)
        {
            if (i == 0)
            {
                cout << "Return to Game" << endl;
                m_stateMgr->SwitchTo(StateType::Game);
            }
            else if (i == 1)
            {
                cout << "QUIT THE GAME" << endl;
                m_stateMgr->GetContext()->m_wind->Close();
            }
        }
    }
}
void State_Option::Game(EventDetails *l_details)
{
    m_stateMgr->SwitchTo(StateType::Game);
}
