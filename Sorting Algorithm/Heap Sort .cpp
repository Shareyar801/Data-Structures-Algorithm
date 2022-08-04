#include  <iostream>
using namespace std;

void heapify(int a[], int n, int i)
{
    //2*i+1 formula for left child, 2*i+2 formula for right child.
    // Find largest among root, left child and right child.
    int largest = i; //letting i as largest for now.
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest.
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void build_heap(int a[], int n)
{
    for (int sf = n / 2 - 1; sf >= 0; sf--)
        heapify(a, n, sf);
    //sorting array in order of heap.
    //n/2-1 is formula for last non-leave branch of heap.
}

void sort_heap(int a[], int n)
{
    build_heap(a, n);
    for (int sf = n - 1; sf > 0; sf--)
    {
        swap(a[0], a[sf]); //calling heapify to the reduced heap and convert it into sorted array.
        heapify(a, sf, 0);
    }
}

int main()
{
    int arr[10] = { 12, 34, 54, 69, 3, 15, 99, 58, 1,49 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "======HEAP SORT:";
    cout << "\nPrinting array in its orginal condition: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    sort_heap(arr, n);
    
    cout << "\n\nPrinting array after sorting: ";
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n";
    return 0;
}
