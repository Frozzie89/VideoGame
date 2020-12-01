#ifndef STATE_PAUSED_H
#define STATE_PAUSED_H


#include "State/BaseState.h"
#include "StateManager.h"

class State_Paused:public BaseState
{
    public:
        State_Paused(StateManager* l_stateManager);
        virtual ~State_Paused();

        void OnCreate();
        void OnDestroy();

        void Activate();
        void Deactivate();

        void Update(const sf::Time& l_time);
        void Draw();

        void Unpause(EventDetails* l_details);

    protected:

    private:
        sf::Text m_text;
        sf::RectangleShape m_rect;
        sf::Font m_font;
};

#endif // STATE_PAUSED_H
