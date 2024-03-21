#include <iostream>
using namespace std;

int *getEvenNumbers (const int arr[], int size, int &evenSize)
{
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
            evenSize++;
    }

    if (evenSize == 0)
    {
        return nullptr;
    }
    else
    {
        int *evenArray = new int[evenSize];

        for (int i = 0; i < size; i++)
        {
            if (arr[i] % 2 == 0)
                evenArray[j++] = arr[i];
        }
            return evenArray;
    }

}

int main()
{
    int arr[10], evenArraySize = 0;

    // Initializing Array
    cout << "Enter array: ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    // Calling the function to separate even number arrays
    int *evenArray = getEvenNumbers (arr, 10, evenArraySize);

    // Checking if even number arrays exist
    if (evenArraySize == 0)
    {
        cout << "No even numbers exist in the array." << endl;
    }
    else 
    {
        cout << "Even Numbers Array: ";
        for (int i = 0; i < evenArraySize; i++)
        {
            cout << evenArray[i] << " ";
        }
        cout << endl;
    }

    // Deleti
    delete [] evenArray;

    return 0;
}