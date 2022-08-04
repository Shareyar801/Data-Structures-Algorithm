//01.website for details: https://www.programiz.com/dsa/counting-sort
//02.youtube video: https://www.youtube.com/watch?v=7zuGmKfUt7s

#include <iostream>
using namespace std;

void CountSort(int arr[], int size)
{
    int output[10];         //for putting values during sorting.
    int count[10] = { 0 };  //making count array & inilizing from 0.
    int k = arr[0];         //letting  first element equal to k.

    for (int i = 1; i < size; i++)
    {   //finding max number to identify that how many element in count array.
        k = max(k, arr[i]); 
    }

    for (int i = 0; i < size; i++)
    {   //storing count of every element from our original array.
        count[arr[i]]++;    
    }

    for (int i = 1; i <= k; i++)
    {   //adding value at position i-1 into position i.
        count[i] += count[i - 1];
    }

    output[size]; //setting range of output array to size of given array.

    for (int i = size - 1; i >= 0; i--)
    {   //places value at its correct position and decrease count by one.
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];   //The output will be returned to the original array.
    }
}

void main()
{
    int arr[10] = { 1,9,2,5,7,0,6,4,3,8};
    int sz = 10;

    cout << "======COUNT SORT:";
    cout << "\nPrinting array in its orginal condition: ";
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }

    CountSort(arr, sz);

    cout << "\n\nPrinting array after sorting: ";
    for (size_t i = 0; i < sz; i++)
    {
        cout << arr[i] << "  ";
    }

    cout << "\n\n";
}
