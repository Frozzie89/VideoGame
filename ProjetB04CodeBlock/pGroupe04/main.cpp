#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
#include <string>

#include "Game.h"
#include "Entity/Player/Warrior.h"
#include "Fight.h"
#include "Entity/Characteristics/Characteristic.h"
#include "Entity/Characteristics/Characteristics.h"

using namespace std;

int main()
{
    Warrior *w1 = new Warrior();
    Fight f1(w1);


    // Game game;

    // DefensiveCardWarrior dcw("Coucou", "chapitre4.jpg", 0, 0, game.GetContext(), true);

    // cout << dcw.str() << endl;
    // dcw.SetSpritePosition(3.0f, 4.0f);
    // cout << dcw.str() << endl;
    // dcw.SetSpritePositon(sf::Vector2f(12.0f, 765.0f));
    // cout << dcw.str() << endl;

    // // Start the game loop
    // while (!game.GetWindow()->isDone())
    // {
    //     game.Update();
    //     game.Render();
    //     game.LateUpdate();
    // }

    return EXIT_SUCCESS;
}
