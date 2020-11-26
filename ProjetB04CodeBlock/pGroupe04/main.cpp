#include <SFML/Graphics.hpp>
#include "Game.h"

#include "Entity/Health.h"
#include "Entity/Shield.h"
#include "Entity/Characteristics.h"
#include "Cards/DefensiveCardWarrior.h"
#include "Cards/OffensiveCardGambler.h"

#include <iostream>
using namespace std;
int main()
{
    Game game;

    DefensiveCardWarrior dcw1("coucou", "assets/test.png", 5, 4, false);

    cout << dcw1.str() << endl;
    dcw1.draw(*game.GetWindow(),sf::RenderStates::Default);

    // Start the game loop
    while (!game.GetWindow()->isDone())
    {
        game.HandleInput();
        game.Update();
        game.Render();
        //sf::sleep(sf::seconds(0.2)); // Sleep for 0.2 seconds
        game.RestartClock();
    }
    return EXIT_SUCCESS;
}
