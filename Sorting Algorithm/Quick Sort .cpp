//01.website for explainationand details: https://www.programiz.com/dsa/quick-sort
//02.youtube video only for logic : https ://www.youtube.com/watch?v=UA_Rmjfj4bw&t=726s

#include <iostream>
using namespace std;

int Partition(int arr[], int l, int r)
{
    int pivot = arr[r]; //setting pivot, pivot according to which sawpping will take place.
    int i = l - 1;  //setting i iteration equal to most left element of array. its also pointer for greater element.
    int temp;   //for holding value temparorly while swapping.

    for (size_t j = l; j < r; j++) //loop will run till i is smaller than j.
    {
        if (arr[j] <= pivot)
        {
            //if element smaller than pivot is found. it swap with the greater element pointed by i.
            i++;
            //simple swaping technique.
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    //simple swaping technique. and it will swap pivot to its rightful place (which is i+1).
    temp = arr[r];
    arr[r] = arr[i + 1];
    arr[i + 1] = temp;

    return (i + 1);

}

void Quicksort(int arr[], int l, int r)
{
    if (l < r)  //will run untill left is smaller than right.
    {
        int pivot = Partition(arr, l, r);  //saving return value of partition function into pivot variable.
        Quicksort(arr, l, pivot - 1);      //will sort left side of array by calling this function recursively.
        Quicksort(arr, pivot + 1, r);      //will sort right side of array by calling this function recursively.
    }

}

int main()
{
    int a[15] = { 99,88,77,66,55,44,33,22,11,10,9,8,7,6, 5 };
    int left = 0, right = 14;

    cout << "======QUICK SORT:";
    cout << "\nPrinting array in its orginal condition: ";
    for (size_t i = 0; i < 15; i++)
    {
        cout << a[i] << "  ";
    }

    Quicksort(a, left, right);

    cout << "\n\nPrinting array after sorting: ";
    for (size_t i = 0; i < 15; i++)
    {
        cout << a[i] << "  ";
    }

    cout << "\n\n";
}

