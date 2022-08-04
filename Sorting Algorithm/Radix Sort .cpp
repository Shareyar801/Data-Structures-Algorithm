//01.website for code explaination : https://www.geeksforgeeks.org/radix-sort/ and https://www.programiz.com/dsa/radix-sort
//02.youtube video only for logic : https ://www.youtube.com/watch?v=nu4gDuFabIM

#include <iostream>
using namespace std;

int getmax(int arr[], int s)
{
    int mx = arr[0];

    for (int i = 1; i < s; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    return mx;
}

void countSort(int arr[], int size, int exp)
{
    int output[10];         //for putting values during sorting.
    int count[10] = { 0 };  //making count array & inilizing from 0.

    for (int i = 0; i < size; i++)
    {   //storing count of every element from our original array.
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < size; i++)
    {   //adding value at position i-1 into position i.
        count[i] += count[i - 1];
    }

    output[size]; //setting range of output array to size of given array.

    for (int i = size - 1; i >= 0; i--)
    {   //places value at its correct position and decrease count by one.
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];   //The output will be returned to the original array.
    }
}

void Radixsort(int arr[], int s)
{
    int max = getmax(arr, s);

    for (size_t exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, s, exp);
    }
}

void main()
{
    int arr[10] = { 80,900,20,508,14,0,192,4,30,48 };
    int sz = 10;

    cout << "======COUNT SORT:";
    cout << "\nPrinting array in its orginal condition: ";
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }

    Radixsort(arr, sz);

    cout << "\n\nPrinting array after sorting: ";
    for (size_t i = 0; i < sz; i++)
    {
        cout << arr[i] << "  ";
    }

    cout << "\n\n";
}
