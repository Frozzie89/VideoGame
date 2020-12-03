#ifndef STATE_OPTION_H
#define STATE_OPTION_H

#include <SFML/Graphics.hpp>

#include "State/BaseState.h"
#include "StateManager.h"
#include <iostream>

class State_Option: public BaseState
{
    public:
        State_Option(StateManager *l_stateManager);
        virtual ~State_Option();

        void OnCreate();
        void OnDestroy();

        void Activate();
        void Deactivate();

        void Update(const sf::Time &l_time);
        void Draw();

        void MouseClick(EventDetails *l_details);
        void Game(EventDetails* l_details);

    protected:

    private:
        sf::RectangleShape m_rectTitle;
        sf::Text m_title;
        sf::Text m_egg;
        sf::Font m_font;

        sf::Vector2f m_buttonSize;
        sf::Vector2f m_buttonPos;
        unsigned int m_buttonPadding;

        sf::RectangleShape m_rects[2]; //On va creer trois "boutons"
        sf::Text m_labels[2];


        float m_timePassed;
};

#endif // STATE_OPTION_H
