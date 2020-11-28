#ifndef STATE_INTRO_H
#define STATE_INTRO_H
#include <SFML/Graphics.hpp>

#include "State/BaseState.h"
#include "StateManager.h" //vu que la classe est declaree dans BaseState, nous devons l'implementer

class State_Intro : public BaseState
{
public:
    State_Intro(StateManager *l_stateManager);
    virtual ~State_Intro();

    void OnCreate();
    void OnDestroy();

    void Activate();
    void Deactivate();

    void Update(const sf::Time &l_time);
    void Draw();

    void Continue(EventDetails *l_details); //Sert de transition vers un autre etat

protected:
private:
    sf::Texture m_introTexture;
    sf::Sprite m_introSprite;
    sf::Font m_font;
    sf::Text m_indication;
    sf::Text m_title;
    float m_timePassed; //Sert a compter le temps passe sur cet etat
};

#endif // STATE_INTRO_H
