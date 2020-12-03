#ifndef STATE_GAME_H
#define STATE_GAME_H

#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

#include "State/BaseState.h"
#include "StateManager.h"
#include "Cards/DefensiveCardWarrior.h"
#include "Entity/Enemy/Enemy.h"
#include "Entity/Player/Warrior.h"

class State_Game : public BaseState
{
public:
    State_Game(StateManager *l_stateManager);
    virtual ~State_Game();

    void OnCreate();
    void OnDestroy();

    void Activate();
    void Deactivate();

    void Update(const sf::Time &l_time);
    void Draw();

    void Option(EventDetails* l_details);
    void Pause(EventDetails* l_details);

    void CardClick(EventDetails* l_details);

protected:
private:
    sf::Texture m_introTexture;
    sf::Sprite m_introSprite;
    sf::Font m_font;
    sf::Text m_text;
    float m_timePassed;
    sf::Texture m_bgTexture;
    sf::Sprite m_bgSprite;

    sf::RectangleShape m_health;
    sf::RectangleShape m_lostHealth;
    sf::CircleShape m_btnEndTurn;

};

#endif // STATE_GAME_H
