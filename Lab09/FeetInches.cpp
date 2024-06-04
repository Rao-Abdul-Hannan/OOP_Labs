#include "iostream"

using namespace std;

class FeetInches
{
private:
    int feet;          // To hold a number of feet
    int inches;        // To hold a number of inches

    // Private member function to simplify the values in feet and inches
    void simplify()
    {
        if (inches >= 12)
        {
            feet += (inches / 12);
            inches = inches % 12;
        }
        else if (inches < 0)
        {
            feet -= ((abs(inches) / 12) + 1);
            inches = 12 - (abs(inches) % 12);
        }
    }

public:
    // Constructor
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }

    // Copy constructor
    FeetInches(const FeetInches& right)
    {
        feet = right.feet;
        inches = right.inches;
        simplify();
    }

    // Mutator function to set feet
    void setFeet(int f)
    {
        feet = f;
    }

    // Mutator function to set inches
    void setInches(int i)
    {
        inches = i;
        simplify();
    }

    // Accessor function to get feet
    int getFeet() const
    {
        return feet;
    }

    // Accessor function to get inches
    int getInches() const
    {
        return inches;
    }

    // Overloaded + operator
    FeetInches operator + (const FeetInches& right)
    {
        FeetInches temp;

        temp.inches = inches + right.inches;
        temp.feet = feet + right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded - operator
    FeetInches operator - (const FeetInches& right)
    {
        FeetInches temp;

        temp.inches = inches - right.inches;
        temp.feet = feet - right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded * operator
    FeetInches operator * (const FeetInches& right)
    {
        FeetInches temp;

        temp.inches = inches * right.inches;
        temp.feet = feet * right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded prefix ++ operator
    FeetInches operator ++ ()
    {
        ++inches;
        simplify();

        return *this;
    }

    // Overloaded postfix ++ operator
    FeetInches operator ++ (int)
    {
        FeetInches temp(feet, inches);

        inches++;
        simplify();

        return temp;
    }

    // Overloaded prefix -- operator
    FeetInches operator -- ()
    {
        --inches;
        simplify();

        return *this;
    }

    // Overloaded postfix -- operator
    FeetInches operator -- (int)
    {
        FeetInches temp(feet, inches);

        inches--;
        simplify();

        return temp;
    }

    // Overloaded > operator
    bool operator > (const FeetInches& right) const
    {
        bool status;

        if (feet > right.feet)
            status = true;
        else if (feet == right.feet && inches > right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded < operator
    bool operator < (const FeetInches& right) const
    {
        return !(*this > right);
    }

    // Overloaded >= operator
    bool operator >= (const FeetInches& right) const
    {
        bool status;

        if (feet >= right.feet)
            status = true;
        else if (feet == right.feet && inches >= right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded <= operator
    bool operator <= (const FeetInches& right) const
    {
        return !(*this >= right);
    }

    // Overloaded == operator
    bool operator == (const FeetInches& right) const
    {
        bool status;

        if (feet == right.feet && inches == right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded != operator
    bool operator != (const FeetInches& right) const
    {
        return !(*this == right);
    }

    // Friend function to overload << operator for output
    friend ostream& operator << (ostream&, const FeetInches&);

    // Friend function to overload >> operator for input
    friend istream& operator >> (istream&, FeetInches&);
};

// Overloaded << operator
ostream& operator << (ostream& out, const FeetInches& obj)
{
    out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

    return out;
}

// Overloaded >> operator
istream& operator >> (istream& in, FeetInches& obj)
{
    cout << "Enter Feet:\t";
    in >> obj.feet;

    cout << "Enter Inches:\t";
    in >> obj.inches;

    return in;
}

// Room Dimensions
class RoomDimension 
{
    private:
        FeetInches length, width;
    public:
        RoomDimension(FeetInches _ob1, FeetInches _ob2) : length(_ob1), width(_ob2)  // Parameterized Constructor 
    {}  

    void setLength(FeetInches _length)
    {
        this -> length.setFeet(_length.getFeet());
        this -> length.setInches(_length.getInches());
    }

    void setWidth(FeetInches _width)
    {
        this -> width.setFeet(_width.getFeet());
        this -> width.setInches(_width.getInches());
    }

    FeetInches getLength() const
    {
        return length;
    }

    FeetInches getWidth() const
    {
        return width;
    }

    FeetInches getArea () const
    {
        FeetInches area;
        area.setFeet((this -> length.getFeet()) * this -> width.getFeet());
        area.setInches(this -> length.getInches() * this -> width.getInches());

        return area;
    }

    void displayLenghtWidth() const
    {
        cout << "Length: " << this -> length.getFeet() << " feets " << this -> length.getInches() << " inches" << endl;
        cout << "Width: " << this -> width.getFeet() << " feets " << this -> width.getInches() << " inches" << endl;
    }

    ~RoomDimension () { }

};

class RoomCarpet 
{
    private:
        RoomDimension roomSize;
        float costPerSquareFoot;

    public:
        RoomCarpet (RoomDimension _ob1, float _cost) : roomSize (_ob1), costPerSquareFoot(_cost) { }

        void setRoomSize (RoomDimension _roomSize)
        {
            this -> roomSize.setLength(_roomSize.getLength());
            this -> roomSize.setWidth(_roomSize.getWidth());  
        }

        void setCostPerSquareFoot (float _costPerSquareFoot)
        {
            this -> costPerSquareFoot = _costPerSquareFoot;
        }

        RoomDimension getRoomSize () const
        {
            return this -> roomSize;
        }

        float getCostPerSquareFoot () const
        {
            return this -> costPerSquareFoot;
        }

        float totalCost () const 
        {
            FeetInches area = roomSize.getArea();
            return area.getFeet() * costPerSquareFoot;
        }

        void display () const
        {
            roomSize.displayLenghtWidth();
            cout << "Cost per square foot: " << this -> costPerSquareFoot << endl;
        }

};

int main ()
{
    FeetInches ob1 (12, 10), ob2 (25, 15);
    RoomDimension room1(ob1, ob2);
    RoomCarpet obj (room1, 25);

    obj.display();
    cout << room1.getArea() << endl;

    float cost = obj.totalCost();
    cout << cost << endl;

    // room1.displayLenghtWidth();

    // room1.setLength({13, 15});

    // room1.display(); 

    // cout << room1.getWidth() << endl;


    return 0;
}