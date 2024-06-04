#include <iostream>
using namespace std;

template <typename T>
class GenericArray
{
private:
    T *array;
    int size;

public:
    GenericArray() : size(5) // default constructor
    {
        array = new T[size]{0};
    }

    GenericArray(const int &size) : size(size) // paramerized constructor with default array values
    {
        this->array = new T[size]{0};
    }

    GenericArray(const GenericArray &other) : size(other.size) // copy constructor
    {
        this->array = new T[size];

        for (int i = 0; i < size; i++)
        {
            array[i] = other.array[i];
        }
    }

    ~GenericArray() // destructor
    {
        delete[] array;
    }

    int getSize() const // get size member function, not static because of lhs object
    {
        return this->size;
    }

    void setElement(const int &index, const T &value)
    {
        if (index < size && index >= 0)
        {
            this->array[index] = value;
        }
        else
        {
            throw out_of_range{"Error: Index out of bounds."};
        }
    }

    void printArray() const
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << this->array[i] << "\t";
        }
        cout << endl;
    }

    int countElement(const T &key) const
    {
        int count = 0;

        for (int i = 0; i < this->size; i++)
        {
            if (this->array[i] == key)
            {
                count++;
            }
        }

        return count;
    }

    GenericArray &operator=(const GenericArray &other)
    {
        if (this != &other)
        {
            delete[] this->array;

            this->size = other.size;

            this->array = new T[size];

            for (int i = 0; i < size; i++)
            {
                this->array[i] = other.array[i];
            }
        }

        return *this;
    }

    GenericArray& operator+(const GenericArray &other)
    {
        int tempSize = this -> size + other.size;
        T* tempArray = new T[tempSize];
        int j = 0;
        for (int i = 0; i < tempSize; i++)
        {
            if (i < this -> size)
            {
                tempArray[i] = this -> array[i];
            }
            else
            {
                tempArray[i] = other.array[j++];
            }
        }

        this -> size = tempSize;

        delete[] this->array;
        this -> array = new T[size];

        for (int i = 0; i < size; i++)
        {
            this -> array[i] = tempArray[i];
        }

        delete[] tempArray;
        return *this;
    }

    T *getSubArray(const int &startIndex, const int &endIndex) const
    {
        if (startIndex >= 0 && startIndex < this->size && endIndex >= 0 && endIndex < this->size && startIndex <= endIndex)
        {
            T *subArray = new T[(endIndex - startIndex) + 1];
            int j = 0;
            for (int i = startIndex; i <= endIndex; i++)
            {
                subArray[j++] = this->array[i];
            }
            return subArray;
        }
        throw out_of_range{"Error index out of bounds"};
    }

    friend ostream& operator<< (ostream& out, const GenericArray<T>& other)
    {
        for (int i = 0; i < other.size; i++)
        {
            out << other.array[i] << "\t";
        }
        cout << endl;
        return out;
    }

    friend istream& operator>> (istream& in, GenericArray<T>& other)
    {
        in >> other.size;
        other.array = new T[other.size];

        for (int i = 0; i < other.size; i++)
        {
            in >> other.array[i];
        }

        return in;
    }

    bool operator== (const GenericArray& other) const
    {
        int i;
        if (this -> size == other.size)
        {
            for (i = 0; i < this -> size; i++)
            {
                if (this -> array[i] != other.array[i])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    // Overloaded index [] operator for constant objects to handle rvalue
    T operator[] (const int& index) const 
    {
        if (index >= 0 && index < this -> size) 
        {
            return array[index];    // Returning the value at the specified index
        }
        
        throw out_of_range{ "Error: Array Index Out of Bounds." };
    }

    // Overloaded index [] operator for non-constant objects to handle lvalue and rvalue
    T& operator[] (const int& index) 
    {
        if (index >= 0 && index < size) 
        {
            return array[index];    // Returning a reference to the value at the specified index
        }

        throw out_of_range{ "Error: Array Index Out of Bounds" };
    }
};

int main()
{
    GenericArray<int> obj1, obj2;
    GenericArray<char> obj3;

    try
    {
        obj3.setElement(3, 'a');
        obj3.setElement(4, 'b');
        obj3.setElement(2, 'e');
        obj3.setElement(1, 'd');
        obj3.setElement(0, 'c');
        obj3.printArray();
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    }

    int count = obj3.countElement('a');
    cout << count << endl;

    char *array;
    try
    {
        int startIndex = 0;
        int endIndex = 3;
        array = obj3.getSubArray(startIndex, endIndex);
        // for (int i = 0; i < (endIndex - startIndex) + 1; i++)
        // {
        //     cout << array[i] << "\t";
        // }
        // cout << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }

    // GenericArray<int> obj3 = obj1 + obj2;

    // obj3.printArray();

    // cin >> obj1;
    // cout << obj1;

    // if (obj1 == obj2)
    // {
    //     cout << "True" << endl;
    // }
    // else
    // {
    //     cout << "False" << endl;
    // }

    try
    {
        cin >> obj3[3];
        cout << obj3[3];
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    

    delete[] array;
    return 0;
}