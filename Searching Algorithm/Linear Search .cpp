#include <iostream> 
#include <string>
using namespace std;

void main()
{
	int array1[20]; int key_val; bool check = 1;

	cout << "Enter 20 elements of array: \n";
	for (size_t i = 0; i < 20; i++)
	{
		cout << "INDEX " << i << ": ";
		cin >> array1[i];
	}

	cout << "Enter a key value to find from array: ";
	cin >> key_val;
	for (size_t i = 0; i < 20; i++)
	{
		if (key_val == array1[i])
		{
			cout << "Key value found! at index " << i << endl;
			check = 0;
			break;
		}
		check = 1;
	}

	if (check == 1)
	{
		cout << "key value not found.\n";
	}
}
