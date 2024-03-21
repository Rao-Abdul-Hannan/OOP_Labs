#include "iostream"
#include "fstream"

using namespace std;

void printOriginalData (int arr[], int size)
{
    int i;

    cout << "The original data is:" << endl << endl;

    for (i = 0; i < size; i++)
    {
        if (i != 0 && (i % 10 == 0))
        {
            cout << endl;
        }
        cout << arr[i] << " ";
    }
    
    cout << endl << endl;
}

void getMinimumNumber (int arr[], int size)
{
    int i, min = arr[0];

    for (i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    cout << "Minimum number: " << min << endl << endl;
}

void getMaximumNumber (int arr[], int size)
{
    int i, max = 0;

    for (i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    cout << "Maximum number: " << max << endl;
}

void getSumOfData (int arr[], int size)
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    cout << "Sum: " << sum << endl;
}

void getAverageOfData (int arr[], int size)
{
    int i, sum = 0;
    float average;

    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    cout << "Average: " << (float)sum / size << endl;
}

void countOddEvenNumbers (int arr[], int size)
{
    int i, countEven = 0;

    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            countEven++;
        }
    }

    cout << "Count of Even numbers: " << countEven << endl;
    cout << "Count of Odd numbers: " << abs (100 - countEven) << endl;
}

void printMenu(int arr[], int size)
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
            printOriginalData(arr, size);
            break;

        case 1:
            getMinimumNumber(arr, size);
            break;

        case 2:
            getMaximumNumber(arr, size);
            break;

        case 3:
            getSumOfData(arr, size);
            break;

        case 4:
            getAverageOfData(arr, size);
            break;
        case 5:
            countOddEvenNumbers(arr, size);
            break;
        }
    }

    cout << "Exiting the program. Goodbye!" << endl;
}

int main()
{
    string filename = "input.txt";
    int arr[100], i = 0;

    ifstream readFile(filename);

    if (readFile.is_open())
    {
        while (readFile >> arr[i])
        {
            i++;
        }
        printMenu(arr, 100);
        readFile.close();
    }
    else
    {
        cerr << "Error reading file " << filename << endl;
        exit(0);
    }

    return 0;
}