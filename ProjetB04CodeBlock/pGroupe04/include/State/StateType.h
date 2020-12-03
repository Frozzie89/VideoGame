#ifndef STATETYPE_H
#define STATETYPE_H

//Permet de definir les differents types de states que l'on va retrouver dans l'application
enum class StateType
{
    Intro = 1,
    MainMenu,
    Game,
    Paused,
    GameOver,
    Credits,
    Option
};

#endif // STATETYPE_H
