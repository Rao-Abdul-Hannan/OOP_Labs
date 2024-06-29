#include <iostream>
#include <vector>
using namespace std;

class Employee
{
    private:
        string firstName, lastName, ssn;

    public:
        Employee() : firstName(""), lastName(""), ssn("")
        {
            cout << "Employee's default constructor" << endl;
        }
        Employee(string _firstName, string _lastName, string _ssn) : firstName(_firstName), lastName(_lastName), ssn(_ssn) 
        {
            cout << "Employee's parameterized constructor" << endl;
        }
        virtual ~Employee()
        {
            cout << "Employee's destructor" << endl;
        }

        string getFirstName() const
        {
            return firstName;
        }
        string getLastName() const
        {
            return lastName;
        }
        string getSSN() const
        {
            return ssn;
        }
        void setFirstName(string _firstName)
        {
            this -> firstName = _firstName;
        }
        void setLastName(string _lastName)
        {
            this -> lastName = _lastName;
        }
        void setSSN(string _ssn)
        {
            this -> ssn = _ssn;
        }

        virtual void printData () const
        {
            cout << "First Name: " << firstName << endl;
            cout << "Last Name: " << lastName << endl;
            cout << "SSN: " << ssn << endl;
        }

        virtual double earnings () const = 0;
};

class SalariedEmployee : public Employee
{
    private:
        double weeklySalary;
    public:
        SalariedEmployee() : Employee(), weeklySalary(0)
        {
            cout << "SalariedEmployee's default constructor" << endl;
        }

        SalariedEmployee(string _firstName, string _lastName, string _ssn, double _weeklySalary) : Employee(_firstName, _lastName, _ssn), weeklySalary(_weeklySalary)
        {
            cout << "SalariedEmployee's parameterized constructor" << endl;
        }

        ~SalariedEmployee() override
        {
            cout << "SalariedEmployee's destructor" << endl;
        }

        void setWeeklySalary (double _weeklySalary) 
        {
            this -> weeklySalary = _weeklySalary;
        }

        double getWeeklySalary () const
        {
            return this -> weeklySalary;
        }

        void setFirstName (string _firstName)
        {
            Employee::setFirstName(_firstName);
        }

        void setLastName(string _lastName)
        {
            Employee::setLastName(_lastName);
        }

        void setSSN(string _ssn)
        {
            Employee::setSSN(_ssn);
        }

        string getFirstName() const
        {
            return Employee::getFirstName();
        }

        string getLastName() const
        {
            return Employee::getLastName();
        }

        string getSSN() const
        {
            return Employee::getSSN();
        }

        void printData () const override
        {
            Employee::printData();
            cout << "Weekly Salary: " << weeklySalary << endl;
        }

        double earnings () const override
        {
            return weeklySalary;
        }
};

class HourlyEmployee : public Employee
{
    private: 
        double wage, hours;
    public:
        HourlyEmployee() : Employee(), wage(0), hours(0) 
        {
            cout << "Hourly Employee's default constructor" << endl;
        }

        HourlyEmployee(string _firstName, string _lastName, string _ssn, double _wage, double _hours) : Employee(_firstName, _lastName, _ssn), wage(_wage), hours(_hours)
        {
            cout << "Hourly Employee's parameterized constructor" << endl;
        }

        ~HourlyEmployee() override
        {
            cout << "Hourly Employee's destructor" << endl;
        }

        void setWage(double _wage)
        {
            this -> wage = _wage;
        }

        void setHours(double _hours)
        {
            this -> hours = hours;
        }

        double getWage() const
        {
            return this -> wage;
        }

        double getHours() const
        {
            return this -> hours;
        }

        void setFirstName (string _firstName)
        {
            Employee::setFirstName(_firstName);
        }

        void setLastName(string _lastName)
        {
            Employee::setLastName(_lastName);
        }

        void setSSN(string _ssn)
        {
            Employee::setSSN(_ssn);
        }

        string getFirstName() const
        {
            return Employee::getFirstName();
        }

        string getLastName() const
        {
            return Employee::getLastName();
        }

        string getSSN() const
        {
            return Employee::getSSN();
        }

        void printData() const override
        {
            Employee::printData();
            cout << "Wage: " << this -> wage << endl;
            cout << "Hours: " << this -> hours << endl;
        }

        double earnings() const override
        {
            return hours * wage;
        }
};

class ComissionEmployee : public Employee
{
    private:
        double grossSales, comissionRate;
    public:
        ComissionEmployee() : Employee(), grossSales(0), comissionRate(0)
        {
            cout << "Comission Employee's default constructor" << endl;
        }
        
