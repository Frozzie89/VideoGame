#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <functional>

#include "EventManager.h"
#include "Window.h"
#include "SharedContext.h"

#include "State/BaseState.h"
#include "State/State_Intro.h"
#include "State/State_MainMenu.h"


#include <iostream>
using namespace std;

using StateContainer = std::vector<std::pair<StateType, BaseState*>>; //Pas de map car elle ne garde pas un ordre d'indexation
using TypeContainer = std::vector<StateType>; //Liste d'etats possible
using StateFactory = std::unordered_map<StateType, std::function<BaseState*(void)>>; //Perm

    class StateManager{
public:
    StateManager();
    StateManager(SharedContext* l_shared);
    ~StateManager();
    void Update(const sf::Time& l_time);
    void Draw();
    void ProcessRequests();
    SharedContext* GetContext();
    bool HasState(const StateType& l_type);
    void SwitchTo(const StateType& l_type);
    void Remove(const StateType& l_type);

    void setContext(SharedContext l_context);

    private:
    // Methods.
    void CreateState(const StateType& l_type);
    void RemoveState(const StateType& l_type);

    template<class T>
    void RegisterState(const StateType& l_type){
        m_stateFactory[l_type] = [this]() -> BaseState*
        {
            return new T(this);
        };
    }
    // Members.
    SharedContext* m_shared;
    StateContainer m_states;
    TypeContainer m_toRemove;
    StateFactory m_stateFactory;
};


#endif // STATEMANAGER_H
