#include "State/BaseState.h"
//Constructeur
BaseState::BaseState(StateManager *l_stateManager) : m_stateMgr(l_stateManager), m_transparent(false), m_transcendent(false)
{
    //ctor
}
//Destructeur
BaseState::~BaseState()
{
    //dtor
}
