#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include <iostream>
#include <string>
using namespace std;
#include "Ship.h" // Include the Ship header file

class CargoShip : public Ship {
private:
    int capacity;

public:
    CargoShip();
    CargoShip(string _name, string _year, int _capacity);
    CargoShip(const CargoShip& obj);
    ~CargoShip() override;

    void setCapacity(int _capacity);
    int getCapacity() const;
    void setName(string _name);
    void setYear(string _year);
    string getName() const;
    string getYear() const;
    void printData() const override;
};

#endif // CARGOSHIP_H

