#include <iostream>
using namespace std;

void merge(int arr[], int left, int middle, int right)
{
	int s = left, f = middle + 1, sf = left, temp_arr[20];

	//s will start from first index and stop at middle-1.
	//f will start from middle+1 index and stop at last index.
	while (s <= middle && f <= right)
	{
		if (arr[s] <= arr[f]) //if s element of sub array < f element of sub array
		{
			//the s element will be save in temparory array.
			temp_arr[sf] = arr[s];
			s++;
		}
		else	//if s element of sub array > f element of sub array
		{
			//the f element will be save in temparory array.
			temp_arr[sf] = arr[f];
			f++;

		} sf++;
	}
	if (s > middle)
	{ //there is possibility that all elements of right side aren't fully sorted and stored into temp array that's why we are putting another condition in effect to over this problem.
		while (f <= right)
		{
			temp_arr[sf] = arr[f];
			sf++; f++;
		}
	}
	else
	{ //there is possibility that all elements of left side aren't fully sorted and stored into temp array that's why we are putting another condition in effect to over this problem..
		while (s <= middle)
		{
			temp_arr[sf] = arr[s];
			sf++; s++;
		}
	}
	//now storing all elements of temp array into orginal array.
	for (size_t i = left; i <= right; i++)
	{
		arr[i] = temp_arr[i];
	}
}

void merge_sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;	//getting middle point of array.

		//merge_sort will run as recurise funcation till start of array is larger than its end.
		merge_sort(arr, left, mid);		//dividing or breaking array into sub arrays from left to middle.
		merge_sort(arr, mid + 1, right);	//dividing or breaking array into sub arrays from middle to right.

		//now sorting that sub arrays and merging them.
		merge(arr, left, mid, right);
	}
}

int main()
{
	int sz, arr[50], first_idx, last_idx;
	cout << "------MERGE SORTING:------\n";
	cout << "Enter size of array (recommended max 50):\n";
	cin >> sz; arr[sz];

	cout << "Enter 20 elements of array:\n";
	for (size_t sf = 0; sf < sz; sf++)
	{
		cin >> arr[sf];
	}

	first_idx = 0; last_idx = sz - 1;
	merge_sort(arr, first_idx, last_idx);

	cout << "Displaying all 20 elements of array: ";
	for (size_t sf = 0; sf < sz; sf++)
	{
		cout << arr[sf] << "  ";
	}
	cout << endl;
}
