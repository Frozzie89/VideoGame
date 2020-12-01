#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Game.h"
#include "Cards/DefensiveCardWarrior.h"
#include "Entity/Enemy/Enemy.h"
#include "Entity/Enemy/EnemyAbility.h"

#include <iostream>
using namespace std;
int main()
{
    Enemy e;
    EnemyAbilityDefensive ability;

    cout<<e.getClassName()<<endl;
    cout<<ability.getClassName()<<endl;

    e.addAbilities(&ability);

    e.removeAbilities(&ability);


    /*
    Game game;

    // Start the game loop
    while (!game.GetWindow()->isDone())
    {
        game.Update();
        game.Render();
        game.LateUpdate();
    }
    return EXIT_SUCCESS;
    */
}
