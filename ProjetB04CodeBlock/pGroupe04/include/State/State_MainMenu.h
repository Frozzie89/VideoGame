#ifndef STATE_MAINMENU_H
#define STATE_MAINMENU_H

#include <SFML/Graphics.hpp>

#include "State/BaseState.h"
#include "StateManager.h"
#include <iostream>

using namespace std;

class State_MainMenu : public BaseState
{
public:
    State_MainMenu(StateManager *l_stateManager);
    virtual ~State_MainMenu();

    void OnCreate();
    void OnDestroy();

    void Activate();
    void Deactivate();

    void Update(const sf::Time &l_time);
    void Draw();

    void MouseClick(EventDetails *l_details);
    void MouseHover();

protected:
private:
    sf::Text m_text;
    sf::Text m_hint;
    sf::Font m_font;

    sf::Vector2f m_buttonSize;
    sf::Vector2f m_buttonPos;
    unsigned int m_buttonPadding;

    sf::RectangleShape m_rects[3]; //On va creer trois "boutons"
    sf::Text m_labels[3];          //Vu qu'on a trois "boutons", il nous faut trois labels

    // sf::Text m_Easter;
    float m_timePassed;
};

#endif // STATE_MAINMENU_H
