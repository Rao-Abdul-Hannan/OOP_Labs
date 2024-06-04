#include <iostream>
using namespace std;

class Ball
{
private:
    int id, quantity;
    string name;
    float price;

public:
    Ball(int id, string name, int quantity, float price) : id(id), name(name), quantity(quantity), price(price)
    {
        if (id < 0)
        {
            this->id = 0;
        }
        if (quantity < 0)
        {
            this->quantity = 0;
        }
        if (price < 0)
        {
            this->price = 0;
        }
    }

    Ball(int id, string name, int quantity) : id(id), name(name), quantity(quantity), price(0)
    {
        if (id < 0)
        {
            this->id = 0;
        }
        if (quantity < 0)
        {
            this->quantity = 0;
        }
    }

    Ball(int id, string name, float price) : id(id), name(name), price(price), quantity(0)
    {
        if (id < 0)
        {
            this->id = 0;
        }
        if (price < 0)
        {
            this->price = 0;
        }
    }

    Ball(const Ball &obj) : id(obj.id), name(obj.name), quantity(obj.quantity), price(obj.price)
    {
    }

    ~Ball()
    {
        cout << "Destructor Executed" << endl;
    }

    // Setters
    void setId(const int id)
    {
        if (id >= 0)
        {
            this->id = id;
        }
    }

    void setName(const string name)
    {
        this->name = name;
    }

    void setQuantity(const int quantity)
    {
        if (quantity >= 0)
        {
            this->quantity = quantity;
        }
    }

    void setPrice(const float price)
    {
        if (price >= 0)
        {
            this->price = price;
        }
    }

    // Getters
    int getId() const
    {
        return this->id;
    }

    string getName() const
    {
        return this->name;
    }

    int getQuantity() const
    {
        return this->quantity;
    }

    float getPrice() const
    {
        return this->price;
    }

    // Member Functions
    void setBall(const int id, const string name, const int quantity, const float price)
    {
        setId(id);
        setName(name);
        setQuantity(quantity);
        setPrice(price);
    }

    void getBall()
    {
        cout << "Enter Id: ";
        cin >> this->id;
        setId(this->id);

        cout << "Enter Name: ";
        cin >> this->name;
        setName(this->name);

        cout << "Enter Quantity: ";
        cin >> this->quantity;
        setQuantity(this->quantity);

        cout << "Enter Price: ";
        cin >> this->price;
        setPrice(this->price);
    }

    void putBall() const
    {
        cout << this->id << "\t" << this->name << "\t" << this->quantity << "\t\t" << this->price << "\n";
    }

    int getTotalPrice() const
    {
        return (this->price) * (this->quantity);
    }

    bool isSame(const Ball &obj) const
    {
        if ((this->id == obj.id) && (this->name == obj.name) && (this->quantity == obj.quantity) && (this->price == obj.price))
        {
            return true;
        }

        return false;
    }

    void updateName(Ball arr[], int SIZE) const
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (this -> id == arr[i].id)
            {
                arr[i].name = this -> name;
            }
        }
    }

    Ball getMaximumPriceBall (const Ball arr[], const int SIZE) const
    {
        int max = arr[0].price, object = 0, i = 1;
        for (i = 1; i < SIZE; i++)
        {
            if (arr[0].price > max)
            {
                max = arr[0].price;
                object = i;
            }
        }
        return arr[object];
    }

    void getAveragePrice (const Ball arr[], const int SIZE)
    {
        int sum = 0, count = 0;

        for (int i = 0; i < SIZE; i++)
        {
            if (arr[i].price <= 50)
            {
                sum += arr[i].price;
                count++;
            }
        }

        this -> price = (float)sum / count;
    }
};

int main()
{
    Ball arr[3]{Ball(50, "adidas", 27, 3.5), Ball(-2, "reebok", 25), Ball(23, "nike", (float)-25.72)};
    Ball obj(arr[0]);

    cout << "Id\tName\tQuantity\tPrice\n";
    for (int i = 0; i < 3; i++)
    {
        arr[i].putBall();
    }

    arr[1].setId(50);
    arr[1].setPrice (15);
    arr[2].setQuantity (10);
    arr[2].setPrice (50);

    cout << "Id\tName\tQuantity\tPrice\n";
    for (int i = 0; i < 3; i++)
    {
        arr[i].putBall();
    }

    cout << "Total Price: ";
    cout << arr[1].getTotalPrice() << endl;

    if (obj.isSame(arr[0]))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    obj.updateName(arr, 3);

    cout << "Id\tName\tQuantity\tPrice\n";
    for (int i = 0; i < 3; i++)
    {
        arr[i].putBall();
    }

    cout << "Maximum Price Ball" << endl;
    Ball r = arr->getMaximumPriceBall(arr, 3);
    r.putBall();

    cout << "Average Price Ball" << endl;
    r.getAveragePrice(arr, 3);
    r.putBall();
    return 0;
}