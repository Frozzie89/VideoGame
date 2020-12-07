#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Game.h"

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
