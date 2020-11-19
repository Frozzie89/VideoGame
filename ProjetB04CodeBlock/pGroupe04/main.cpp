#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    Game game;
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
