#include "iostream"
using namespace std;

int printMenu()
{
    int choice, flag = 0;

    do
    {
        if (flag == 1)
        {
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
            cout << endl;
        }

        cout << "---- Calculator Menu ----" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Get Remainder" << endl;
        cout << "6. Exit" << endl;

        cout << "-------------------------" << endl;

        cout << "Enter your choice(1-6): ";
        cin >> choice;

        cout << endl;

        flag = 1;

    } while (choice > 6 || choice < 1);

    return choice;
}

int performOperation(int choice)
{
    int operand1, operand2, flag = 0;

    switch (choice)
    {
    case 1:
        cout << "Enter the first number: ";
        cin >> operand1;
        cout << "Enter the second number: ";
        cin >> operand2;

        cout << endl;

        cout << operand1 << " + " << operand2 << " = " << operand1 + operand2 << endl;
        
        cout << endl;

        break;
    case 2:
        cout << "Enter the first number: ";
        cin >> operand1;
        cout << "Enter the second number: ";
        cin >> operand2;

        cout << endl;

        cout << operand1 << " - " << operand2 << " = " << operand1 - operand2 << endl;
        
        cout << endl;

        break;
    case 3:

        cout << "Enter the first number: ";
        cin >> operand1;
        cout << "Enter the second number: ";
        cin >> operand2;

        cout << endl;

        cout << operand1 << " x " << operand2 << " = " << operand1 * operand2 << endl;
        
        cout << endl;

        break;
    case 4:

        cout << "Enter the first number: ";
        cin >> operand1;

        do
        {
            if (flag == 1)
            {
                cout << "Cannot divide by zero. Please enter a non-zero second number." << endl;
                cout << endl;
            }

            cout << "Enter the second number: ";
            cin >> operand2;

            cout << endl;

            flag = 1;

        } while (operand2 == 0);

        cout << operand1 << " / " << operand2 << " = " << (float)operand1 / operand2 << endl;
        
        cout << endl;

        break;
    case 5:

        cout << "Enter the first number: ";
        cin >> operand1;

        do
        {
            if (flag == 1)
            {
                cout << "Cannot divide by zero. Please enter a non-zero second number." << endl;
                cout << endl;
            }

            cout << "Enter the second number: ";
            cin >> operand2;

            cout << endl;

            flag = 1;

        } while (operand2 == 0);

        cout << operand1 << " mod " << operand2 << " = " << operand1 % operand2 << endl;
        
        cout << endl;

        break;
    case 6:

        cout << "Exiting the program. Good Bye!";
        return 1;

    }
    return 0;
}

int main()
{
    int choice, result = 0;

    while (result != 1)
    {
        choice = printMenu();

        result = performOperation(choice);
    }
    return 0;
}