#include <SFML/Graphics.hpp>
#include "Game.h"

#include "Entity/Health.h"
#include "Entity/Shield.h"
#include "Entity/Characteristics.h"

#include <iostream>
using namespace std;
int main()
{
    Game game;
    Health h(150);
    Shield s(20);

    cout<<h.str()<<endl;
    cout<<s.str()<<endl;
    h.RaiseValue(15);
    s.LowerValue(10);
    cout<<h.str()<<endl;
    cout<<s.str()<<endl;
    Characteristics c;
    c.AddCharacteristic(&h);
    cout<<c.getCharacteristics()<<endl;
    c.AddCharacteristic(&s);
    cout<<c.getCharacteristics()<<endl;
    c.AddCharacteristic(&h);
    cout<<c.getCharacteristics()<<endl;



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
