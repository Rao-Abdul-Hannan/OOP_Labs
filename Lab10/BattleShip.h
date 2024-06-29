#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include <string>
using namespace std;
#include "Ship.h" // Include the Ship header file

class BattleShip : public Ship {
private:
    int numOfMissiles;

public:
    BattleShip();
    BattleShip(std::string _name, std::string _year, int _numOfMissiles);
    BattleShip(const BattleShip& obj);
    ~BattleShip() override;

    void setNumOfMissiles(int _numOfMissiles);
    int getNumOfMissiles() const;
    void setName(std::string _name);
    void setYear(std::string _year);
    std::string getName() const;
    std::string getYear() const;
    void printData() const override;
};

#endif // BATTLESHIP_H
