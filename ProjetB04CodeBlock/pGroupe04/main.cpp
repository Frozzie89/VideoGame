#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
#include <string>

#include "Game.h"
#include "Entity/Player/Warrior.h"
#include "Fight.h"
#include "Entity/Characteristics/Characteristic.h"
#include "Entity/Characteristics/Characteristics.h"
#include "Cards/DefensiveCardWarrior.h"
#include "Cards/OffensiveCardWarrior.h"

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
