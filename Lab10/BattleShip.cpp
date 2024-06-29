#include <iostream>
#include <string>
#include "BattleShip.h"

using namespace std;

BattleShip::BattleShip() : Ship(), numOfMissiles(0)
{
    cout << "BattleShip's default constructor" << endl;
}
BattleShip::BattleShip(string _name, string _year, int _numOfMissiles) : Ship(_name, _year), numOfMissiles(_numOfMissiles)
{
    cout << "BattleShip's parameterized Constructor" << endl;
}
BattleShip::BattleShip(const BattleShip &obj) : Ship(obj), numOfMissiles(obj.numOfMissiles)
{
    cout << "BattleShip's copy constructor" << endl;
}
BattleShip::~BattleShip()
{
    cout << "BattleShip's destructor" << endl;
}
void BattleShip::setNumOfMissiles(int _numOfMissiles)
{
    numOfMissiles = _numOfMissiles;
}
int BattleShip::getNumOfMissiles() const
{
    return numOfMissiles;
}
void BattleShip::setName(string _name)
{
    Ship::setName(_name);
}
void BattleShip::setYear(string _year)
{
    Ship::setYear(_year);
}
string BattleShip::getName() const
{
    return Ship::getName();
}
string BattleShip::getYear() const
{
    return Ship::getYear();
}
void BattleShip::printData() const
{
    Ship::printData();
    cout << "NumOfMissiles: " << numOfMissiles << endl;
}
