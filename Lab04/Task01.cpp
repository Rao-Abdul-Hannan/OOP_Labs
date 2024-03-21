#include <iostream>
using namespace std;

class Bus 
{
    private:
        string busNumber, owner;
        int capacity;
    
    public:

        // Default constructor
        Bus () : busNumber(" "), owner (" "), capacity (0)
        {
            cout << "Default constructor" << endl;
        }

        // Parameterized constructor
        Bus (string busNumber, string owner, int capacity = 0)
        {
            this->busNumber = busNumber;
            this->owner = owner;
            this->capacity = capacity;

            cout << "Parameterized Constructor called" << endl;
        }

        // Copy constructor
        Bus (const Bus& bus) : busNumber(bus.busNumber), owner(bus.owner), capacity(bus.capacity)
        {
            cout << "Copy constructor called" << endl;
        }

        // Destructor
        ~Bus ()
        {
            cout << "Destructor executed" << endl;
        }

        // Getter Functions
        void getBus ()
        {
            cout << "Enter Bus license number: ";
            getline (cin, busNumber);

            cout << "Enter Owner name: ";
            getline (cin, owner);

            cout << "Enter Capacity: ";
            cin >> capacity;

            cin.ignore();
        }

        string getBusNumber ()
        {
            return this->busNumber;
        }

        string getOwner ()
        {
            return this->owner;
        }

        int getCapacity ()
        {
            return this->capacity;
        }

        // Setter Functions
        void setBus (string busNumber, string owner, int capacity)
        {
            this->busNumber = busNumber;
            this->owner = owner;
            this->capacity = capacity;
        }

        void setBusNumber (string busNumber)
        {
            this->busNumber = busNumber;
        }

        void setOwner (string owner)
        {
            this->owner = owner;
        }

        void setCapacity (int capacity)
        {
            this->capacity = capacity;
        }

        // Put Function 
        void putBus ()
        {
            cout << this->busNumber << "\t" << this->owner << "\t" << this->capacity << endl;
        }

        // Book Method
        void book ()
        {
            this->capacity = (this->capacity) + 1;
        }

        // Cancel Method
        void cancel ()
        {
            this->capacity = (this->capacity) - 1;
        }
};

int main()
{
    Bus bus1, bus2("Bus", "Company"), bus3(bus2), bus4, bus5("Bus", "Company");

    bus1.getBus();
    bus2.getBus();
    bus3.getBus();
    bus4.getBus();
    bus5.getBus();

    cout << "Bus Number\tOwner\tCapacity" << endl;
    bus1.putBus();
    bus2.putBus();
    bus3.putBus();
    bus4.putBus();
    bus5.putBus();

    bus1.setBus("AK5-4567", "Shalimar", 45);
    bus2.setBusNumber("PK47-1857");
    bus2.setOwner("Abdul-Hannan");
    bus2.setCapacity(50);

    cout << "Bus Number: " << bus1.getBusNumber() << endl;
    cout << "Owner: " << bus1.getOwner() << endl;
    cout << "Capacity: " << bus1.getCapacity() << endl;
    

    bus1.book();
    bus2.cancel();

    cout << "Bus Number\tOwner\tCapacity" << endl;
    bus1.putBus();
    bus2.putBus();
    bus3.putBus();
    bus4.putBus();
    bus5.putBus();

    return 0;
}