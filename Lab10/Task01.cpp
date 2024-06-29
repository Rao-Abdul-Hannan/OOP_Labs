#include <iostream>
#include <string>
#include "ship.h"
#include "CargoShip.h"
#include "BattleShip.h"
#include "CruiseShip.h"

using namespace std;

int main()
{
    Ship *ship1 = new Ship{"Ship", "1914"};
    Ship *ship2 = new CruiseShip{"Titanic", "1978", 1500};
    Ship *ship3 = new CargoShip{"HMS", "1957", 3000};
    Ship *ship4 = new BattleShip{"Badr", "2000", 5000};

    Ship* ships[] = { ship1, ship2, ship3, ship4 };

    for (int i = 0; i < 4; i++)
    {
        ships[i] -> printData();
    }

    for (int i = 0; i < 4; i++)
    {
        delete ships[i];
    }

    return 0;
}