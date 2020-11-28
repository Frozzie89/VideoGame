#ifndef SHAREDCONTEXT_H
#define SHAREDCONTEXT_H

#include "Window.h"
#include "EventManager.h"

#include <iostream>
using namespace std;
//Permet d'avoir en un seul element les elements les plus utilisé
struct SharedContext
{
    SharedContext() : m_wind(nullptr), m_eventManager(nullptr)
    {
        cout << "SharedContext" << endl;
    }
    Window *m_wind;
    EventManager *m_eventManager;
};

#endif // SHAREDCONTEXT_H
