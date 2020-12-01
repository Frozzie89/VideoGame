#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
#include "Game.h"
#include "Cards/DefensiveCardWarrior.h"


#include "Entity/Enemy/Enemy.h"
#include "Entity/Enemy/EnemyAbility.h"
#include "Entity/Enemy/BehaviourHighLife.h"

using namespace std;
int main()
{
    Game game;

    // Start the game loop
    while (!game.GetWindow()->isDone())
    {
        game.Update();
        game.Render();
        game.LateUpdate();
    }
    return EXIT_SUCCESS;

}
