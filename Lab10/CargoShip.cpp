#include <iostream>
#include <string>
#include "CargoShip.h"

using namespace std;

CargoShip::CargoShip() : Ship(), capacity(0)
{
    cout << "CargoShip's default constructor" << endl;
}
CargoShip::CargoShip(string _name, string _year, int _capacity) : Ship(_name, _year), capacity(_capacity)
{
    cout << "CargoShip's parameterized constructor" << endl;
}
CargoShip::CargoShip(const CargoShip &obj) : Ship(obj), capacity(obj.capacity)
{
    cout << "CargoShip's copy constructor" << endl;
}
CargoShip::~CargoShip()
{
    cout << "CargoShip's destructor" << endl;
}
void CargoShip::setCapacity(int _capacity)
{
    capacity = _capacity;
}
int CargoShip::getCapacity() const
{
    return capacity;
}
void CargoShip::setName(string _name)
{
    Ship::setName(_name);
}
void CargoShip::setYear(string _year)
{
    Ship::setYear(_year);
}
string CargoShip::getName() const
{
    return Ship::getName();
}
string CargoShip::getYear() const
{
    return Ship::getYear();
}
void CargoShip::printData() const
{
    Ship::printData();
    cout << "Capacity: " << capacity << endl;
}
