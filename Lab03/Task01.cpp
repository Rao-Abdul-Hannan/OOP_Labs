#include <iostream>
using namespace std;

int main()
{
    int *ptrX = nullptr, *ptrY = nullptr;

    ptrX = new int{2};
    ptrY = new int{8};

    cout << "Address of ptrX: ";
    cout << &ptrX << endl;

    cout << "Value in ptrX: ";
    cout << ptrX << endl;

    cout << "Address at which ptrX is pointing: ";
    cout << &(*ptrX) << endl;

    cout << "Value at the pointed address: ";
    cout << *ptrX << endl;
    
    cout << "Address of ptrY: ";
    cout << &ptrY << endl;

    cout << "Value in ptrY: ";
    cout << ptrY << endl;

    cout << "Address at which ptrY is pointing: ";
    cout << &(*ptrY) << endl;

    cout << "Value at the pointed address: ";
    cout << *ptrY << endl;

    delete ptrX;
    delete ptrY;
    return 0;
}