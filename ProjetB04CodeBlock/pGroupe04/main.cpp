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
    Enemy e1 (25, "assets/enemies/fox.png");
    Enemy e2 (25, "assets/enemies/fox.png");

    EnemyAbilityDefensive *ead1_1 = new EnemyAbilityDefensive("Sleep", 5, true);
    EnemyAbilityDefensive *ead1_2 = new EnemyAbilityDefensive("Hide", 3, false);
    EnemyAbilityOffensive *eao1_1 = new EnemyAbilityOffensive("Bite", 5);
    EnemyAbilityOffensive *eao1_2 = new EnemyAbilityOffensive("Scratch", 3);

    e1.addAbilities(ead1_1);
    e1.addAbilities(ead1_2);
    e1.addAbilities(eao1_1);
    e1.addAbilities(eao1_2);

    cout<<"E1: \t Health"<< e1.getHealth() << "\t\t Shield :"<<e1.getShield()<<endl;
    cout<<"E2: \t Health"<< e2.getHealth() << "\t\t Shield :"<<e2.getShield()<<endl;

    e1.useAbility(e2);

    cout<<"E1: \t Health"<< e1.getHealth() << "\t Shield :"<<e1.getShield()<<endl;
    cout<<"E2: \t Health"<< e2.getHealth() << "\t Shield :"<<e2.getShield()<<endl;





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