        ComissionEmployee(string _firstName, string _lastName, string _ssn, double _grossSales, double _comissionRate) : Employee(_firstName, _lastName, _ssn), grossSales(_grossSales), comissionRate(_comissionRate)
        {
            cout << "Comission Employee's parameterized constructor" << endl;
        }

        ~ComissionEmployee() override
        {
            cout << "Comission Employee's destructor" << endl;
        }

        void setGrossSales(double _grossSales)
        {
            this -> grossSales = _grossSales;
        }

        void setComissionRate(double _comissionRate)
        {
            this -> comissionRate = _comissionRate;
        }

        double getGrossSales() const
        {
            return grossSales;
        }

        double getComissionRate() const
        {
            return comissionRate;
        }

        void setFirstName(string _firstName)
        {
            Employee::setFirstName(_firstName);
        }

        void setLastName(string _lastName)
        {
            Employee::setLastName(_lastName);
        }

        void setSSN(string _ssn)
        {
            Employee::setSSN(_ssn);
        }

        string getFirstName() const
        {
            return Employee::getFirstName();
        }

        string getLastName() const
        {
            return Employee::getLastName();
        }

        string getSSN() const
        {
            return Employee::getSSN();
        }

        void printData() const override
        {
            Employee::printData();
            cout << "Gross Sales: " << grossSales << endl;
            cout << "Comission Rate: " << comissionRate << endl;
        }

        double earnings() const override
        {
            return grossSales * comissionRate;
        }
};

class BasePlusCommissionEmployee : public ComissionEmployee
{
    private:
        double baseSalary;
    public:
        BasePlusCommissionEmployee() : ComissionEmployee(), baseSalary(0)
        {
            cout << "Base Plus Comission Employee's default constructor" << endl;
        }

        BasePlusCommissionEmployee(string _firstName, string _lastName, string _ssn, double _grossSales, double _comissionRate, double _baseSalary) : ComissionEmployee(_firstName, _lastName, _ssn, _grossSales, _comissionRate), baseSalary(_baseSalary)
        {
            cout << "Base Plus Comission Employee's parameterized constructor" << endl;
        }

        ~BasePlusCommissionEmployee() override
        {
            cout << "Base Plus Comission Employee's destructor" << endl;
        }

        void setBaseSalary(double _baseSalary) 
        {
            this -> baseSalary = _baseSalary;
        }

        double getBaseSalary() const
        {
            return baseSalary;
        }

        void setGrossSales(double _grossSales)
        {
            ComissionEmployee::setGrossSales(_grossSales);
        }

        void setComissionRate(double _comissionRate)
        {
            ComissionEmployee::setComissionRate(_comissionRate);
        }

        double getGrossSales() const
        {
            return ComissionEmployee::getGrossSales();
        }

        double getComissionRate() const
        {
            return ComissionEmployee::getComissionRate();
        }

        void setFirstName(string _firstName)
        {
            Employee::setFirstName(_firstName);
        }

        void setLastName(string _lastName)
        {
            Employee::setLastName(_lastName);
        }

        void setSSN(string _ssn)
        {
            Employee::setSSN(_ssn);
        }

        string getFirstName() const
        {
            return Employee::getFirstName();
        }

        string getLastName() const
        {
            return Employee::getLastName();
        }

        string getSSN() const
        {
            return Employee::getSSN();
        }

        void printData() const override
        {
            Employee::printData();
            ComissionEmployee::printData();
            cout << "Base Salary: " << baseSalary << endl;
        }

        double earnings() const override
        {
            return ComissionEmployee::earnings() + baseSalary;
        }
};

int main()
{
    // Employee obj1; object of abstract class type employee is not allowed
    
    SalariedEmployee employee1("Abdul", " Hannan", "33202-0713392-7", 100);
    // employee1.printData();

    HourlyEmployee employee2("Faizan", "Ahmad", "33202-9879927-5", 20, 5);
    // employee2.printData();

    ComissionEmployee employee3("Nauman", "Ahmad", "33202-3549293-0", 10, 24);
    // employee3.printData();

    BasePlusCommissionEmployee employee4("Ammar", "Arif", "33202-4320459-1", 14, 20, 100);
    // employee4.printData();

    // vector<Employee*> employees;
    // employees.push_back(&employee1);
    // employees.push_back(&employee2);
    // employees.push_back(&employee3);
    // employees.push_back(&employee4);

    // for(auto& employee : employees)
    // {
    //     employee -> printData();
    // }

    // Employee* employee = &employee4;
    // employee -> printData();
    // employee -> printData(); if printData() function virtual nhi ha tw ye statement parent ka data dikhayega bs

    return 0;
}