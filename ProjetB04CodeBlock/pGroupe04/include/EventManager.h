#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Graphics.hpp>

#include <functional> // Permet d'avoir std::function et std::bind
#include <unordered_map>
#include <iostream>
#include <sstream> //Permet d'avoir stringstream
#include <fstream> //Permet de couper stringstream

#include "State/StateType.h"

//Differents d'Event qu'on peut avoir
enum class EventType
{
    KeyDown = sf::Event::KeyPressed,
    KeyUp = sf::Event::KeyReleased,
    MButtonDown = sf::Event::MouseButtonPressed,
    MButtonTop = sf::Event::MouseButtonReleased,
    MouseWheel = sf::Event::MouseWheelMoved,
    WindowResized = sf::Event::Resized,
    GainedFocus = sf::Event::GainedFocus,
    LostFocus = sf::Event::LostFocus,
    MouseEntered = sf::Event::MouseEntered,
    MouseLeft = sf::Event::MouseLeft,
    Closed = sf::Event::Closed,
    TextEntered = sf::Event::TextEntered,
    Keyboard = sf::Event::Count + 1,
    Mouse = sf::Event::MouseMoved,
    Joystick = sf::Event::Count + 3
};
//Donne des info sur l'event
struct EventInfo
{
    EventInfo() { m_code = 0; }
    EventInfo(int l_event)
    {
        m_code = l_event;
    }
    union
    { //Union est un type de declaration comme struct sauf que tous les elements d'union prendront la meme case memoire
        int m_code;
    };
};
//Sert à stocker dans une variable le type et les informations d'un event
using Events = std::vector<std::pair<EventType, EventInfo>>;
// Sert à partager les informations de l'évènement avec le code qui utilise cette classe
struct EventDetails
{
    EventDetails(const std::string &l_bindName) : m_name(l_bindName)
    {
        Clear();
    }
    std::string m_name;

    sf::Vector2i m_size;
    sf::Uint32 m_textEntered;
    sf::Vector2i m_mouse;
    int m_mouseWheelDelta;
    int m_keyCode;

    void Clear()
    {
        m_size = sf::Vector2i(0, 0);
        m_textEntered = 0;
        m_mouse = sf::Vector2i(0, 0);
        m_mouseWheelDelta = 0;
        m_keyCode = -1;
    }
};

// Sert à contenir tous les informations liés aux events
// Le constructeur va prend le nom de l'action dont on veut lie les event
// et utilise la listee d'initiateur pour parametrer les membres de la classe
struct Binding
{
    Binding(const std::string &l_name) : m_name(l_name), m_details(l_name), c(0) {}
    //Sert à lier un type d'event et l'information d'un event dans un objet Events
    void BindEvent(EventType l_type, EventInfo l_info = EventInfo())
    {
        m_events.emplace_back(l_type, l_info);
    }
    Events m_events;
    //Ceci doit suivre l'ordre d'instanciation du constructeur
    std::string m_name;
    EventDetails m_details;
    int c; //Sert à compter le nombre d'events qui "arrive" --> Va nous servir pour savoir combien d'events sont effectuees et savoir si tous les events sont actifs ou non
};
//Afin de lier les methodes aux events, on a besoin d'un callback
//Un callback, c'est un bout de code qui peut être passé en argument d'un autre bout de code qui sera execute en temps voulu
//Typiquement, un callback est une fonction passé en argument d'une autre
/*template<class T>
struct Callback{
    std::string m_name;
    T* CallbackInstance; // Pointeur vers l'instance
    void(T::*_callback)();
    void Call(){
        CallbackInstance->*_callback();
    }
};
*/

//Sert à stocker les liaisons --> Utilisation de unordered_map pour etre sur qu'il n'y aura qu'une liaison par action
using Bindings = std::unordered_map<std::string, Binding *>;
//Un callback, c'est un bout de code qui peut être passé en argument d'un autre bout de code qui sera execute en temps voulu
//Typiquement, un callback est une fonction passé en argument d'une autre
//On va utiliser une map afin de n'avoir qu'un callback par action
using CallbackContainer = std::unordered_map<std::string, std::function<void(EventDetails *)>>;

using Callbacks = std::unordered_map<StateType, CallbackContainer>;

class EventManager
{
public:
    EventManager();
    virtual ~EventManager();

    bool AddBinding(Binding *l_binding);    //Sert à ajouter une liaison
    bool RemoveBinding(std::string l_name); //A supprimer une liaison par le nom
    void SetFocus(const bool &l_focus);     //Sert à modifier le focus de la fenetre

    //Ceci doit etre defini dans le header
    //On l'implemente ici au lieu du .cpp a cause du compilateur vu qu'on utilise une classe templee
    template <class T>
    bool AddCallback(StateType l_state, const std::string &l_name, void (T::*l_func)(EventDetails *), T *l_instance)
    {
        auto itr = m_callbacks.emplace(
                                  l_state, CallbackContainer())
                       .first;
        auto temp = std::bind(l_func, l_instance, std::placeholders::_1);
        return itr->second.emplace(l_name, temp).second;
    }

    //Pour avoir une certaine coherance, on va instancier cette classe ici aussi
    bool RemoveCallback(StateType l_state, const std::string &l_name)
    {
        auto itr = m_callbacks.find(l_state);
        if (itr == m_callbacks.end())
        {
            return false;
        }
        auto itr2 = itr->second.find(l_name);
        if (itr2 == itr->second.end())
        {
            return false;
        }
        itr->second.erase(l_name);
        return true;
    }

    void HandleEvent(sf::Event &l_event); //Permet de gerer la gestion des evenements
    void Update(); //Permet d'update la classe

    //Permet d'obtenir la position de la souris. On place une fenetre en argument
    // Pour etre sur qu'on puisse faire des traitements peu importe la fenetre utilisee
    sf::Vector2i GetMousePos(sf::RenderWindow *l_wind = nullptr)
    {
        return (l_wind ? sf::Mouse::getPosition(*l_wind) : sf::Mouse::getPosition());
    }

    void SetCurrentState(const StateType &l_type); //Permet de modifier l'etat actuel
    StateType GetCurrentState() const; //Permet de retourner l'etat actuel

protected:
private:
    void LoadBindings(); //Permet de charger les liaisons depuis un fichier de donnees

    Bindings m_bindings; //Map servant à stocker les liaisons
    Callbacks m_callbacks; //Map contenant les callbacks
    bool m_hasFocus; //Permet de focus ou non la fenetre
    StateType m_currentState; //Etat actuel
};

#endif // EVENTMANAGER_H
