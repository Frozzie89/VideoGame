#include "EventManager.h"
//Constructeur
EventManager::EventManager(): m_hasFocus(true)
{
    //ctor
    LoadBindings();
}
//Destructeur
EventManager::~EventManager()
{
    //dtor
    for(auto &itr : m_bindings){
        delete itr.second;
        itr.second = nullptr; // nullptr --> Implicitement convertible et comparable à tout type de pointeur, là où null l'est pour des types intégraux
    }
}
//Permet d'ajouter une liaison
bool EventManager::AddBinding(Binding* l_binding)
{
    //Retourne false si une liaison possède déjà ce nom
    if(m_bindings.find(l_binding->m_name)!= m_bindings.end()){
        return false;
    }
    return m_bindings.emplace(l_binding->m_name,l_binding).second;
}
//Supprime une liaison en passant son nom en parametre
bool EventManager::RemoveBinding(std::string l_name)
{
    auto itr = m_bindings.find(l_name);
    if(itr == m_bindings.end()){
        return false;
    }
    delete itr->second;
    m_bindings.erase(itr);
    return true;
}

void EventManager::SetFocus(const bool& l_focus)
{
    m_hasFocus = l_focus;
}
//Gere l'evenement passe en parametre
//On va passer un event en argument et iterer l'ensemble des liaisons pour verifier si le type d'argument du parametre correspond
//au type de l'evenement de la liaison en cours.
//Si oui, il faudra verifier s'il s'agit d'un evenement clavier ou souris, les evenements relies à ces deux la etant bien plus nombreux que les autre
//S'il s'agit de l'un d'eux, on va verifier que le code de la touche du clavier ou le click de la souris, qui est stocke dans les structure
//l_event.key, pour les touches, et l_event.mouseButton, pour les boutons, correspond au code de notre evenement de liaison
//Si c'est le cas, ou bien s'il s'agit d'un evenement qui n'a pas besoin de plus de traitement, nous allons incrementer le compteur c de la liaison
//après que que les informations pertinentes de l'evenement soit stockees dans la structure details de l'evenement de liaison
void EventManager::HandleEvent(sf::Event& l_event)
{
    //Gestion des evenements SFML
    for(auto &b_itr : m_bindings)
    {
        Binding* bindin = b_itr.second;
        for(auto &e_itr : bindin->m_events)
        {
            EventType sfmlEvent = (EventType)l_event.type;
            if(e_itr.first != sfmlEvent){
                continue;
            }
            //On verifie si on a un type d'evenement lie au touches du clavier
            if(sfmlEvent == EventType::KeyDown || sfmlEvent == EventType::KeyUp)
            {
                    //.second signifie qu'on prend le deuxieme element de la pair -> Pour rappel, Events est un vecteur contenant une paire d'information, le type et les informations de l'event
                    // Comme ceci : Events = std::vector<std::pair<EventType,EventInfo>>
                    //Ici, on va tester les codes des evenements
                    if(e_itr.second.m_code == l_event.key.code)
                    {
                        //Fais correspondre les events / les touches frappees
                        //Augmente le compteur
                        if(bindin->m_details.m_keyCode != -1)
                        {
                            bindin->m_details.m_keyCode = e_itr.second.m_code;
                        }
                        ++(bindin->c);
                        break;
                    }
            }
            //On verifie si on a un type d'evenement lie au click de la souris
            else if (sfmlEvent == EventType::MButtonDown || sfmlEvent == EventType::MButtonTop)
            {
                if(e_itr.second.m_code == l_event.mouseButton.button)
                {
                    //Fais correspondre les events / Les touches frappes
                    //Augmente le compteur
                    bindin->m_details.m_mouse.x = l_event.mouseButton.x;
                    bindin->m_details.m_mouse.y = l_event.mouseButton.y;
                    if(bindin ->m_details.m_keyCode !=-1)
                    {
                        bindin->m_details.m_keyCode = e_itr.second.m_code;
                    }
                    ++(bindin->c);
                    break;
                }
            } else
            {
                //Pas besoin de conditions supplementaires
                //On verifie si il s'agit de la roulette de la souris
                if(sfmlEvent == EventType::MouseWheel)
                {
                    bindin->m_details.m_mouseWheelDelta = l_event.mouseWheel.delta;
                }
                //On verifie si on a redimensionne la fenetre
                else if(sfmlEvent == EventType::WindowResized)
                {
                    bindin->m_details.m_size.x = l_event.size.width;
                    bindin->m_details.m_size.y = l_event.size.height;
                }
                //On verifie si du texte est entre
                else if(sfmlEvent == EventType::TextEntered)
                {
                    bindin->m_details.m_textEntered = l_event.text.unicode;
                }
                ++(bindin->c);
            }
        }
    }
}
//Permet de gerer en temps reel les changements tel que la validation ou le reset des etats des liaisons
//Comme dans HandleEvent, on va prendre tous les evenements et les liaisons.
//On ne fera ici que des traitements sur le clavier, la souris ou le joystick vu que ce sont les seuls dont
//on peut verifier l'entre en temps reel
//Comme auparavant, nous allons verifierle type d'evenement auquel nous faisons face et utilisons la classe
//appropriee pour verifier l'entree.
//Ensuite, on va verifier si le nombre d'event dans le conteneur d'evenements est egal aux nombre d'events 'active'
//Si oui, on va localiser notre callback dans m_callback et invoquer le second membre avec un operateur() pour implementer notre callback
//-> pour rappel : Callbacks = std::unordered_map<std::string,std::function<void(EventDetails*)>>
//En dernier lieu, on remet notre compteur a 0 pour la prochaine iteration car l'etat de n'importe quel event a pu change et doit donc etre reverifie
void EventManager::Update()
{
    if(!m_hasFocus)
    {
        return;
    }
    for(auto &b_itr:m_bindings)
    {
        Binding* bindin = b_itr.second;
        for(auto &e_itr : bindin->m_events)
        {
            switch(e_itr.first){
            case(EventType::Keyboard):
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(e_itr.second.m_code)))
                {
                    std::cout<<"Touche Ok"<<std::endl;
                    if(bindin->m_details.m_keyCode !=-1)
                    {
                        bindin->m_details.m_keyCode = e_itr.second.m_code;
                    }
                    ++(bindin->c);
                }
                break;
            case(EventType::MButtonDown):
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button(e_itr.second.m_code)))
                {

                        std::cout<<"Click OK"<<std::endl;
                        if(bindin->m_details.m_keyCode !=-1)
                        {
                            bindin->m_details.m_keyCode = e_itr.second.m_code;
                        }
                        ++(bindin->c);


                }
                break;
            case(EventType::Joystick):
                //Up for expansion
                break;
            /*default:
                std::cout<<"Default ma gueule"<<std::endl;
                break;*/
            }
        }
        if((int)bindin->m_events.size() == bindin->c){
            auto callItr = m_callbacks.find(bindin->m_name);
            if(callItr != m_callbacks.end())
            {
                callItr->second(&bindin->m_details);
            }
        }
        bindin->c =0;
        bindin->m_details.Clear();
    }
}
//permet de charger des liaisons depuis un fichier de donnees
void EventManager::LoadBindings()
{
    std::string delimiter =":";

    std::ifstream bindings;
    bindings.open("key.cfg");
    //On tente d'ouvrir le fichier, si on n'y arrive pas, on ecrit en console
    if(!bindings.is_open())
    {
        std::cout<<"!Failed loading key.cfg"<<std::endl;
        return;
    }
    std::string line;
    //Va servir a lire l'entierete des ligne du fichier
    while(std::getline(bindings,line))
    {
        std::stringstream keystream(line); //->Permet de morceler le string recu
        std::string callbackName;
        keystream >> callbackName; //Permet de recuperer le nom du callback -->Coupe les chaines de caracteres en utilisant les espaces comme delimiteurs par defaut
        Binding* bindin =new Binding(callbackName); //Creation de la liaison

        //on va s'assurer qu'on va lire l'ensemble de la ligne
        while(!keystream.eof())
        {
            std::string keyval;
            keystream >> keyval; //On recupere la dernier chaine de caractere correspondant a notre type d'event et son code
            int start = 0;
            int fin = keyval.find(delimiter);
            if(fin == (int)std::string::npos)
            {
                delete bindin;
                bindin = nullptr;
                break;
            }
            //On va separer les differentes informations a commencer par le type d'event
            EventType type = EventType(stoi(keyval.substr(start,fin-start)));
            //Pour la suite, on aura besoin du delimiter qu'on a defini un peu plus haut afin de bien faire la separation
            int code = stoi(keyval.substr(fin+delimiter.length(),keyval.find(delimiter,fin+delimiter.length())));
            EventInfo eventInfo;
            eventInfo.m_code = code;
            bindin->BindEvent(type,eventInfo);
        }
        if(!AddBinding(bindin))
        {
            delete bindin;
        }
        bindin = nullptr;
    }
    bindings.close();
}
