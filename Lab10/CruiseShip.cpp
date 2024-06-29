#include <iostream>
#include <string>
#include "CruiseShip.h"

using namespace std;

CruiseShip::CruiseShip() : Ship(), maximumPassengers(0)
{
    cout << "CruiseShip's default constructor" << endl;
}
CruiseShip::CruiseShip(string _name, string _year, int _passengers) : Ship(_name, _year), maximumPassengers(_passengers)
{
    cout << "CruiseShip's parameterized constructor" << endl;
}
CruiseShip::CruiseShip(const CruiseShip &obj) : Ship(obj), maximumPassengers(obj.maximumPassengers)
{
    cout << "CruiseShip's copy constructor" << endl;
}
CruiseShip::~CruiseShip()
{
    cout << "CruiseShip's Destructor" << endl;
}
void CruiseShip::setMaximumPassengers(int _maximumPassengers)
{
    maximumPassengers = _maximumPassengers;
}
int CruiseShip::getMaximumPassengers() const
{
    return maximumPassengers;
}
void CruiseShip::setName(string _name)
{
    Ship::setName(_name);
}
void CruiseShip::setYear(string _year)
{
    Ship::setYear(_year);
}
string CruiseShip::getName() const
{
    return Ship::getName();
}
string CruiseShip::getYear() const
{
    return Ship::getYear();
}
void CruiseShip::printData() const
{
    Ship::printData();
    cout << "Maximum Passengers: " << maximumPassengers << endl;
}
