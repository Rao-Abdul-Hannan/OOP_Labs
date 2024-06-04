#include <iostream>
#include <string>

using namespace std;

class Faculty 
{
    private:

    int id;  // 1001 to 1065, 0 otherwise
    string firstName, lastName, qualification;
    float salary; // 20,000 to 100,000, -1 otherwise

    public:

    Faculty () : id (0), firstName(""), lastName(""), qualification(""), salary(0.0)
    {
        cout << "Default constructor" << endl;
    }

    Faculty (int id, string firstName, string lastName, string qualification, float salary = -1) : id(id), firstName(firstName), lastName(lastName), qualification(qualification), salary(salary)
    {
        cout << "Parameterized constructor" << endl;

        if (salary >= 20000 && salary <= 65000)
        {
            this -> salary = salary;
        }
        else
        {
            this -> salary = -1;
        }
        if (id >= 1001 && id <= 1065)
        {
            this -> id = id;
        }
        else
        {
            this -> id = 0;
        }
    }

    Faculty (int id, string firstName, string qualification) : id(id), firstName(firstName), qualification(qualification), lastName(""), salary(-1)
    {
        cout << "Parameterized constructor" << endl;
        if (salary >= 20000 && salary <= 65000)
        {
            this -> salary = salary;
        }
        else
        {
            this -> salary = -1;
        }
        if (id >= 1001 && id <= 1065)
        {
            this -> id = id;
        }
        else
        {
            this -> id = 0;
        }
    }

    Faculty (const Faculty& obj) : id(obj.id), firstName(obj.firstName), lastName(obj.lastName), qualification(obj.qualification), salary(obj.salary)
    {
        cout << "Copy constructor" << endl;
    }

    ~Faculty ()
    {
        cout << "Destructor" << endl;
    }

    // Mutators
    void setId (const int& id)
    {
        if (id >= 1001 && id <= 1065)
        {
            this -> id = id;
        }
        else
        {
            this -> id = 0;
        }
    }

    void setFirstName (const string& firstName)
    {
        this -> firstName = firstName;
    }

    void setLastName (const string& lastName)
    {
        this -> lastName = lastName;
    }

    void setQualification (const string& qualification)
    {
        this -> qualification = qualification;
    }

    void setSalary (const float& salary)
    {
        if (salary >= 20000 && salary <= 65000)
        {
            this -> salary = salary;
        }
        else
        {
            this -> salary = -1;
        }
    }

    // Accessors

    int getId () const
    {
        return this -> id;
    }

    string getFirstName () const
    {
        return this -> firstName;
    }

    string getLastName () const
    {
        return this -> lastName;
    }

    string getQualification () const
    {
        return this -> qualification;
    }

    float getSalary () const
    {
        return this -> salary;
    }

    // set method to accept faculty data from arguments
    void setFaculty (const int& id, const string& firstName, const string& lastName, const string& qualification, const float& salary)
    {
        setId (id);
        setFirstName (firstName);
        setLastName (lastName);
        setQualification (qualification);
        setSalary (salary);
    }

    // set data members from the data got through console
    void getFaculty () 
    {
        cout << "Enter identification number: ";
        cin >> this -> id;
        setId (this -> id);

        cin.ignore();

        cout << "Enter first name: ";
        cin >> this -> firstName;
        setFirstName (this -> firstName);

        cout << "Enter last name: ";
        cin >> this -> lastName;
        setLastName (this -> lastName);

        cout << "Enter qualification: ";
        cin >> this -> qualification;
        setQualification (this -> qualification);

        cout << "Enter salary: ";
        cin >> this -> salary;
        setSalary (this -> salary);
    }

    void putFaculty () const
    {
        cout << this -> id << "\t";
        cout << this -> firstName << "\t";
        cout << this -> lastName << "\t";
        cout << this -> qualification << "\t\t";
        cout << this -> salary << "\t";

        cout << endl;
    }

    bool isPostGraduate () const
    {
        if ((this -> qualification.compare ("MS") == 0) || (this -> qualification.compare ("PhD") == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    float getTakeHomeSalary () const
    {
        if ((this -> salary) - ((salary * 7) / 100) < 20,000)
        {
            return -1;
        }
        return (this -> salary) - ((salary * 7) / 100);
    }

    bool isJoined () const
    {
        if ((this -> salary) - ((salary * 7) / 100) < 20,000)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

};

int main()
{
    int facultyMembers = 0;

    cout << "Enter members of faculty: ";
    cin >> facultyMembers;

    Faculty *faculty = new Faculty[facultyMembers];

    for (int i = 0; i < facultyMembers; i++)
    {
        cout << "Enter Data of member " << i << endl;
        faculty[i].getFaculty();
    }

    cout << "Id\tFirst Name\tLast Name\tQualification\tSalary" << endl;

    for (int i = 0; i < facultyMembers; i++)
    {
        faculty[i].putFaculty();
    }

    cout << faculty[1].isPostGraduate();
    cout << faculty[0].isPostGraduate();

    delete [] faculty;
    return 0;
}