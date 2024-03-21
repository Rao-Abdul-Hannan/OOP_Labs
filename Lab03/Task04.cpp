#include <iostream>
using namespace std;

void getPosNeg (const int arr[], const int size, int* &pos, int &n_pos, int* &neg, int &n_neg)
{
    int j = 0, k = 0;

    // Counting positive and negative numbers
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
            n_neg++;
        else if (arr[i] > 0)
            n_pos++;
    }
    
    // Allocating memory in heap
    pos = new int[n_pos];
    neg = new int[n_neg];

    // Populating positive and negative arrays
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
            neg[j++] = arr[i];
        else if (arr[i] > 0)
            pos[k++] = arr[i];
    }
}

int main()
{
    int arr[10], positiveCount = 0, negativeCount = 0;
    int *positive = nullptr, *negative = nullptr;

    // Initializing Array
    cout << "Enter Array: ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    // Calling the function to separate positive and negative arrays
    getPosNeg (arr, 10, positive, positiveCount, negative, negativeCount);

    //Checking if positive and negative arrays exist and then print it
    if (positiveCount == 0 && negativeCount == 0)
    {
        cout << "No positive or negative values found." << endl;
    }
    else
    {
        cout << "Positive Values: ";
        for (int i = 0; i < positiveCount; i++)
        {
            cout << positive[i] << " ";
        }
        cout << endl;

        cout << "Negative Values: ";
        for (int i = 0; i < negativeCount; i++)
        {
            cout << negative[i] << " ";
        }
        cout << endl;
    }

    // deleting the allocated arrays
    delete [] positive;
    delete [] negative;
    return 0;
}