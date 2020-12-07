#ifndef BASESTATE_H
#define BASESTATE_H

#include <SFML/Graphics.hpp>

class StateManager;
/*
    Cette classe va definir ce que l'on va retrouver dans les differents state du jeu
    Cette classe a besoin du stateManager afin
    Parmi ses attributs, on retrouve une police de caracteres, un element Texte nous permettant d'afficher du texte a l'ecran, le temps passe sur le dit state,
    une texture pour le background ainsi qu'un sprite pour celui-ci, deux rectangles permettant de connaitre la vie restante de l'ennemie et un bouton permettant de terminer le tour
*/
class BaseState
{

    friend class StateManager;

public:
    BaseState(StateManager *l_stateManager); //Cosntructeur
    virtual ~BaseState();                    //Destructeur

    virtual void OnCreate() = 0;  //Permet de creer les differents elements graphiques que l'on va retrouver dans la fenetre
    virtual void OnDestroy() = 0; //Permet de supprimer les callbacks afin de liberer la memoire allouee a cet effet

    virtual void Activate() = 0;   //Methode qui d'activer certaines modifications si la state a deja ete utilisee
    virtual void Deactivate() = 0; //Permet de supprimer les modifications si la state n'est plus utilisee

    virtual void Update(const sf::Time &l_time) = 0; //Met a jour ce qui est a l'ecran
    virtual void Draw() = 0;                         //Permet de dessiner les differents elements graphiques

    void SetTransparent(const bool &l_transparent) { m_transparent = l_transparent; } //Permet de modifier la transparence de l'ecran
    bool IsTransparent() const { return m_transparent; }                              //Permet de savoir si l'ecran est transparent ou non
    void SetTranscendent(const bool &l_transcendent) { m_transcendent = l_transcendent; } //Permet de modifier le fait que l'ecran puisse transmettre des informations a un autre ecran ou non
    bool IsTranscendent() const { return m_transcendent; } // Permet de savoir si on peut transmettre des informations a un autre ecran

    StateManager *GetStateManager() { return m_stateMgr; } //Permet de retourner le statemanager

protected:
    StateManager *m_stateMgr; //le statemanager
    bool m_transparent;       //Permet de definir ce qui est
    bool m_transcendent; //Autorise le transfere d'information sur d'autres ecrans
};
#endif // BASESTATE_H
