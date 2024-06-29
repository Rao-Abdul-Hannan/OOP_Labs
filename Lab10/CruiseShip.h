#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include <iostream>
#include <string>
using namespace std;
#include "Ship.h" // Include the Ship header file

class CruiseShip : public Ship {
private:
    int maximumPassengers;

public:
    CruiseShip();
    CruiseShip(string _name, string _year, int _passengers);
    CruiseShip(const CruiseShip& obj);
    ~CruiseShip() override;

    void setMaximumPassengers(int _maximumPassengers);
    int getMaximumPassengers() const;
    void setName(string _name);
    void setYear(string _year);
    string getName() const;
    string getYear() const;
    void printData() const override;
};

#endif // CRUISESHIP_H
