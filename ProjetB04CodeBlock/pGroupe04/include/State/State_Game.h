#ifndef STATE_GAME_H
#define STATE_GAME_H

#include <SFML/Graphics.hpp>

#include "State/BaseState.h"
#include "StateManager.h"

class State_Game: public BaseState
{
    public:
        State_Game(StateManager* l_stateManager);
        virtual ~State_Game();

        void OnCreate();
        void OnDestroy();

        void Activate();
        void Deactivate();

        void Update(const sf::Time& l_time);
        void Draw();

    protected:

    private:
        sf::Texture m_introTexture;
        sf::Sprite m_introSprite;
        sf::Font m_font;
        sf::Text m_text;
        float m_timePassed;
};

#endif // STATE_GAME_H
