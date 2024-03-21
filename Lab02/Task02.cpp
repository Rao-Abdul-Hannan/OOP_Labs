#include "iostream"
#include "fstream"
using namespace std;

void printOriginalData (int *ptrArray, int size)
{
    int i;

    cout << "The original data is:" << endl << endl;

    for (i = 0; i < size; i++)
    {
        if (i != 0 && (i % 10 == 0))
        {
            cout << endl;
        }
        cout << *(ptrArray + i) << " ";
    }
    
    cout << endl << endl;
}

void getMinimumNumber (int *ptrArray, int size)
{
    int i, min = *(ptrArray);

    for (i = 1; i < size; i++)
    {
        if (*(ptrArray + i) < min)
        {
            min = *(ptrArray + i);
        }
    }

    cout << "Minimum number: " << min << endl << endl;
}

void getMaximumNumber (int *ptrArray, int size)
{
    int i, max = 0;

    for (i = 0; i < size; i++)
    {
        if (*(ptrArray + i) > max)
        {
            max = *(ptrArray + i);
        }
    }

    cout << "Maximum number: " << max << endl << endl;
}

void getSumOfData (int *ptrArray, int size)
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += *(ptrArray + i);
    }

    cout << "Sum: " << sum << endl << endl;
}

void getAverageOfData (int *ptrArray, int size)
{
    int i, sum = 0;
    float average;

    for (i = 0; i < size; i++)
    {
        sum += *(ptrArray + i);
    }

    cout << "Average: " << (float)sum / size << endl << endl;
}

void countOddEvenNumbers (int *ptrArray, int size)
{
    int i, countEven = 0;

    for (i = 0; i < size; i++)
    {
        if (*(ptrArray + i) % 2 == 0)
        {
            countEven++;
        }
    }

    cout << "Count of Even numbers: " << countEven << endl;
    cout << "Count of Odd numbers: " << abs (100 - countEven) << endl << endl;
}

void printMenu(int *ptrArray, int size)
{
    int choice = 10;

    cout << "==> Data reading from input.txt completed <==" << endl << endl;

    while (choice != 6)
    {
        cout << "---- Data Operations menu ----" << endl;
        cout << "0. Display Original Data" << endl;
        cout << "1. Get Minimum Number" << endl;
        cout << "2. Get Maximum Number" << endl;
        cout << "3. Get Sum of data" << endl;
        cout << "4. Get Average of Data" << endl;
        cout << "5. Count Odd/Even Numbers" << endl;
        cout << "6. Exit" << endl;
        cout << "-----------------------------" << endl << endl;

        cout << "Enter your choice(0-6): ";
        cin >> choice;

        cout << endl;

        while (choice < 0 || choice > 6)
        {
            cout << "Invalid choice. Please enter a number between 0 and 6." << endl << endl;

            cout << "---- Data Operations menu ----" << endl;
            cout << "0. Display Original Data" << endl;
            cout << "1. Get Minimum Number" << endl;
            cout << "2. Get Maximum Number" << endl;
            cout << "3. Get Sum of data" << endl;
            cout << "4. Get Average of Data" << endl;
            cout << "5. Count Odd/Even Numbers" << endl;
            cout << "6. Exit" << endl;
            cout << "-----------------------------" << endl;

            cout << "Enter your choice(0-6): ";
            cin >> choice;

            cout << endl;
        }

        switch (choice)
        {
        case 0:
            printOriginalData(ptrArray, size);
            break;

        case 1:
            getMinimumNumber(ptrArray, size);
            break;

        case 2:
            getMaximumNumber(ptrArray, size);
            break;

        case 3:
            getSumOfData(ptrArray, size);
            break;

        case 4:
            getAverageOfData(ptrArray, size);
            break;
        case 5:
            countOddEvenNumbers(ptrArray, size);
            break;
        }
    }

    cout << "Exiting the program. Goodbye!" << endl;
}

int main ()
{
    string filename = "input.txt";
    int size = 0, a, i = 0;

    ifstream fileData (filename);

    if (fileData.is_open())
    {
        while (fileData >> a)
        {
            size++;
        }
        fileData.close();
    }
    else
    {
        cerr << "Can't open file " << filename << endl;
        exit (0);
    }

    int *ptrArray = new int[size];

    fileData.open (filename);

    for (int i = 0; i < size; i++)
    {
        fileData >> *(ptrArray + i);
    }

    printMenu (ptrArray, size);

    delete [] ptrArray;
    fileData.close();
    return 0;
}