#include <iostream>
using namespace std;

void arrayInIt (float *array, int size)
{
    cout << "Enter array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> *(array + i);
    }
}

float calculateAverage (float *array, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(array + i);
    }
    return sum / size;
}

int main()
{
    int sizeOfArray = 0;
    float average;

    cout << "Enter size of array: ";
    cin >> sizeOfArray;

    float *array = new float[sizeOfArray];

    arrayInIt (array, sizeOfArray);
    average = calculateAverage (array, sizeOfArray);

    cout << "Average: " << average << endl;

    delete [] array;
    return 0;
}