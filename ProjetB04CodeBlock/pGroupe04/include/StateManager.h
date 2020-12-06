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
#include "State/State_Game.h"
#include "State/State_Paused.h"
#include "State/State_Option.h"
#include "State/State_GameOver.h"
#include "State/State_Credits.h"

#include <iostream>
using namespace std;

using StateContainer = std::vector<std::pair<StateType, BaseState *>>;                //Pas de map car elle ne garde pas un ordre d'indexation
using TypeContainer = std::vector<StateType>;                                         //Liste d'etats possible
using StateFactory = std::unordered_map<StateType, std::function<BaseState *(void)>>; //Permet de creer les etats en passant dans une "factory method"
/*
    Cette classe va permettre de gerer les differents states, ou etats, que l'on va avoir dans le jeu
    Parmi ses arguments, on va retrouver un contexte, une paire d'elements caracterisant le type d'etats et l'affichage correspondant, une liste des etats disponibles ainsi
    qu'une liste de state a creer.
    On retrouve une methode template qui permet de mettre en commun un etat avec un affichage
*/
class StateManager
{
public:
    StateManager(); //Constructeur sans argument
    StateManager(SharedContext *l_shared); //Constructeur avec argument
    ~StateManager(); // Destructeur
    void Update(const sf::Time &l_time); //Permet de mettre a jour l'ecran
    void Draw(); //Permet de dessiner le premier state de la liste qui n'est pas transparent
    void ProcessRequests(); //Permet de supprimer les etats que l'on a conserve dans la liste des etats a supprime
    SharedContext *GetContext(); //Retourne le contexte de stateManager
    bool HasState(const StateType &l_type); //Recherche si le state passe en argument est dans la liste de state
    void SwitchTo(const StateType &l_type); //Permet de changer de state si l'etat fait parti de la liste de states
    void Remove(const StateType &l_type); //Ajoute un state de la liste servant a supprimer les state

    void SetContext(SharedContext* l_context); //Permet de modifier le contexte

    void CreateIntro(); //Permet de creer l'intro
    void Restart(); //Remets a zero le jeu

private:
    // Methods.
    void CreateState(const StateType &l_type); //Cree un state si il n'est pas deja dans la liste
    void RemoveState(const StateType &l_type); //Rajoute le state a la liste des elements a supprimer

    //Permet de mettre en commun un type de state et un l'affichage d'un state
    template <class T>
    void RegisterState(const StateType &l_type)
    {
        m_stateFactory[l_type] = [this]() -> BaseState * {
            return new T(this);
        };
    }
    // Members
    SharedContext *m_shared; //Contexte du statemanager
    StateContainer m_states; //Liste des paires Type d'etats/Affichage des etats
    TypeContainer m_toRemove; //Liste des etats possibles
    StateFactory m_stateFactory; //Liste des etats a construire
};

#endif // STATEMANAGER_H
