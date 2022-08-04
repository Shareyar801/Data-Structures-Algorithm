#include <iostream>
using namespace std;

int main()
{
	int sz = 5, temp, key; int arr[20]; //sz = size.
	
	//temp will hold value for a while when sorting will be taking place.
	cout << "```INSERTION SORTING ALGORITHM:```\n";
	cout << "Enter Elemets of array: \n";
	for (size_t sf = 0; sf < sz; sf++)
	{
		cout << sf << ".";
		cin >> arr[sf];
	} cout << endl;

	//sorting block
	for (size_t s = 1; s < sz; s++)
	{
		temp = arr[s];
		int f = s - 1;
		while (f >= 0 && temp <= arr[f])
		{
			arr[f + 1] = arr[f];
			f = f - 1;
		}
		arr[f + 1] = temp;
	}

	cout << "Now displaying sorted array:\t";
	for (size_t sf = 0; sf < sz; sf++)
	{
		cout << arr[sf] << "\t";
	} cout << endl;
}


