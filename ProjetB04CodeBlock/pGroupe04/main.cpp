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

    // Warrior *w1 = new Warrior(15);
    // // DefensiveCardWarrior dcw1("HEAL", "NOPATH", 2, 5, nullptr, true);
    // DefensiveCardWarrior dcw1("SHIELD", "NOPATH", 2, 5, nullptr, false);
    // w1->addCard(&dcw1, Warrior::hand);
    // Fight f1(w1);

    // f1.getEnemy().useAbility(*w1);
    // cout << f1.getPlayer().str() << endl;

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
