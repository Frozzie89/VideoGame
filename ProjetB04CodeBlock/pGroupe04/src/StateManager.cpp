#include "StateManager.h"
//Constructeur sans argument
StateManager::StateManager()
{
}
//Constructeur avec Argument
StateManager::StateManager(SharedContext *l_shared)
    : m_shared(l_shared)
{
    CreateIntro();
    RegisterState<State_MainMenu>(StateType::MainMenu);
    RegisterState<State_Game>(StateType::Game);
    RegisterState<State_Paused>(StateType::Paused);
    RegisterState<State_Option>(StateType::Option);
    RegisterState<State_GameOver>(StateType::GameOver);
    RegisterState<State_Credits>(StateType::Credits);
}
//Destructeur
//Vu qu'on alloue dynamiquement de la memoire, nous devons la liberer
StateManager::~StateManager()
{
    for (auto &itr : m_states)
    {
        itr.second->OnDestroy();
        delete itr.second;
    }
}
//Permet de dessiner le premier state de la liste qui n'est pas transparent
void StateManager::Draw()
{
    //On verifie si la liste n'est pas vide
    if (m_states.empty())
        return;

    //On verifie si la liste contient au moins 2 elements, sinon la transparence serait inutile, et on cherche quel etat a eu une transparence
    if (m_states.back().second->IsTransparent() && m_states.size() > 1)
    {
        auto itr = m_states.end();
        //On va chercher le dernier etat qui ne soit pas transparent a moins qu'il ne s'agisse du premier element de la liste
        while (itr != m_states.begin())
        {
            if (itr != m_states.end())
            {
                if (!itr->second->IsTransparent())
                    break;
            }
            --itr;
        }
        //On va dessiner tous les etats à partir du dernier element apparant ou bien à partir du premier element
        for (; itr != m_states.end(); ++itr)
        {
            itr->second->Draw();
        }
    }
    //Si il n'y a qu'un seul element ou si l'element en question n'est pas transparent, alors on va appeler sa methode Draw
    else
        m_states.back().second->Draw();
}
//Permet de mettre a jour l'ecran
void StateManager::Update(const sf::Time &l_time)
{
    if (m_states.empty())
        return;

    if (m_states.back().second->IsTranscendent() && m_states.size() > 1)
    {
        auto itr = m_states.end();
        while (itr != m_states.begin())
        {
            if (itr != m_states.end())
            {
                if (!itr->second->IsTranscendent())
                    break;
            }
            --itr;
        }
        for (; itr != m_states.end(); ++itr)
        {
            itr->second->Update(l_time);
        }
    }
    else
        m_states.back().second->Update(l_time);
}
//Permet de supprimer les etats que l'on a conserve dans la liste des etats a supprime
void StateManager::ProcessRequests()
{
    while (m_toRemove.begin() != m_toRemove.end())
    {
        RemoveState(*m_toRemove.begin());
        m_toRemove.erase(m_toRemove.begin());
    }
}
//Retourne le contexte
SharedContext *StateManager::GetContext()
{
    return m_shared;
}
// Cherche dans le conteneur d'etats.
// Si il trouve un tel etat, retourne true. Sinon false
bool StateManager::HasState(const StateType &l_type)
{
    for (auto itr = m_states.begin(); itr != m_states.end(); ++itr)
    {
        if (itr->first == l_type)
        {
            auto removed = std::find(m_toRemove.begin(), m_toRemove.end(), l_type);
            if (removed == m_toRemove.end())
                return true;

            return false;
        }
    }
    return false;
}
//Permet de changer de state si l'etat fait parti de la liste de states
void StateManager::SwitchTo(const StateType &l_type)
{
    //Modification du state actuel dans le contexte
    m_shared->m_eventManager->SetCurrentState(l_type);
    for (auto itr = m_states.begin(); itr != m_states.end(); ++itr)
    {
        //On va chercher dans notre liste l'etat passe en argument
        if (itr->first == l_type)
        {
            m_states.back().second->Deactivate();
            StateType tmp_type = itr->first;
            BaseState *tmp_state = itr->second;
            m_states.erase(itr);
            m_states.emplace_back(tmp_type, tmp_state);
            tmp_state->Activate();
            return;
        }
    }
    //Si l'etat donne en argument n'est pas trouve, on va creer l'etat
    if (!m_states.empty())
        m_states.back().second->Deactivate();

    CreateState(l_type);
    m_states.back().second->Activate();
}
//Ajoute un etat de la liste servant a supprimer les etats
void StateManager::Remove(const StateType &l_type)
{
    m_toRemove.push_back(l_type);
}
//Cree un etat si il n'est pas deja dans la liste
void StateManager::CreateState(const StateType &l_type)
{
    //on regarde dans le container de Factory si l'element est dans sa liste de state a cree
    auto newState = m_stateFactory.find(l_type);
    //on verifie si on peut creer l'etat
    if (newState == m_stateFactory.end())
        return;

    //Si oui
    BaseState *state = newState->second();
    m_states.emplace_back(l_type, state);
    state->OnCreate();
}
//Supprime l'etat
void StateManager::RemoveState(const StateType &l_type)
{
    for (auto itr = m_states.begin(); itr != m_states.end(); ++itr)
    {
        if (itr->first == l_type)
        {
            itr->second->OnDestroy();
            delete itr->second;
            m_states.erase(itr);
            return;
        }
    }
}
//Permet de modifier le contexte
void StateManager::SetContext(SharedContext* l_context)
{
    m_shared = l_context;
}

void StateManager::CreateIntro()
{
    RegisterState<State_Intro>(StateType::Intro);
}
//Permet de remettre a zero le jeu
void StateManager::Restart()
{
    Remove(StateType::MainMenu);
    Remove(StateType::Game);
    Remove(StateType::Paused);
    Remove(StateType::Option);
    Remove(StateType::GameOver);
    Remove(StateType::Credits);

    RegisterState<State_MainMenu>(StateType::MainMenu);
    RegisterState<State_Game>(StateType::Game);
    RegisterState<State_Paused>(StateType::Paused);
    RegisterState<State_Option>(StateType::Option);
    RegisterState<State_GameOver>(StateType::GameOver);
    RegisterState<State_Credits>(StateType::Credits);
}
