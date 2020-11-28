#include "State/BaseState.h"

BaseState::BaseState(StateManager* l_stateManager):m_stateMgr(l_stateManager),m_transparent(false),m_transcendent(false)
{
    //ctor
}

BaseState::~BaseState()
{
    //dtor
}
