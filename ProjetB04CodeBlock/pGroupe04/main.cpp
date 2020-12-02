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

    DefensiveCardWarrior dcw("Coucou", "chapitre4.jpg", 0, 0,game.GetContext(), true);

    cout<<dcw.str()<<endl;
    dcw.SetSpritePosition(3.0f,4.0f);
    cout<<dcw.str()<<endl;
    dcw.SetSpritePositon(sf::Vector2f(12.0f,765.0f));
    cout<<dcw.str()<<endl;


    // Start the game loop
    while (!game.GetWindow()->isDone())
    {
        game.Update();
         game.Render();
        game.LateUpdate();

    }

    return EXIT_SUCCESS;

}
