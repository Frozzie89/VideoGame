#ifndef SHAREDCONTEXT_H
#define SHAREDCONTEXT_H

#include "Window.h"
#include "EventManager.h"
#include "Entity/Entity.h"
class Entity;
#include <iostream>
using namespace std;
//Permet d'avoir en un seul element les elements les plus utilisé
struct SharedContext
{
    SharedContext() : m_wind(nullptr), m_eventManager(nullptr), m_entity(nullptr)
    {
    }
    Window *m_wind;
    EventManager *m_eventManager;
    Entity *m_entity;
};

#endif // SHAREDCONTEXT_H
