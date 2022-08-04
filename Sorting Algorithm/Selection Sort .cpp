#include <iostream>
using namespace std;

int main()
{
	int size = 10, arr[10] = { 52, 69, 10, 88, 47, 15, 9, 4, 3, 2 }, temp, selected_val_idx;

	cout << "==>SELECTION SORTING:- \n";
	cout << "\nElements of array: ";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}

	//selection sort:
	for (size_t i = 0; i < size - 1; i++)
	{
		selected_val_idx = i;
		for (size_t j = i + 1; j < size; j++)
		{// for comparision of selected value with elements of array
			if (arr[j] < arr[selected_val_idx])
			{
				selected_val_idx = j;
			}
		}
		//swaping elemets
		temp = arr[selected_val_idx];
		arr[selected_val_idx] = arr[i];
		arr[i] = temp;
	}

	cout << "\nPrinting Array: ";
	for (size_t sf = 0; sf < size; sf++)
	{
		cout << arr[sf] << "  ";
	}
}

