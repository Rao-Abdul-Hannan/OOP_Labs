#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>
using namespace std;

class Ship {
private:
    string name, year;

public:
    Ship();
    Ship(string _name, string _year);
    Ship(const Ship& obj);
    virtual ~Ship();
    
    void setName(string _name);
    void setYear(string _year);
    string getName() const;
    string getYear() const;
    virtual void printData() const;
};

#endif // SHIP_H



