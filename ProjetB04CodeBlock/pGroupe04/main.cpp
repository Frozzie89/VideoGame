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

    Enemy e;
    Enemy e2;
    EnemyAbilityDefensive abilityDefensive1("ad1", 1, true);
    EnemyAbilityDefensive abilityDefensive2("ad2", 1, true);
    EnemyAbilityDefensive abilityDefensive3("ad3", 1, true);
    EnemyAbilityDefensive abilityDefensive4("ad4", 1, true);
    EnemyAbilityDefensive abilityDefensive5("ad5", 1, true);
    EnemyAbilityDefensive abilityDefensive6("ad6", 1, true);
    EnemyAbilityDefensive abilityDefensive7("ad7", 1, true);
    EnemyAbilityDefensive abilityDefensive8("ad8", 1, true);
    EnemyAbilityDefensive abilityDefensive9("ad9", 1, true);
    EnemyAbilityDefensive abilityDefensive10("ad10", 1, true);

    EnemyAbilityOffensive abilityOffensive1("ao1", 1);
    EnemyAbilityOffensive abilityOffensive2("ao2", 1);
    EnemyAbilityOffensive abilityOffensive3("ao3", 1);
    EnemyAbilityOffensive abilityOffensive4("ao4", 1);
    EnemyAbilityOffensive abilityOffensive5("ao5", 1);
    EnemyAbilityOffensive abilityOffensive6("ao6", 1);
    EnemyAbilityOffensive abilityOffensive7("ao7", 1);
    EnemyAbilityOffensive abilityOffensive8("ao8", 1);
    EnemyAbilityOffensive abilityOffensive9("ao9", 1);
    EnemyAbilityOffensive abilityOffensive10("ao10", 1);

    BehaviourHighLife b;

    e.setStrategy(&b);

    e.addAbilities(&abilityDefensive1);
    e.addAbilities(&abilityDefensive2);
    e.addAbilities(&abilityDefensive3);
    e.addAbilities(&abilityDefensive4);
    e.addAbilities(&abilityDefensive5);
    e.addAbilities(&abilityDefensive6);
    e.addAbilities(&abilityDefensive7);
    e.addAbilities(&abilityDefensive8);
    e.addAbilities(&abilityDefensive9);
    e.addAbilities(&abilityDefensive10);
    cout<<endl;
    e.addAbilities(&abilityOffensive1);
    e.addAbilities(&abilityOffensive2);
    e.addAbilities(&abilityOffensive3);
    e.addAbilities(&abilityOffensive4);
    e.addAbilities(&abilityOffensive5);
    e.addAbilities(&abilityOffensive6);
    e.addAbilities(&abilityOffensive7);
    e.addAbilities(&abilityOffensive8);
    e.addAbilities(&abilityOffensive9);
    e.addAbilities(&abilityOffensive10);

    cout<<"Enemy 1" <<endl;
    e.getCharacteristicsValue();
    cout<<"Enemy 2" <<endl;
    e2.getCharacteristicsValue();

    for(int i = 0; i<50; i++){
        cout<<"\nUseAbility"<<endl;
        e.useAbility(e2);

        cout<<"Enemy 1" <<endl;
        e.getCharacteristicsValue();
        cout<<"Enemy 2" <<endl;
        e2.getCharacteristicsValue();
    }



/*
    Game game;

    // Start the game loop
    while (!game.GetWindow()->isDone())
    {
        game.Update();
        game.Render();
        game.LateUpdate();
    }
    return EXIT_SUCCESS;
*/
}
