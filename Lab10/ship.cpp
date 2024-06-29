#include <iostream>
#include <string>
#include "ship.h"

using namespace std;

// Remove the class definition for Ship here

// Constructor definitions
Ship::Ship() : name(""), year("") 
{
    cout << "Ship's default constructor" << endl;
}

Ship::Ship(string _name, string _year) : name(_name), year(_year)
{
    cout << "Ship's parameterized constructor" << endl;
}

Ship::Ship(const Ship& obj) : name(obj.name), year(obj.year)
{
    cout << "Ship's copy constructor" << endl;
}

// Destructor definition
Ship::~Ship() 
{
    cout << "Ship's destructor" << endl;
}

// Member function definitions
void Ship::setName(string _name)
{
    name = _name;
}

void Ship::setYear(string _year)
{
    year = _year;
}

string Ship::getName() const
{
    return name;
}

string Ship::getYear() const
{
    return year;
}

void Ship::printData() const
{
    cout << "Name: " << name << endl;
    cout << "Year: " << year << endl;
}
